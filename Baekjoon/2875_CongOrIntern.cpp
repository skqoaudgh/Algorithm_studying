#include <iostream>
using namespace std;

int main()
{
	int N,M,K; // ��,��,��ȸ : ��2:��1 ������ ���� ����. ����->���� ������ ���Ͻ� ���� ��Ű�� 
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
