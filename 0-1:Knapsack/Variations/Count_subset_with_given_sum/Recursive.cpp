#include<bits/stdc++.h>
using namespace std;

int Count_Subset(int Arr[], int Sum, int N)
{
    if(Sum == 0)
        return 1;
    if(N == 0)
        return 0;

    if(Arr[N - 1] <= Sum)
        return Count_Subset(Arr, Sum - Arr[N - 1], N - 1) + Count_Subset(Arr, Sum, N - 1);
    else
        return Count_Subset(Arr, Sum, N - 1);
}

int main()
{
    int Arr[] = {2, 3, 5, 6, 8 ,10};
    int Sum = 10;
    cout<<Count_Subset(Arr, Sum, 6)<<endl;
}