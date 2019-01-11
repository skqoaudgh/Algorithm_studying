#include <stdio.h>
#include <cmath>

int R,B;

int isPossible(int l, int w)
{
	int brown = (l-2)*(w-2);
	int red = l*w - brown;
	if(brown == B && red == R)
		return 1;
	return 0;
}

int main()
{
	scanf("%d %d",&R,&B);	
	for(int l=3; l<=sqrt(R+B); l++)
	{
		int w = (R+B)/l;
		if(w < 3) continue;
		if(isPossible(l,w))
		{
			if(l > w)
				printf("%d %d",l,w);
			else
				printf("%d %d",w,l);
		}
	}
	return 0;
}
