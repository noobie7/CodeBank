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
const int mod = 998244353;

int x, y; 
vector<vector<int>> g(2e5 + 4);
vector<int> vis(2e5 + 4);

void dfs(int u){
    vis[u] = 1;
    x++;
    y += g[u].size();
    for(int v : g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    Shazam;
    int n, m; cin >> n >> m;
    ll ans = 1;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            x = 0;
            y = 0;
            dfs(i);
            if(y == 2 * x){
                ans = ans * 2 % mod;
            }
            else{
                ans = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
