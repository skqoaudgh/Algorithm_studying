#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Trie {
	Trie *go[26]; // 26 ���ĺ��� ���� go ���
	Trie *fail; // ���� ��忡�� �� ��尡 ���� �� ���� ���
	bool output; // ���� ��忡 ã�� ���ڿ��� �ִ��� �˻�
	
	Trie() {
		fill(go, go+26, nullptr);
		output = false;
	} 
	~Trie() {
		for(int i=0; i<26; i++)
			if(go[i])
				delete go[i];
	}
	void insert(const char *key)
	{
		if(*key == '\0')
			output = true;
		else
		{
			int next = *key - 'a';
			if(!go[next])
				go[next] = new Trie();
			go[next]->insert(key+1);
		}
	}
};

int main()
{
	int N,M;
	char str[10001];
	Trie* root = new Trie();
	
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		scanf("%s",str);
		root->insert(str);	
	}
	
	queue<Trie*> q;
	root->fail = root;
	q.push(root);
	while(!q.empty())
	{
		Trie *current = q.front();
		q.pop();
		for(int i=0; i<26; i++)
		{
			Trie *next = current->go[i];
			if(!next) continue;
			
			if(current == root) 
				next->fail = root; // ��Ʈ ���� ����� fail�� ��Ʈ�̴�. 
			else
			{
				Trie *dest = current->fail;
				while(dest != root && !dest->go[i]) // fail�� �̵����� ��, �� ���� ���� �� ���� ��� fail�� ���� �̵� 
					dest = dest->fail;
				// fail(px) = go(fail(p), x)
				if(dest->go[i]) 
					dest = dest->go[i];
				next->fail = dest;
			}
			// fail(x) = y�� ��, output(y) �� output(x)
			if(next->fail->output) next->output = true;
			q.push(next);
 		}
	}
	
	scanf("%d",&M);
	for(int i=0; i<M; i++)
	{
		scanf("%s",str);
		Trie *current = root;
		bool result = false;
		for(int j=0; str[j]; j++)
		{
			int next = str[j]-'a';
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(current->output)
			{
				result = true;
				break;
			}
		}
		if(result)
			printf("YES\n");
		else
			printf("NO\n");
	} 
	
	return 0;
}
