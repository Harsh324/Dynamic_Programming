#include<bits/stdc++.h>
using namespace std;


int Knapsack(int Wt[], int Val[], int Cap, int Sz)
{
    if(Cap == 0 || Sz == 0)
        return 0;

    if(Wt[Sz - 1] <= Cap)
        return max(Val[Sz - 1] + Knapsack(Wt, Val, Cap - Wt[Sz - 1], Sz - 1) , Knapsack(Wt, Val, Cap, Sz - 1));

    else
        return Knapsack(Wt, Val, Cap, Sz - 1);
}



int main()
{
    //memset(DP, -1, sizeof(DP));
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    cout<<Knapsack(weight, value, W, 3)<<endl;
    return 0;
}