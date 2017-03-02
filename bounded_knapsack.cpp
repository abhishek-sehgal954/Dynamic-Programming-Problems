// Dynamic Programming Knapsack
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int dp[1000][1000];
int maximum_benefit(vector<pair<int,int> > item_details,int cost, int index,int n)
{
    int ans=0;
    if(index==n)
        return 0;
    if(dp[index][cost]==-1)
    {
    if(item_details[index].first<=cost)
        ans=max(maximum_benefit(item_details,cost,index+1,n),item_details[index].second+maximum_benefit(item_details,cost-item_details[index].first,index+1,n));
        dp[index][cost]=ans;
    }
    return dp[index][cost];
}
int main()
{
    int i,j,n,ans=0,cost;
    cin>>n;                                            //number of items
    vector<pair<int,int>> item_details(n);             //first corresponds to cost, second correspondes to benefit
    for(i=0;i<n;i++)
    {
     cin>>item_details[i].first;                      //cost  
    }
    for(i=0;i<n;i++)
    {
     cin>>item_details[i].second;                     //benefit 
    }
    cin>>cost;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=cost;j++)
            dp[i][j]=-1;
    }
    ans=maximum_benefit(item_details,cost,0,n);
    cout<<ans<<endl;
    return 0;
}