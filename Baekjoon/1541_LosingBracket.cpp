#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	string str,temp_num;
	cin >> str;
	
	int sum = 0;
	bool flag = false; // -�� ������ true, ���� - ���� 
	for(int i=0; i<=str.size(); i++)
	{ 
		if(str[i] >= '0' && str[i] <= '9')
			temp_num += str[i];
		else
		{
			if(!flag)
			{
				sum += stoi(temp_num);
				//cout << stoi(temp_num) << "������\n";
			}
				
			else
			{
				sum -= stoi(temp_num);
				//cout << stoi(temp_num) << "����\n";
			}				
			temp_num.clear();
			if(str[i] == '-') flag = true;
		}
	}
	cout << sum;
	return 0;
}
