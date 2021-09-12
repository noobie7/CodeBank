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

vector<ll> total;
vector<vector<int>> g;
vector<ll> pending;

void dfs(int u, int p, ll curr){
    curr+=pending[u];
    total[u] = curr;
    for(int v : g[u]){
        if(v==p) continue;
        dfs(v,u,curr);
    }
}

int main(){
    Shazam;
    int n,q; cin>>n>>q;
    g.resize(n);
    total.resize(n);
    pending.resize(n);
    for(int i = 0 ; i < n-1; i++){
        int a,b; cin>>a>>b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < q; i++){
        ll p,x; cin>>p>>x;
        pending[p-1] +=x;
    }
    dfs(0,-1,0);
    pra(total);

    return 0;
}