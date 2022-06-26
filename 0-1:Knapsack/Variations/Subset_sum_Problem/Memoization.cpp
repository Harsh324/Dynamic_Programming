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
            if(DP[i - 1][j] <= j)
                DP[i][j] = DP[i - 1][j - DP[i][j]] || DP[i - 1][j];
            else
                DP[i][j] = DP[i - 1][j];
        }
    }
    return DP[N][Sum];
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout<<Sub_sum(set, sum, 6)<<endl;
}