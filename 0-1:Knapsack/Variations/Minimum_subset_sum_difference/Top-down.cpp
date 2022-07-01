#include<bits/stdc++.h>
using namespace std;

bool DP[100][100];

int Max_Subset_Sum(int Arr[], int N)
{
    int Sum = 0;
    for(int i = 0; i < N; i++)
        Sum += Arr[i];

    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= Sum; j++)
        {
            if(i== 0)
                DP[i][j] = false;
            if(j == 0)
                DP[i][j] = true;
        }
    }

    for(int i = 1; i <= N ;i++)
    {
        for(int j = 1; j <= Sum; j++)
        {
            if(Arr[i - 1] <= Sum)
                DP[i][j] = DP[i - 1][j - Arr[i - 1]] || DP[i - 1][j];
            else
                DP[i][j] = DP[i - 1][j];
        }
    }

    vector<int> V;
    for(int j = 0; j <= Sum / 2; j++)
    {
        if(DP[N][j])
            V.push_back(j);
    }

    int Minn = Sum + 1;
    for(int i = 0; i < V.size(); i++)
        Minn = min(Sum - (2 * V[i]), Minn);
        
    return Minn;
}


int main()
{
    int Arr[] = {1, 6, 11};
    cout<<Max_Subset_Sum(Arr, 3)<<endl;

}