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
const ll INF = 1e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

ll d[200005][2][2];

int main(){
    Shazam;
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<pair<ll,ll>>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                d[i][j][k] = INF;
            }
        }
    }
    d[0][0][0] = 0;
    priority_queue<pair<ll, array<ll,3>>> q;
    q.push({0, {0,0,0}});
    //{dis, {node, min, max}}
    while(!q.empty()){
        auto tp = q.top();
        ll u  = tp.ss[0];
        ll mx = tp.ss[1];
        ll mn = tp.ss[2];
        q.pop();
        ll len = tp.ff;
        if(abs(len) != d[u][mx][mn]) continue;
        for(auto pp : g[u]){
            ll v = pp.ff;
            ll w = pp.ss;
            for(int i = 0; i <= 1 - mx; i++){
                for(int j = 0; j <= 1 - mn; j++){          
                    if(d[v][i | mx][mn | j] > d[u][mx][mn] + (1 - i + j) * w) {
                        d[v][i | mx][mn | j] = d[u][mx][mn] + (1 - i + j) * w;
                        q.push({-d[v][mx|i][mn|j] , {v, mx|i, mn|j}});
                    }
                    
                }
            }
        }
    }
    for(int i = 1; i < n; i++){
        cout << d[i][1][1] << " ";
    }
    cout << endl;
    return 0;
}
