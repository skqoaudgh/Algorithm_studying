#include <iostream>
#include <cstdio>
 
using namespace std;
 
int arr[200002];
int lis[200002];
 
int _lower_bound(int start, int end, int target)
{
    int mid;
    while (end - start > 0)
    {
        mid = (start + end) / 2;
        if (lis[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    return end + 1;
}
 
int main()
{
    int n; 
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
 
    int pArr = 1;
    int pLis = 0;
    int cnt = 0;
    lis[0] = arr[0];
    
    for (pArr; pArr < n; pArr++)
    {
        if (lis[pLis] < arr[pArr])
            lis[++pLis] = arr[pArr];
 
        else
        {
            int ans = _lower_bound(0, pLis, arr[pArr]);
            lis[ans - 1] = arr[pArr];
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
