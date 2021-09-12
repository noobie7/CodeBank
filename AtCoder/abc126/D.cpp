/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
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
vector<int> ans;

void dfs(int u, int p, int c){
    ans[u] = c;
    for(auto pp : g[u]){
        if(pp.ff==p) continue;
        if(pp.ss&1)
            dfs(pp.ff,u,c^1);
        else 
            dfs(pp.ff,u,c);
    }
}

int main(){
    Shazam;
    int n; cin>>n;
    g.resize(n+1);
    ans.resize(n+1);
    for(int i =1 ; i < n; i++){
        int a,b,w; cin>>a>>b>>w;
        g[a].push_back({b,w%2});
        g[b].push_back({a,w%2});
    }
    dfs(1,0,0);
    for(int i = 1; i <=n; i++)
        cout<<ans[i]<<endl;
    return 0;
}