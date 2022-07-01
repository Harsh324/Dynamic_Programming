#include<bits/stdc++.h>
using namespace std;

int DP[100][100];

int Count_Subset(int Arr[], int Sum, int N)
{
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= Sum; j++)
        {
            if(i == 0)
                DP[i][j] = 0;
            if(j == 0)
                DP[i][j] = 1;
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= Sum; j++)
        {
            if(Arr[i - 1] <= Sum)
            {
                DP[i][j] = DP[i - 1][Sum - Arr[i - 1]] + DP[i - 1][Sum];
            }
            else
                DP[i][j] = DP[i - 1][Sum];
        }
    }
    return DP[N][Sum];
}

int main()
{
    int Arr[] = {2, 3, 5, 6, 8 ,10};
    int Sum = 10;
    cout<<Count_Subset(Arr, Sum, 6)<<endl;
}