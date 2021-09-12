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
const int inf = 1e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin >> n;
    int m; cin >> m;
    int x; cin >> x;
    int y; cin >> y;
    vector<vector<array<ll,3>>> g(n + 1);
    for(int i = 0; i < m; i++){
        ll a, b, t, k; 
        cin >> a >> b >> t >> k;
        g[a].push_back({b, t, k});
        g[b].push_back({a, t, k});
    }
    priority_queue<pair<ll,int>> q;
    vector<ll> d(n + 1, INF);
    d[x] = 0;
    q.push({0, x});
    while(!q.empty()){
        auto best = q.top();
        q.pop();
        int u = best.ss;
        ll dis = -best.ff;
        if(dis != d[u]) continue;
        for(auto [to, tdis, k]  : g[u]){
            if(d[to] > tdis + dis + (  ( (dis + k - 1) / k ) * k  - dis)){
                d[to] =  tdis + dis + (  ( (dis + k - 1) / k ) * k   - dis);
                q.push({-d[to], to});
            }
        }   
    }
    cout << ( d[y] == INF ? -1 : d[y]) << endl;
    return 0;
}