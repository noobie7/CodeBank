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
vector<vector<int>> g(2e5 + 5);
vector<pair<int,int>> edges;
vector<int> color(2e5 + 5, -1);
int bipartite = 1;

void dfs(int u, int c){
    color[u] = c;
    for(int v : g[u]){
        if(color[v] == color[u]){
            bipartite = 0;
            return;
        }
        if(color[v] == -1)
            dfs(v, c ^ 1);
    }
}


int main(){
    Shazam;
    int n; cin >> n;
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back({a,b});
    }
    dfs(0,0);
    if(!bipartite){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < m; i++){
        cout << (int)(color[edges[i].ff] < color[edges[i].ss]);
    }
    cout << endl;
    return 0;
}