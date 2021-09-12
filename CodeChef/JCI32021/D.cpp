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


vector<vector<int>> g(1005);
vector<int> dep(1005);
int ans = 0;
int at = -1;
void dfs(int u, int p , int cur){
    dep[u] = cur;
    ans = max(ans, cur);
    
    for(int v : g[u]){
        if(v == p) continue;
        dfs(v, u, cur + 1);
    }
}
int main(){
    Shazam;
    int n, k; cin >> n >> k;
    for(int i = 0; i < n- 1; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    int mx = -1;
    for(int i = 1; i <= n; i++){
        mx = max(mx, dep[i]);
        if(mx == dep[i]){
            at = i;
        }
    }
    dfs(at, 0, 0);
    cout << max(0, ans - k) << endl;
    return 0;
}