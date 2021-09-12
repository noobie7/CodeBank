/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
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

vector<vector<int>> g;
vector<int> vis;
int curr;
void dfs(int u, int &cnt){
    cnt++;
    vis[u] = true;
    for(int v : g[u]){
        if(!vis[v]){
            dfs(v, cnt);
        }
    }
}
int main(){
    Shazam;
    int n,m; cin>>n>>m;
    g = vector<vector<int>>(n+1);
    vis = vector<int> (n+1);
    for(int i = 0 ; i < m; i++){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <=n; i++){
        if(!vis[i]){
            curr = 0;
            dfs(i,curr);
            ans = max(ans, curr);
        }
    }
    cout<<ans<<endl;
    return 0;
}