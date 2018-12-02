#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin,str);
	
	int happy_cnt = 0;
	int not_cnt = 0;
	int index = 0;
	while((index=str.find(":-)",index)) != -1) {
		happy_cnt ++;
		index += 3;
	}
	index = 0;
	while((index=str.find(":-(",index)) != -1) {
		not_cnt ++;
		index += 3;
	}
	
	if(happy_cnt == 0 && not_cnt == 0)
		cout << "none";
	else if(happy_cnt > not_cnt)
		cout << "happy";
	else if(happy_cnt == not_cnt)
		cout << "unsure";
	else
		cout << "sad";
	return 0;
}
