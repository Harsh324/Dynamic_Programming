#include<bits/stdc++.h>
using namespace std;

bool DP[100][100];


bool Sub_sum(int Arr[], int Sum, int N)
{
    if(Sum == 0)
        return true;
    
    if(N == 0)
        return false;

    if(Arr[N - 1] <= Sum)
        return DP[N][Sum] = Sub_sum(Arr, Sum - Arr[N - 1], N - 1) || Sub_sum(Arr, Sum , N - 1);
    else
        return DP[N][Sum] = Sub_sum(Arr, Sum, N - 1);
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout<<Sub_sum(set, sum, 6)<<endl;
}