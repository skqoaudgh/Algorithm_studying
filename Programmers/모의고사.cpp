#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsFirstCorrect(int number, int answer)
{
    int myAns = (number%5) + 1;
    if(myAns == answer)
        return true;
    return false;
}

bool IsSecondCorrect(int number, int answer)
{
    int myAns;
    if(number % 2 == 0)
        myAns = 2;
    else
    {
        if(number % 8 == 1)
            myAns = 1;
        else if(number % 8 == 3)
            myAns = 3;     
        else if(number % 8 == 5)
            myAns = 4;
        else if(number % 8 == 7)
            myAns = 5;            
    }
    if(myAns == answer)
        return true;
    return false;
}

bool IsThirdCorrect(int number, int answer)
{
    int myAns;
    number = number % 10;
    if(number == 0 || number == 1)
        myAns = 3;
    else if(number == 2 || number == 3)
        myAns = 1;    
    else if(number == 4 || number == 5)
        myAns = 2;    
    else if(number == 6 || number == 7)
        myAns = 4;    
    else if(number == 8|| number == 9)
        myAns = 5;
    
    if(myAns == answer)
        return true;
    return false;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    //-----
    int arr[3] ={0,};
    for(int i=0; i<answers.size(); i++)
    {
        if(IsFirstCorrect(i,answers[i]))
            arr[0] ++;
        if(IsSecondCorrect(i,answers[i]))
            arr[1] ++;
        if(IsThirdCorrect(i,answers[i]))
            arr[2] ++;
    }
    int max = arr[0];
    for(int i=1; i<3; i++)
        if(max < arr[i])
            max = arr[i];

     for(int i=0; i<3; i++)
    {
        if(max == arr[i])
            answer.push_back(i+1);
    } 
    return answer;
}
