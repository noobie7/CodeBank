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
const int mod1 = 1e9 + 7;

ll ans = 0;
vector<int> a;
vector<int> vis;
vector<vector<int>> g;
void dfs(int u){
    ans += a[u];
    vis[u] = 1;
    for(int v : g[u]){
        if(!vis[v])
            dfs(v);
    }
}

int main(){
    Shazam;
    int n; cin >> n;
    a = vis = vector<int> (n);
    g = vector<vector<int>> (n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        int edges; 
        cin >> edges;
        for(int j = 0; j < edges; j++){
            int k; cin >> k;
            g[i].push_back(k - 1);
        }
    }
    dfs(n - 1);
    cout << ans << endl;
    return 0;
}