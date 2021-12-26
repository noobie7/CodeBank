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
    vector<pair<ll, ll>> a(n);
    map<ll, pair<ll,ll>> f;
    for(int i = 0; i < n; i++){
        ll x, id; cin >> x >> id;
        if(f.count(id) == 0){
            f[id] = {x, x};
        }
        else{
            f[id] = {min(x, f[id].ff), max(x, f[id].ss)};
        }
    }
    f[n + 1] = {0, 0};
    vector<vector<pair<ll, ll>>> dp(n + 2, vector<pair<ll, ll>>(2));
    dp[0][0] = dp[0][1] = {0, 0};
    for(int i = 1; i <= n + 1; i++){
        if(f.count(i) == 0){
            for(int j = 0; j < 2; j++){
                dp[i][j] = dp[i - 1][j];
            }
            continue;
        }
        ll l = f[i].ff;
        ll r = f[i].ss;
        dp[i][1] = dp[i][0] = {INF, INF};

        for(int j = 0; j < 2; j++){
            ll cost = dp[i - 1][j].ff;
            ll pos = dp[i - 1][j].ss;
            
            { // choosing to end up at the right most point of all possible positions with ball indexed i
                if(pos < l){
                    dp[i][1] = min(dp[i][1], {cost + (r - pos), r});
                }
                else{
                    dp[i][1] = min(dp[i][1], {cost + ( r - l + pos - l ) , r});
                }
            }
            { // choosing to end up at the left most point of all possible positions with ball indexed i
                if(r < pos){
                    dp[i][0] = min(dp[i][0], {cost + (pos - l), l});
                }
                else{
                    dp[i][0] = min(dp[i][0], {cost + ( r - l + r - pos ) , l});
                }
            }
        }   
    }
    cout << min(dp.back()[0].ff, dp.back()[1].ff) << endl;
    return 0;
}