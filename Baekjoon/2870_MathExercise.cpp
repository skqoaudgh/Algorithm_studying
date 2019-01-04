#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int i, j;
int n, len;
string s, tmp;
vector<string> v;

void func()
{  //���� ������ ���ڸ��� 0�� ��� ó�����ִ� �Լ�
	if (tmp[0] == '0') 
	{
		int len = tmp.length();
		for (j = 1; j < len; j++) 
		{
			if (tmp[j] != '0') 
			{ //���ڸ��� 0�ε� �ڿ� 0�̾ƴ� ������ ������ ���� 0�� ����
				tmp.erase(0, j);
				break;
			}
		}
		if (tmp[0] == '0' && tmp.length() > 1) // "00000"�� ���� ��� "0"���� �ٲ�
			tmp.assign("0");
	}
}

bool cmp(string a, string b) 
{
	int lenA = a.size();
	int lenB = b.size();
	if (lenA < lenB) 
		return true;
	else if (lenA > lenB) 
		return false;
	for (i = 0; i < lenA; i++) 
	{
		if (a[i] < b[i]) 
			return true;
		if (a[i] > b[i]) 
			return false;
	}
	return true;
}

int main() 
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	while (n--) 
	{
		cin >> s;
		len = s.length();
		for (i = 0; i < len; i++) 
		{
			if (s[i] >= '0' && s[i] <= '9')
				tmp.append(1, s[i]);
			else 
			{
				if (tmp.length() != 0) 
				{
					func();
					v.push_back(tmp);
					tmp.clear();
				}
			}
		}
		if (tmp.length() != 0) 
		{
			func();
			v.push_back(tmp);
			tmp.clear();
		}
	}
	sort(v.begin(), v.end(), cmp);
	len = v.size();
	for (i = 0; i < len; cout << v[i++] << "\n");
}
