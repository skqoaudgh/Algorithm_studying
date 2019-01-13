#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

string insert_temp;
string dna;
// A,T,G,C
int AlphabetToInt(char ch)
{
	if(ch == 'A')
		return 0;
	else  if(ch == 'T')
		return 1;
	else if(ch == 'G')
		return 2;
	else
		return 3;								
}

string change(string a)
{
	string result;
	for(int i=a.size()-1;i>=0;i--)
		result+=a[i];
	return result;
}

struct TrieNode
{
	TrieNode* go[4];
	TrieNode* fail;
	bool terminal;

	TrieNode() : terminal(false)
	{
		fill(go,go+4,nullptr);
	}
	~TrieNode()
	{
		for(int i=0;i<4;i++)
			if(go[i])
				delete go[i];
	}
	void insert(const char* key)
	{
		if(*key == '\0')
			terminal = true;
		else
		{
			int next = AlphabetToInt(*key);
			if(!go[next])
				go[next] = new TrieNode();
			go[next]->insert(key+1);
		}		
	}
};

int main()
{
	int tcc;
	scanf("%d",&tcc);

	while(tcc--)
	{
		TrieNode *tr=new TrieNode();
		int n,m;		
		scanf("%d %d",&n,&m);
		
		char* a = new char[n+1];
		char* b = new char[m+1];		
		scanf("%s",a);
		scanf("%s",b);
		
		string mark(b);
		dna = a;
		tr->insert(mark.c_str());
		for(int i=0;i<m;i++)
			for(int j=i+1;j<m;j++)
				tr->insert((mark.substr(0,i)+change(mark.substr(i,j-i+1))+mark.substr(j+1,m-j-1)).c_str());

		queue<TrieNode*> q;
		tr->fail=tr;
		q.push(tr);

		while(!q.empty())
		{
			TrieNode* current = q.front();
			q.pop();
			for(int i=0;i<4;i++)
			{
				TrieNode* next = current->go[i];
				if(!next)	continue;

				if(current == tr)
					next->fail = tr;
				else
				{
					TrieNode* dest = current->fail;
					while(dest != tr && !dest->go[i])
						dest = dest->fail;

					if(dest->go[i])	
						dest = dest->go[i];
					next->fail = dest;
				}
				if(next->fail->terminal) next->terminal = true;
				q.push(next);
			}
		}
		
		int result = 0;
		TrieNode* current = tr;
		for(int i=0; i<dna.size(); i++)
		{
			int next = AlphabetToInt(dna[i]);
			while(current != tr && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(current->terminal)
				result ++;
		}
		printf("%d\n",result);
		delete[] a;
		delete[] b;
		delete tr;
	}
	return 0;
}
