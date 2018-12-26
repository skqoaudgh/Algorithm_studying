#include <iostream>
using namespace std;

int main()
{
	int N,M,K; // 여,남,대회 : 여2:남1 비율로 팀을 만듬. 여자->남자 순으로 인턴쉽 참가 시키기 
	cin >> N >> M >> K;
	
	while(K > 0)
	{
		if(N>2*M)
			N --;
		else
			M --;
		K --;
	}
	
	int ans  = 0;
	while(N > 1 && M > 0)
	{
		N -=2;
		M --;
		ans ++;
	}
	cout << ans;
	return 0;
}
