#include<bits/stdc++.h>
using namespace std;

bool DP[100][100];

bool Sub_sum(int Arr[], int Sum, int N)
{
    if(Sum == 0)
        return true;
    
    if(N == 0)
        return false;


    if(DP[N - 1][Sum] <= Sum)
        return DP[N][Sum] = DP[N - 1][Sum - DP[N][Sum]] || DP[N - 1][Sum];
    else
        DP[N][Sum] = DP[N - 1][Sum];
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout<<Sub_sum(set, sum, 6)<<endl;
}