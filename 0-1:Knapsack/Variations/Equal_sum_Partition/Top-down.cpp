#include<bits/stdc++.h>
using namespace std;

bool DP[100][100];

bool Sub_sum(int Arr[], int Sum, int N)
{
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= Sum; j++)
        {
            if(i == 0)
                DP[i][j] = false;
            if(j == 0)
                DP[i][j] = true;
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= Sum; j++)
        {
            if(Arr[i - 1] <= j)
                DP[i][j] = DP[i  -1][j - Arr[i - 1]] || DP[i - 1][j];
            else
                DP[i][j] = DP[i - 1][j];
        }
    }
    return DP[N][Sum];
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
    int set[] = {1, 3, 3, 3};
    cout<<Equal_Sum_Partiton(set, 4)<<endl;
}