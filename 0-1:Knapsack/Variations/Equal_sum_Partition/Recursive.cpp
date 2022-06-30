#include<bits/stdc++.h>
using namespace std;

bool Sub_sum(int Arr[], int Sum, int N)
{
    if(Sum == 0)
        return true;
    
    if(N == 0)
        return false;

    if(Arr[N - 1] <= Sum)
        return (Sub_sum(Arr, Sum - Arr[N - 1], N - 1) || Sub_sum(Arr, Sum , N - 1));

    else
        return Sub_sum(Arr, Sum, N - 1);
}


bool Equal_Sum_Partiton(int Arr[], int N)
{
    int Sum = 0;
    for(int i = 0; i < N; i++)
        Sum += Arr[i];

    if(Sum % 2 != 0)
        return false;
    else
        return Sub_sum(Arr, Sum / 2, N);
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 30;
    cout<<Sub_sum(set, sum, 6)<<endl;
}