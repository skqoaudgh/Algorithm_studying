#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Trie {
	Trie *go[26]; // 26 알파벳에 대한 go 노드
	Trie *fail; // 현재 노드에서 갈 노드가 없을 때 가는 노드
	bool output; // insert한 문자열의 맨 마지막 알파벳에 true 설정. 이 노드에 도달한다면 문자열을 찾은 것임 
	
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
				next->fail = root; // 루트 다음 노드의 fail은 루트이다. 
			else
			{
				// dest는 next의 최종 fail 목적지가 됨 
				Trie *dest = current->fail;
				
				// fail로 이동했을 때, 갈 곳이 있을 때 까지 계속 fail을 따라 이동 
				while(dest != root && !dest->go[i]) 
					dest = dest->fail;
					
				// fail(px) = go(fail(p), x)
				if(dest->go[i]) 
					dest = dest->go[i];
				next->fail = dest;
			}
			// fail(x) = y일 때, output(y) ⊂ output(x)
			// fail로 이동한 노드의 output이 true라면 fail로 이동하기 전 노드의 output도 true이다. 
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
