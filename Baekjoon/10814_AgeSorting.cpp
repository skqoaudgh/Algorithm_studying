#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct ACC {
	int age,no;
	string name;
	ACC(int a, string b, int c) { age=a; name=b; no=c; }
};

bool comp(ACC a, ACC b) 
{
	if(a.age == b.age)
		return a.no < b.no;
	return a.age<b.age;	
}

int main()
{
	vector<ACC> v;
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		int a;
		string b;
		cin >> a >> b;
		v.push_back(ACC(a,b,i));
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0; i<N; i++)
		cout << v[i].age << ' ' << v[i].name << '\n';
	return 0;
}
