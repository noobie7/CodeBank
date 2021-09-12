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



int main(){
    Shazam;
    int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;
    vector<vector<int>> g(n);
    vector<vector<int>> adj(n, vector<int> (n, -1));
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        adj[a][b] = adj[b][a] = c;
    }
    vector<array<int,2>> routes(k);
    for(int i = 0; i < k; i++){
        cin >> routes[i][0] >> routes[i][1];
        routes[i][0]--;
        routes[i][1]--;
    }
    vector<vector<ll>> dp(n, vector<ll> (n, INF));
    for(int root = 0; root < n; root++){
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>> , greater<pair<ll,ll>>> pq;
        pq.push({root, 0});
        dp[root][root] = 0;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            ll u = x.ff;
            ll d = x.ss;
            if(d != dp[root][u]) continue;
            for(int v : g[u]){
                if(dp[root][v] > d + adj[u][v]){
                    dp[root][v] = d + adj[u][v];
                    pq.push({v, d + adj[u][v]});
                }
            }
        }
    }
    ll ans = INF;
    for(int u = 0; u < n; u++){
        for(int v : g[u]){
            ll curr = 0;
            for(auto pp : routes){
                int a = pp[0];
                int b = pp[1];
                curr += min({ dp[a][b], dp[a][u] + dp[v][b], dp[a][v] + dp[u][b]});
            }
            ans = min(ans, curr);
        }
    }
    cout << ans << endl;
    return 0;
}