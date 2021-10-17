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
    
    vector<vector<pair<int, ll>>> g(n);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        ll c; cin >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vector<ll> d(n); 
    get(d);

    auto djikstra = [&](int s = 0){
        vector<ll> D(n, 1e18);
        priority_queue<pair<ll, int>> q;
        q.push({0, s});
        D[s] = 0;
        while(!q.empty()){
            auto pp = q.top();
            q.pop();
            if(abs(pp.ff) != D[pp.ss]) continue;
            int u = pp.ss;
            ll dis = -1 * pp.ff;
            for(auto [v, c] : g[u]){    
                if(dis + c < D[v]){
                    D[v] = dis + c;
                    q.push({-D[v], v});
                }
            }
        }
        return D;
    };
    int s = 0, x = -1, y = -1;
    {
        auto ds = djikstra(s);
        ll cost = -1;
        for(int i = 0; i < n; i++){
            if(i == s) continue;
            if(d[i] + ds[i] > cost){
                cost = d[i] + ds[i];
                x = i;
            }
        }
    }
    {
        auto dx = djikstra(x);
        ll cost = -1;
        for(int i = 0; i < n; i++){
            if(i == x) continue;
            if(d[i] + dx[i] > cost){
                cost = d[i] + dx[i];
                y = i;
            }
        }
    }
    auto dx = djikstra(x);
    auto dy = djikstra(y);
    for(int i = 0; i < n; i++){
        ll ans = 0;
        if(i != x) ans = max(ans, dx[i] + d[x]);
        if(i != y) ans = max(ans, dy[i] + d[y]);
        cout << ans << endl;
    }
    return 0;
}