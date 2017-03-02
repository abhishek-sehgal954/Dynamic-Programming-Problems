//problem statement
/*
 Byteland is a scarcely populated country, and residents of different cities seldom communicate with each other. 
 There is no regular postal service and throughout most of the year a one-man courier establishment suffices to transport all freight. 
 However, on Christmas Day there is somewhat more work for the courier than usual, and since he can only transport one parcel at a time on his bicycle, 
 he finds himself riding back and forth among the cities of Byteland.
The courier needs to schedule a route which would allow him to leave his home city, perform the individual orders in arbitrary order (i.e. travel to the city of the sender and transport the parcel to the city of the recipient, carrying no more than one parcel at a time), and finally return home. All roads are bi-directional, but not all cities are connected by roads directly; some pairs of cities may be connected by more than one road. Knowing the lengths of all the roads and the errands to be performed, determine the length of the shortest possible cycling route for the courier.
Input
The input begins with the integer t, the number of test cases. Then t test cases follow.
Each test case begins with a line containing three integers: n m b, denoting the number of cities in Byteland, the number of roads, 
and the number of the courier's home city, respectively (1<=n<=100,1<=b<=m<=10000). The next m lines contain three integers each, the i-th being ui vi di, which means that cities ui and vi are connected by a road of length di (1<=ui,vi<=100, 1<=di<= 10000). The following line contains integer z - the number of transport requests the courier has received (1<=z<=5). After that, z lines with the description of the orders follow. Each consists of three integers, the j-th being uj vj bj, which signifies that bj parcels should be transported (individually) from city uj to city vj. The sum of all bj does not exceed 12.
Output
For each test case output a line with a single integer - the length of the shortest possible bicycle route for the courier. */
//test case
/*
Sample input
1
5 7 2
1 2 7
1 3 5
1 5 2
2 4 10
2 5 1
3 4 3
3 5 4
3
1 4 2
5 3 1
5 1 1
Sample output
43*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
#define INF 999999999
long long int n,m,b,z;
long long int prob[101][101];
long long int dp[14][1<<(14)];
vector<pair<long long int,long long int> > v;
long long int func(long long int last,long long int mask)
{
   //cout<<mask<<" ";
    long long int i,j;
    long long int ans=INF;
    i=__builtin_popcount (mask);
    //cout<<i<<" ";
    if(i==z)
        return prob[v[last].second][b];
    if(dp[last][mask]==-1)
    {
        for(j=0;j<z;j++)
            {
                if(!((1<<j)&mask))
                    ans=min(ans,prob[v[last].second][v[j].first]+prob[v[j].first][v[j].second]+func(j,mask+(1<<j)));


            }
        dp[last][mask]= ans;
    }
    return dp[last][mask];

}
 int main()
{
    long long int i,j,k,l,t;
    long long int bak,ans;;
    cin>>t;

    while(t--)
    {
            cin>>n>>m>>b;
            b--;
            for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                        {
                            if(i!=j)
                                prob[i][j]=INF;
                            else
                                prob[i][j]=0;
                        }

                }
            for(i=0;i<m;i++)
                {
                    cin>>j>>k>>bak;;
                    j--;
                    k--;
                    prob[j][k]=min(prob[j][k],bak);
                    prob[k][j]=min(prob[k][j],bak);

                }
            for(k=0;k<n;k++)
                {
                    for(i=0;i<n;i++)
                        {
                            for(j=0;j<n;j++)
                                {
                    
                                    if(prob[i][k]+prob[k][j]<prob[i][j])
                                        prob[i][j]=prob[i][k]+prob[k][j];
            
                                 }
                        }
                }   
            cin>>z;
            v.clear();
             pair<long long int,long long int> foo;

            for(i=0;i<z;i++)
                {
                     cin>>j>>k>>bak;
                     foo=make_pair(j-1,k-1);
                    for(j=0;j<bak;j++)
                        v.push_back(foo);

                }
            z=v.size();

            for(j=0;j<z;j++)
                for(i=0;i<(1<<(z+1));i++)
                     dp[j][i]=-1;

            ans=INF;
            for(i=0;i<z;i++)
                ans=min(ans,prob[b][v[i].first]+prob[v[i].first][v[i].second]+func(i,1<<i));
   
  
            cout<<ans<<endl;
    }


    return 0;
}