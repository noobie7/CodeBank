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
    ll k; cin >> k;
    vector<int> a(m);
    get(a);
    for(int &i : a) i--;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    map<int,int> f;

    function<int(int ,int, int)> dfs = [&](int u, int  p, int d){
        if(u == d) return 1;
        for(auto [v, i] : g[u]){
            if(v == p) continue;
            if(dfs(v, u, d)){
                f[i]++;
                return 1;
            }
        }
        return 0;
    };

    for(int i = 0; i + 1 < m; i++){
        int des = a[i + 1];
        dfs(a[i], -1, des);
    }
    ll s = 0;
    for(auto pp : f){
        s += pp.ss;
    }
    if(((s + k) & 1 ) || s + k < 0){
        cout << 0 << endl;
        return 0;
    }
    vector<int> dp(1e5 + 5);
    dp[0] = 1;
    for(int i = 0; i < n - 1; i++){
        for(int j = 100005; j >= f[i]; j--){
            dp[j] = (dp[j] + dp[j - f[i]]) % mod;
        }
    }
    cout << dp[(s + k) / 2] << endl;
    return 0;
}