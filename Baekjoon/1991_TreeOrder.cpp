#include <cstdio>

int left_child[27];
int right_child[27];

void preorder(int root)
{
	printf("%c",root+'A');
	if(left_child[root] != -1) preorder(left_child[root]);
	if(right_child[root] != -1) preorder(right_child[root]);
}
void inorder(int root)
{	
	if(left_child[root] != -1) inorder(left_child[root]);
	printf("%c",root+'A');
	if(right_child[root] != -1) inorder(right_child[root]);
}
void postorder(int root)
{
	if(left_child[root] != -1) postorder(left_child[root]);
	if(right_child[root] != -1) postorder(right_child[root]);
	printf("%c",root+'A');
}
int main()
{
	int N;
	scanf("%d",&N);
	
	for(int i=0; i<27; i++)
	{
		left_child[i] = -1;
		right_child[i] = -1;
	}
	for(int i=0; i<N; i++)
	{
		char parent, lc, rc;
		scanf(" %c %c %c",&parent,&lc,&rc);
		if(lc != '.')
			left_child[parent-'A'] = lc-'A';
		if(rc != '.')
			right_child[parent-'A'] = rc-'A';
	}
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	
	return 0;
}
