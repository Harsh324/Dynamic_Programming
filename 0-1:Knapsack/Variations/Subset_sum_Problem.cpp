#include<bits/stdc++.h>
using namespace std;

bool Sub_sum(int Arr[], int Sum, int N)
{
    cout<<"Sum = "<<Sum <<" , N = "<<N<<endl;
    if(Sum == 0)
        return true;
    
    if(N == 0)
        return false;

    if(Arr[N - 1] <= Sum)
        return (Sub_sum(Arr, Sum - Arr[N - 1], N - 1) || Sub_sum(Arr, Sum , N - 1));

    else
        return Sub_sum(Arr, Sum, N - 1);
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 30;
    cout<<Sub_sum(set, sum, 6)<<endl;
}