#include<bits/stdc++.h>
using namespace std;

int Unbounded_knapsack(int Length[], int Prize[], int Cap, int Sz)
{
    int DP[Sz + 1][Cap + 1];
    for(int i = 0; i < Sz + 1; i++)
    {
        for(int j = 0; j < Cap + 1; j++)
        {
            if(i == 0 || j == 0)
                DP[i][j] = 0;
        }
    }

    for(int i = 1; i < Sz + 1; i++)
    {
        for(int j = 1; j < Cap + 1; j++)
        {
            if(Length[i - 1] <= j)
                DP[i][j] = max(Prize[i - 1] +  DP[i][j - Length[i - 1]] , DP[i - 1][j]);
            
            else if(Length[i - 1] > j)
                DP[i][j] = DP[i - 1][j];
        }
    }
    return DP[Sz][Cap];
}


int main()
{
    //memset(DP, -1, sizeof(DP));
    int Prize[] = {60, 100, 120};
    int Length[] = {1,2,3};
    int W = 3;
    cout<<Unbounded_knapsack(Length, Prize, W, 3)<<endl;
    return 0;
}