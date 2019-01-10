#include <cstdio>
#include <cstring>

struct Trie {
	bool finish;
	Trie* Next[26];
	
	Trie() : finish(false) 
	{
		memset(Next, 0, sizeof(Next));
	}
	
	void insert(const char* key)
	{
		if(*key == '\0')
			finish = true;
		else
		{
			int idx = *key - '0';
			if(Next[idx] == NULL)
				Next[idx] = new Trie();
			Next[idx]->insert(key+1);
		}
	}
	
	bool find(const char* key)
	{
		if(*key == '\0')
			return 0;
		int idx = *key - '0';
		if(Next[idx] == NULL)
			return NULL;
		if(finish)
			return 1;
		return Next[idx]->find(key+1);
	}
};

int main()
{
	int t;
	char phone[10000][10];
	scanf("%d",&t);
	for(int test_case=0; test_case<t; test_case++)
	{
		int n,r=0;
		Trie* root = new Trie();
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%s",&phone[i]);
			root->insert(phone[i]);
		}
			
		
		for(int i=0; i<n; i++)
			if(root->find(phone[i]) == 1)
			{
				r = 1;
				break;
			}
		if(r == 1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
