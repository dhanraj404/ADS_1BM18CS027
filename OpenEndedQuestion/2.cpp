/*
In the given range [L, R], print all numbers having unique digits. e.g. In range 10 to 20 should print all numbers except 11.
*/
#include<iostream>
using namespace std;

int unique(int a)
{
    // neg numbers check
    if (a < 0){
        a*=-1;
    }
    int b[10]={0},p=1;
    while(a)
    {
        if(++b[a%10]>1)
        {
            p=0;
            break;
        }
        a/=10;
    }
    return p;
}
int main()
 {
	int test;
	cin>>test;
	while(test--)
	{
	    int m,n;
	    cin>>m>>n;
	    for(int i=m;i<=n;i++){
	        if(unique(i))
	            cout<<i<<" ";
        }
	    cout<<"\n";
	}
	return 0;
}