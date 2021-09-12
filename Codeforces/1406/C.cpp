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
const int nag = 1e5 + 5;

int mn = nag;
int cent1 = 0;
int cent2 = 0;
int s;
int n;

vector<vector<int>> g(nag);
vector<int> sz(nag);
vector<int> par(nag);

void dfs(int u, int p = -1){
    sz[u] = 1;
    par[u] = p;
    int mx = 0;
    for(int v : g[u]){
        if(v == p) continue;    
        dfs(v, u);
        sz[u] += sz[v];
        mx = max(mx, sz[v]);
    }
    mx = max(mx, n - sz[u]);
    if( mx < mn ){
        mn = mx;
        cent1 = u;
        cent2 = 0;
    }
    else if(mx == mn){
        cent2 = u;
    }
}

void dfs2(int u, int p){
    if(g[u].size() == 1){
        s = u;
        return;
    }
    for(int y : g[u]){
        if(y == p) continue;
        dfs2(y, u);
    }
}

int main(){
    Shazam;
    test(){
        cin >> n;
        cent1 = 0;
        cent2 = 0; 
        mn = nag;
        for(auto &v : g){
            v.clear();
        } 
        sz.clear();
        par.clear();

        for(int i = 1; i < n; i++){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1,0);
        if(cent2 == 0){
            cout << 1 << " " << g[1][0] << endl;
            cout << 1 << " " << g[1][0] << endl;
            continue;
        }
        if(par[cent1] != cent2) swap(cent1, cent2);
        dfs2(cent1, cent2);
        cout << s << " " << par[s] << endl;
        cout << s << " " << cent2 << endl;
    }
    return 0;
}