/*
"Do I really belong in this game I ponder, I just wanna play my part."
- Guts over fear, Eminem
 */
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

vector<vector<pair<int,int>>> g;
static int comp = 0;
vector<int> vis;
void dfs(int u){
    vis[u] = 1;
    for(auto pp : g[u]){
        if(!vis[pp.ff]) 
            dfs(pp.ff);
    }
}

int main(){
    Shazam;
    int n, m;
    cin>>n>>m;
    g = vector<vector<pair<int,int>>>(n);
    vis = vector<int>(n);
    for(int i = 0; i < m; i++){
        int a,b,z; cin>>a>>b>>z;
        a--; b--;
        g[a].push_back({b,z});
        g[b].push_back({a,z});
    }
    for(int i = 0; i < n; i++){
        if(!vis.at(i))
            dfs(i), comp++;
    }
    cout<<comp<<endl;
    return 0;
}