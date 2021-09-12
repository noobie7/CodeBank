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

vector<vector<int>> g(2e3 + 5, vector<int> (2e3 + 5, inf));
vector<vector<int>> ed(2e3 + 5);
int main(){
    Shazam;
    int n, k; cin >> n >> k;
    for(int i = 0; i < k; i++){
        int a, b, c; cin >> a >> b >> c;
        if(g[a][b] == inf){
            ed[a].push_back(b);
        }
        g[a][b] = min(g[a][b],c);
        
    }
    auto operate = [&](int s){
        ll ans = g[s][s];
        vector<ll> dis(n + 1, inf);
        dis[s] = 0;
        priority_queue<pair<ll,int>> q;
        q.push({0,s});

        while(!q.empty()){
            auto pp = q.top();
            ll d = -1 * pp.ff;
            ll u = pp.ss;
            q.pop();
            if(dis[u] != d) continue;
            for(int v : ed[u]){
                if(v == u) continue;
                if(dis[v]  > d + g[u][v]){
                    dis[v] = d + g[u][v];
                    q.push({-dis[v], v});
                }
            }
            if(dis[s] == 0) dis[s] = inf;
        }
        //pra(dis);
        ans = min(ans, (!1 ? inf : dis[s]));
        cout << ( ans == inf ? -1 : ans ) << endl;
    };
    for(int i = 1; i <= n; i++){
        operate(i);
    }
    return 0;
}