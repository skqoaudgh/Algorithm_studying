#include <string>
#include <vector>

using namespace std;

int answer = 0;

int func(vector<int> arr, int idx, int num, int target)
{
    int size = arr.size();
    if(idx == size)
    {
        if(target == num)
            return 1;
        else 
            return 0;
    }
    else
    {
        return func(arr,idx+1,num+arr[idx],target) + func(arr,idx+1,num-arr[idx],target);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = func(numbers,0,0,target);
    return answer;
}
