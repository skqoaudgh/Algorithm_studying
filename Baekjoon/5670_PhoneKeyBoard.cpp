#include <cstdio>
#include <cstring>

int ans = 0;
char str[100000][80];
bool rootflag = false;

struct Trie {
	bool finish;
	int count;
	Trie* next[26];
	
	~Trie()
	{
		for(int i=0; i<26; i++)
			if(next[i])
				delete next[i];
	}
	Trie() : finish(false),count(0) {
		memset(next, 0, sizeof(next));
	}	
	
	void insert(Trie* root, const char *key)
	{
		if(*key == '\0')
			finish = true;
		else
		{
			int idx = *key - 'a';
			if(next[idx] == NULL)
			{
				count ++;
				next[idx] = new Trie();
			}
				
			next[idx]->insert(this,key+1);
		}
	}
	
	Trie* find(const char* key)
	{
		if(*key == '\0')
			return this;
		int idx = *key - 'a';
		if(next[idx] == NULL)
			return NULL;
		if(finish || count > 1 || rootflag)
			ans ++;
		rootflag = false;
		return next[idx]->find(key+1);
	}
};


int main()
{
	int N;
	while(scanf("%d",&N) != -1)
	{
		Trie* root = new Trie();
		ans = 0;
		for(int i=0; i<N; i++)
		{
			scanf("%s",&str[i]);
			root->insert(root,str[i]);
		}
		
		for(int i=0; i<N; i++)
		{
			rootflag = true;
			root->find(str[i]);
		}
			
		printf("%.2lf\n",(double)ans/N);
		delete root;
	}
	return 0;
}
