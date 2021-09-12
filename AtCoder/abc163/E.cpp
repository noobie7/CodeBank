/*
"Do I really belong in this game I ponder, I just wanna play my part."
- Guts over fear, Eminem
 */
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
    int n; cin>>n;
    vector<pair<ll,ll>> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].ff;
        a[i].ss = i;
    }
    sort(a.rbegin(),a.rend());
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1e18));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            ll x = a[i].ff;         
            ll pos = a[i].ss;
            ll d1 = abs(pos - j);
            ll d2 = abs(n-1 -(i-j) - pos);
            dp[i+1][j] = max(dp[i+1][j], (dp[i][j] + d2 * x ));
            dp[i+1][j+1] = max(dp[i+1][j+1], (dp[i][j] + d1 * x )); 
        }
    }
    ll ans = 0; 
    for(int i = 0 ; i < n+1; i++){
        ans = max(ans, dp[n][i]);
    }
    cout<<ans<<endl;
    return 0;
}