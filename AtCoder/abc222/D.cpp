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
const int mod = 998244353;



int main(){
    Shazam;
    int n; cin >> n;
    vector<int> s(n), t(n);
    get(s);
    get(t);
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        a[i].ff = s[i];
        a[i].ss = t[i];
    }
    vector<vector<ll>> dp(n, vector<ll> (3004));

    for(int i = a[0].ff; i <= a[0].ss; i++){
        dp[0][i] = 1;
    }
    auto add = [&](ll &a, ll b){
        a = (a%mod + b%mod)%mod;
    };
    for(int i = 1; i < n; i++){
        for(int j = 1; j < 3004; j++){
            add(dp[i - 1][j], dp[i - 1][j - 1]);     
        }
        for(int j = a[i].ff; j <= a[i].ss; j++){
            add(dp[i][j], dp[i - 1][j]);   
        }
    }
    ll ans = 0;
    for(int j = 0; j <= 3004; j++){
        add(ans, dp[n - 1][j]);
    }
    cout << ans << endl;
    return 0;
}