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
vector<vector<int>> g(3e5 + 5);
vector<int> color(3e5 + 5);
int ans = 0;
int blue = 0;
int red = 0;
int n;
pair<int,int> dfs(int u, int p){
    pair<int,int> res; //{blue, red}
    if(color[u] == 1) res.ff = 1;
    if(color[u] == 2) res.ss = 1;
    for(int v : g[u]){
        if(v == p) continue;
        auto fromSon = dfs(v, u);
        res.ss += fromSon.ss;
        res.ff += fromSon.ff;
    }
    ans += ((res.ff == blue && res.ss == 0) || (res.ff == 0 && res.ss == red));
    return res;
}


int main(){
    Shazam;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> color[i];
        if(color[i] == 1) blue++;
        if(color[i] == 2) red++;
    }
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }    
    dfs(0,-1);
    cout << ans << endl;
    return 0;
}