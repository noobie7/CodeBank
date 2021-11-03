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
    int m; cin >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
      int a, b; cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vector<int> cc;
    vector<int> vis(n);
    function<void(int)> dfs = [&](int u){
      vis[u] = 1;  
      for(int v : g[u]){
        if(!vis[v]){
          dfs(v);
        }
      }
      cc.push_back(u);
    };
    ll ans = 1;
    for(int i = 0; i < n; i++){
      if(vis[i]) continue;
      cc.clear();
      dfs(i);
      reverse(all(cc));
      vector<int> col(n, -1);
      int m = cc.size();
      function<ll(int)> brute_force = [&](int idx){
        if(idx == m){
          return 1LL;
        }
        int u = cc[idx];
        ll res = 0;
        for(int c = 0; c < 3; c++){
          int ok = 1;
          for(int v : g[u]){
            if(col[v] == c)
              ok = 0;
          }
          if(ok){
            col[u] = c;
            res += brute_force(idx + 1);
            col[u] = -1;
          }
        }
        return res;
      };
      ans *= brute_force(0);
    }
    cout << ans << endl;
    return 0;
}