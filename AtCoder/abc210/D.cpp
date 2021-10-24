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
const ll INF = 1e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int h, w; cin >> h >> w;
    ll c; cin >> c;
    vector<vector<ll>> grid(h + 1, vector<ll> (w + 1));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> grid[i][j];
        }
    }
    ll ans = INF;
    auto process = [&](){
        vector<vector<ll>> dp(h + 1, vector<ll> (w + 1));
        for(int i = 0; i <= h; i++) dp[i][0] = INF;
        for(int j = 0; j <= w; j++) dp[0][j] = INF;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                dp[i][j] = min({grid[i][j], dp[i - 1][j] + c, dp[i][j - 1] + c});
            }
        }
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                ans = min({ans, c + grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])});
            }
        }
    };
    
    process();

    for(auto &v : grid){
        reverse(v.begin() + 1, v.end());
    }

    process();

    cout << ans << endl;
    return 0;
}