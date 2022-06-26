#include<bits/stdc++.h>
using namespace std;


int Knapsack(int Wt[], int Val[], int Cap, int Sz)
{
    if(Cap == 0 || Sz == 0)
        return 0;

    if(Wt[Sz - 1] <= Cap)
        return max(Val[Sz - 1] + Knapsack(Wt, Val, Cap - Wt[Sz - 1], Sz - 1) , Knapsack(Wt, Val, Cap, Sz - 1));

    else if(Wt[Sz - 1] > Cap)
        return Knapsack(Wt, Val, Cap, Sz - 1);
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