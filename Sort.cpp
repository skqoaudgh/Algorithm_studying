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
// 버블 정렬 : 인접한 두 원소를 비교하여 정렬. 비교 횟수가 많다. 
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
/*
	선택 정렬 : 가장 큰 원소를 배열의 처음(마지막) 원소와 교환하여 정렬
	교환의 횟수가 적다. -> 역순상태에서 가장 효율적이다. -> 이미 정렬된 상태가 최악이다. 
*/
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
/*
	삽입 정렬 : Key를 왼쪽 부분은 정렬이 된 것이다. 이 부분에서 Key를 적절한 인덱스에 끼워 넣어 정렬 상태를 유지
	쉘정렬은 삽입 정렬의 변형 알고리즘인데, 특정 Gap 차이가 나는 원소끼리만 삽입 정렬을 한다.
	멀리 있는 원소끼리 교환을 하기 때문에 교환한 원소가 적절한 자리가 맞을 확률이 높다. 
*/
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

/*
	nlogn 정렬 알고리즘 
	퀵 정렬 : 정렬 후 분할. Unstable-Sort이다. logN의 메모리가 필요
	피벗의 선정 방법에 따라 수행 속도에 차이가 있을 수 있다.
	먼 거리의 데이터와의  교환, 한 번의 연산에서 사용된 피벗은 다음 연산에서 사용하지 않음. -> 속도가 빠르다 
	분할한 공간을 참조할 때 CPU 캐시의 히트율이 높아 병합보다 빠르다. (메모리 참조가 지역화) 
	지역성 - 1) 공간지역성: 특정 클러스터에 대한 참조. 참조된 메모리 근처의 메모리를 참조한다.
			 2) 시간지역성: 최근 사용된 장소에 대한 참조. 최근 사용한 메모리는 다시 사용될 가능성이 높다.
			 3) 순차지역성: 데이터가 순차적으로 참조. 프로그램 내의 명령어가 순차적으로 구성되어 있다. 공간지역성에 편입 가능. 
*/ 
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

// 병합 정렬 : 분할 후 정렬. Stable-Sort이다. N만큼의 메모리가 추가적으로 필요 
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

int main()
{
	int arr[] = {3,1,6,2,7,1};
	radixSort(arr,6,10);
	for(int i=0; i<6; i++)
		cout << arr[i] << ' ';
	return 0;
}
