/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

vector<array<pair<ll,ll>,2>> dp[1e5 + 4];
// min. score (dp[i][0].ff) till ith place in the string w 0 at ith place dp[i][0].ss no. of 1
// min. score (dp[i][1].ff) till ith place in the string w 1 at ith place dp[i][1].ss no. of 1


int main(){
    Shazam;
    string s; cin >> s; 
    ll x, y; cin >> x >> y;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            dp[i + 1][0] = {dp[i][0].ff + (i - dp[i][0].ss) * x, dp[i][0].ss + 1};
            dp[i + 1][1] = {dp[i][1].ff + (i - dp[i][1].ss) * x, dp[i][1].ss + 1}; 
        }
        else if(s[i] == '0'){
            dp[i + 1][0] = {dp[i][0].ff + (dp[i][0].ss) * y, dp[i][0].ss };
            dp[i + 1][1] = {dp[i][1].ff + (dp[i][1].ss) * y, dp[i][1].ss }; 
        }
        else{
            {
                dp[i + 1][0] = { min(dp[i][0].ff + dp[i][0].ss * y, dp[i][1].ff + dp[i][0].ss * y), dp[i][0].ss};
            }
            {
                dp[i + 1][1] = { min(dp[i][0].ff + (i - dp[i][0].ss) * x , dp[i][1].ff + (i - dp[i][1].ss) * x), dp[i]}
            }
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}