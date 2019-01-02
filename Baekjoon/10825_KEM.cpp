#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	int K,E,M;
	Student(string a, int b, int c, int d) { name=a; K=b; E=c; M=d; }
};

bool comp(Student p1, Student p2)
{
	if(p1.K == p2.K && p1.E == p2.E && p1.M == p2.M)
		return p1.name < p2.name;
	else if(p1.K == p2.K && p1.E == p2.E)
		return p1.M > p2.M;
	else if(p1.K == p2.K)
		return p1.E < p2.E;
	return p1.K > p2.K;
}

int main()
{
	vector<Student> v;
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		string a;
		int b,c,d;
		cin >> a >> b >> c >> d;
		v.push_back(Student(a,b,c,d));
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0; i<N; i++)
		cout << v[i].name << '\n';
	return 0;
}
