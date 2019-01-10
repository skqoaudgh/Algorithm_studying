#include <stdio.h>
#include <cstring>

struct Trie {
	bool finish;
	Trie* Next[26];
	
	~Trie()
	{
		for(int i=0; i<26; i++)
			delete Next[i];
	}
	
	Trie() : finish(false) {
		memset(Next, 0, sizeof(Next));
	}
	
	void insert(const char* key)
	{
		if(*key == '\0')
			finish = true;
		else
		{
			int curr = *key - 'A';
			if(Next[curr] == NULL)
				Next[curr] = new Trie();
			Next[curr]->insert(key+1);
		}
	}
	
	Trie* find(const char* key)
	{
		if(*key == '\0')
			return this;
		int curr = *key - 'A';
		if(Next[curr] == NULL)
			return NULL;
		return Next[curr]->find(key+1);
	}
};

int main()
{
	char string[5][5];
	for(int i=0; i<5; i++)
		scanf("%s",&string[i]);
	
	Trie* root = new Trie();
	for(int i=0; i<5; i++)
		root->insert(string[i]);
	
	for(int i=0; i<5; i++)
	{
		if(root->find(string[i]))
			printf("yes!!\n");
		else
			printf("no!!\n");
	}
	return 0;
}
