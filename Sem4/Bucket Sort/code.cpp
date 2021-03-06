// C++ program to sort an array using bucket sort 
#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 

// Function to sort arr[] of size n using bucket sort 
void bucketSort(float arr[], int n) 
{ 
    vector<float> b[n];
    for(int i=0;i<n;i++)
        b[int(n*arr[i])].push_back(arr[i]);
    for(int i=0;i<n;i++)
        sort(b[i].begin(),b[i].end());
    int i=0;
    for(int j=0;j<n;j++){
        for(int k=0;k<b[j].size();k++)
            arr[i++]=b[j][k];
    }
} 

/* Driver program to test above funtion */
int main() 
{ 
	float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	bucketSort(arr, n); 

	cout << "Sorted array is \n"; 
	for (int i=0; i<n; i++) 
	cout << arr[i] << " "; 
	return 0; 
} 
