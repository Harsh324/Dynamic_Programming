#include<bits/stdc++.h>
using namespace std;

int Knapsack(int Wt[], int Val[], int Cap, int Sz)
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
            if(Wt[i - 1] <= Cap)
                DP[i][j] = max(Val[i - 1] +  DP[i - 1][j - Wt[i - 1]] , DP[i - 1][j]);
            
            else if(Wt[i - 1] > Cap)
                DP[i][j] = DP[i - 1][j];
        }
    }
    return DP[Sz][Cap];
}


int main()
{
    //memset(DP, -1, sizeof(DP));
    int value[] = {20, 5, 10, 40, 15, 25};
    int weight[] = {1, 2, 3, 8, 7, 4};
    int W = 10;
    cout<<Knapsack(weight, value, 10, 6)<<endl;
    return 0;
}