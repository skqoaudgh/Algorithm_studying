#include <iostream>
using namespace std;

int temp[100];

void swap(int &a, int &b)
{
	int temp = a;
	a=b;
	b=temp;
}

// n^2 정렬 알고리즘
// 버블 정렬 : 인접한 두 원소를 비교하여 정렬 
void bubbleSort(int arr[], int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			if(arr[j] > arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
} 

// 선택 정렬 : 가장 큰 원소를 배열의 처음(마지막) 원소와 교환하여 정렬
void selectionSort(int arr[], int size)
{
	for(int i=0; i<size-1; i++)
	{
		int min_index = i;
		for(int j=i; j<size; j++)
		{
			if(arr[j] < arr[min_index])
				min_index = j;
		}
		swap(arr[i],arr[min_index]);
	}
}

// 삽입 정렬 : Key를 왼쪽 부분은 정렬이 된 것이다. 이 부분에서 Key를 적절한 인덱스에 끼워 넣어 정렬 상태를 유지
void insertionSort(int arr[], int size)
{
	int j;
	for(int i=1; i<size; i++)
	{
		int key = arr[i];
		for(j=i-1; j>=0 && arr[j]>key; j--)
			arr[j+1] = arr[j];
		arr[j+1] = key;
	}
}

// nlogn 정렬 알고리즘 
// 퀵 정렬 : 정렬 후 분할 
void quickSort(int arr[], int left, int right)
{
	int pivot = left;
	int j = left;
	int i = left+1;
	if(left < right)
	{
		for(; i<=right; i++)
		{
			if(arr[pivot] > arr[i])
			{
				j++;
				swap(arr[j],arr[i]);
			}
		}
		swap(arr[pivot],arr[j]);
		pivot = j;
		
		quickSort(arr,left,pivot-1);
		quickSort(arr,pivot+1,right);		
	}
}

// 기타 정렬 알고리즘
// 계수(Count) 정렬 : 데이터가 양수이고, 정수형 데이터 타입의 범위를 넘지 않아야 한다. 
void countSort(int arr[], int size)
{
	// 최대값 구하기
	int max_value = arr[0];
	for(int i=1; i<size; i++)
		if(max_value < arr[i])
			max_value = arr[i];
		
	int* temp = new int[max_value];
	for(int i=0; i<max_value; i++)
		temp[i] = 0;
	
	for(int i=0; i<size; i++)
		temp[arr[i]]++;
		
	for(int i=0; i<=max_value; i++)
		for(int j=0; j<temp[i]; j++)
			cout << i << ' ';
	 
}

// 기수(Radix) 정렬 : 자릿수를 통해 정렬한다. 직접 비교를 하지 않으며 Stable-sort이다.
//					   버킷으로 큐를 주로 사용한다. 
void radixSort(int arr[], int size, int base) 
{
    int ex, i, j;
    
    // 자리수의 최대를 구하기위해 배열의 최대값 구하기 
	int max = arr[0];
    for(i=1; i<size; i++)
		if(arr[i]>max) 
			max=arr[i];
	
	// 1의 자리수부터 10^i의 자리수까지 
    for(ex=1; ex<=max; ex*=base) 
	{
    	int output[size], count[base] = {0};
    	for(i=0; i<size; i++) 
			count[(arr[i]/ex)%base]++; // 버킷의 자릿수에 대한 갯수 증가 (버킷:0~9) 
    	for(i=1; i<base; i++)
			count[i] += count[i-1];
    	for(i=size-1; i>-1; i--) 
		{
    		j = (arr[i]/ex)%base;
    		output[count[j]-1] = arr[i];
    		count[j]--;
    	}
    	for(i=0; i<size; i++) 
			arr[i] = output[i];
    }
}

// 병합 정렬 : 분할 후 정렬 
void mergeSort(int arr[], int left, int right)
{
	if(left < right)
	{
		int mid = (left+right)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		//-----
		int i = left;
		int j = mid+1;
		int k = left;
		while(i<=mid || j<=right)
		{
			if(i<=mid && (j>right || arr[i] <= arr[j]))
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		for(int i=left; i<=right; i++)
			arr[i] = temp[i];
	}
}

int main()
{
	int arr[] = {3,1,6,2,7,1};
	radixSort(arr,6,10);
	for(int i=0; i<6; i++)
		cout << arr[i] << ' ';
	return 0;
}
