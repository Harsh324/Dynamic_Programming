#include<bits/stdc++.h>
using namespace std;

int static DP[100][100];

int Knapsack(int Wt[], int Val[], int Cap , int Sz)
{
    if(Sz == 0 || Cap == 0)
        return 0;
    
    // if(DP[Sz][Cap] == -1)
    //     return DP[Sz][Cap];

    if(Wt[Sz - 1] <= Cap)
        return DP[Sz][Cap] = max( Val[Sz - 1] + Knapsack(Wt, Val, Cap - Wt[Sz - 1], Sz - 1), Knapsack(Wt, Val, Cap, Sz - 1));
    
    else
        return DP[Sz][Cap] = Knapsack(Wt, Val, Cap, Sz - 1);
}

int main()
{
    memset(DP, -1, sizeof(DP));
    int value[] = {1, 2, 3};
    int weight[] = {4, 5, 1};
    int W = 3;
    cout<<Knapsack(weight, value, W, 3)<<endl;
    return 0;
}