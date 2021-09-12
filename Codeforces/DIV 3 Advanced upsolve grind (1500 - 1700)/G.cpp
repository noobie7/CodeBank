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
vector<pair<int,int>> path;
void dfs(int u,int p, int dep){
    path.push_back({u,dep});
    for(int v : g[u]){
        if(v != p){
            dfs(v, u, dep+1);
        }
    }
}
int main(){
    Shazam;
    int n; cin >> n;
    int q; cin >> q;
    vector<int> p(n-1);
    get(p);
    for(int i = 0; i < n - 1; i++){
        g[p[i]].push_back(i+2);
    }
    dfs(1,0,0);
    vector<int> idx(n + 1, -1);
    
    for(int i = 0; i < n; i++){
        idx[path[i].ff] = i;
    }

    vector<vector<int>> overkill(n, vector<int> (32,n+1));
    for(int i = 0; i < n; i++){
        overkill[i][0] = path[i].ss;
    }
    for(int bit = 1; bit < 32 ; bit++){
        for(int i = 0 ; i <= n - (1 << bit); i++){
            overkill[i][bit] = min(overkill[i][bit- 1], overkill[i + (1 << (bit - 1))][bit - 1]);
        }
    }
    for(int i = 0; i < q; i++){
        int num, len;
        cin >> num >> len;
        if(len == 1){
            cout << num << endl; 
            continue;
        }
        int bit = 31 - __builtin_clz(len-1);
        int pos = idx[num];
        if(pos + len - 1 >= n){
            cout << -1 << endl;
            continue;
        }
        int mn = path[pos].ss;
        int got = min(overkill[pos + 1][bit], overkill[pos + len - (1 << bit)][bit]);
        if(got <= mn){
            cout << -1 << endl;
        }  
        else{
            cout << path[pos + len - 1].ff << endl;
        }
    }
    return 0;
}