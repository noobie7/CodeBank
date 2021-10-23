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
    int m; cin >> m;
    int k; cin >> k;
    vector<int> f[5005];
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        f[a].push_back(b);
        f[b].push_back(a);
    }
    vector<ll> dp(5005);
    vector<ll> curr(5005);
    auto sub = [&](ll &a, ll b){
        a = (a - b + mod)%mod;
    };
    dp[0] = 1;
    for(int i = 0; i < k; i++){
        ll s = 0;
        for(int j = 0; j < n; j++){
            s += dp[j];
            s %= mod;
        }
        for(int j = 0; j < n; j++){
            curr[j] = (s - dp[j] + 2LL * mod ) % mod;
            for(int x : f[j]){
                sub(curr[j], dp[x]);
            }
        }
        dp = curr;
    }
    cout << dp[0] << endl;
    return 0;
}