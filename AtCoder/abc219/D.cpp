/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ff first
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define fl(i,a,b) for(int i = a ; i <b ;i++)
#define get(a) fl(i,0,a.size())  cin>>a[i];
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin >> n;
    int x, y; cin >> x >> y;
    int mx = 0, my = 0;
    vector<pair<int,int>> lunch(n);
    for(int i = 0; i < n; i++){
      cin >> lunch[i].ff >> lunch[i].ss;

    }
    vector<vector<int>> dp(300 + 1, vector<int>(300 + 1, inf));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
      auto pp = lunch[i];
      for(int j = 300; j >= 0; j--){
        for(int k = 300; k >= 0; k--){
          int _x = min(x, j + pp.ff);
          int _y = min(y, k + pp.ss);
          if(dp[j][k] != inf)
            dp[_x][_y] = min(dp[_x][_y], dp[j][k] + 1);
        }
      }
    }

    cout <<  (dp[x][y] == inf ? -1 : dp[x][y])<< endl;

    return 0;
}