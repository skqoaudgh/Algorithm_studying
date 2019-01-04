#include <iostream>
using namespace std;

int temp[100];

void swap(int &a, int &b)
{
	int temp = a;
	a=b;
	b=temp;
}

// n^2 ���� �˰���
// ���� ���� : ������ �� ���Ҹ� ���Ͽ� ����. �� Ƚ���� ����. 
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
	���� ���� : ���� ū ���Ҹ� �迭�� ó��(������) ���ҿ� ��ȯ�Ͽ� ����
	��ȯ�� Ƚ���� ����. -> �������¿��� ���� ȿ�����̴�. -> �̹� ���ĵ� ���°� �־��̴�. 
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
	���� ���� : Key�� ���� �κ��� ������ �� ���̴�. �� �κп��� Key�� ������ �ε����� ���� �־� ���� ���¸� ����
	�������� ���� ������ ���� �˰����ε�, Ư�� Gap ���̰� ���� ���ҳ����� ���� ������ �Ѵ�.
	�ָ� �ִ� ���ҳ��� ��ȯ�� �ϱ� ������ ��ȯ�� ���Ұ� ������ �ڸ��� ���� Ȯ���� ����. 
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
	nlogn ���� �˰��� 
	�� ���� : ���� �� ����. Unstable-Sort�̴�. logN�� �޸𸮰� �ʿ�
	�ǹ��� ���� ����� ���� ���� �ӵ��� ���̰� ���� �� �ִ�.
	�� �Ÿ��� �����Ϳ���  ��ȯ, �� ���� ���꿡�� ���� �ǹ��� ���� ���꿡�� ������� ����. -> �ӵ��� ������ 
	������ ������ ������ �� CPU ĳ���� ��Ʈ���� ���� ���պ��� ������. (�޸� ������ ����ȭ) 
	������ - 1) ����������: Ư�� Ŭ�����Ϳ� ���� ����. ������ �޸� ��ó�� �޸𸮸� �����Ѵ�.
			 2) �ð�������: �ֱ� ���� ��ҿ� ���� ����. �ֱ� ����� �޸𸮴� �ٽ� ���� ���ɼ��� ����.
			 3) ����������: �����Ͱ� ���������� ����. ���α׷� ���� ��ɾ ���������� �����Ǿ� �ִ�. ������������ ���� ����. 
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

// ���� ���� : ���� �� ����. Stable-Sort�̴�. N��ŭ�� �޸𸮰� �߰������� �ʿ� 
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

// ��Ÿ ���� �˰���
// ���(Count) ���� : �����Ͱ� ����̰�, ������ ������ Ÿ���� ������ ���� �ʾƾ� �Ѵ�. 
void countSort(int arr[], int size)
{
	// �ִ밪 ���ϱ�
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

// ���(Radix) ���� : �ڸ����� ���� �����Ѵ�. ���� �񱳸� ���� ������ Stable-sort�̴�.
//					   ��Ŷ���� ť�� �ַ� ����Ѵ�. 
void radixSort(int arr[], int size, int base) 
{
    int ex, i, j;
    
    // �ڸ����� �ִ븦 ���ϱ����� �迭�� �ִ밪 ���ϱ� 
	int max = arr[0];
    for(i=1; i<size; i++)
		if(arr[i]>max) 
			max=arr[i];
	
	// 1�� �ڸ������� 10^i�� �ڸ������� 
    for(ex=1; ex<=max; ex*=base) 
	{
    	int output[size], count[base] = {0};
    	for(i=0; i<size; i++) 
			count[(arr[i]/ex)%base]++; // ��Ŷ�� �ڸ����� ���� ���� ���� (��Ŷ:0~9) 
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
