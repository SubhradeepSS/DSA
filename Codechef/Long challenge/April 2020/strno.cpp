#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool kFactors(int n, int k) 
{ 
    vector<int> P;
    while (n%2 == 0) 
    { 
        P.push_back(2); 
        n /= 2; 
    } 
    for (int i=3; i*i<=n; i=i+2) 
    { 
        while (n%i == 0) 
        { 
            n = n/i; 
            P.push_back(i); 
        } 
    } 
 
    if (n > 2) 
        P.push_back(n); 
    if (P.size() < k) 
    { 
        return false; 
    } 
    return true;
    
} 

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x,k;
	    cin>>x>>k;
	    if(kFactors(x,k))
	        cout<<"1"<<endl;
	   else
	        cout<<"0"<<endl;
	}
	return 0;
}
