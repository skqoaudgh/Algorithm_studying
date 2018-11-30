#include <iostream>
#include <algorithm>
using namespace std;
 
#define INF 987654321
int V, E;
int arr[101][101];
int from, to, weight;

int main(){
    cin >> V >> E;
    for (int i=1; i<=V; i++)        // vectex table ÃÊ±âÈ­
        for (int j=1; j<=E; j++)
            arr[i][j] = INF;

    for (int i=0; i<E; i++) 
	{
        cin >> from >> to >> weight;
        if (arr[from][to] > weight) 
            arr[from][to] = weight;
    }
    
    for (int i=1; i<=V; i++) 
        for (int j=1; j<=V; j++) 
            for (int k=1; k<=V; k++)
                if (arr[j][i] != INF && arr[i][k] != INF)        
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
                    
    for (int i=1; i<=V; i++) {
        for (int j=1; j<=V; j++) {
            if (i==j || arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
