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

vector<int> numleaves;
vector<vector<int>> g(1e5 + 5);

int dfs(int u, int p = -1){
    int res = 0;
    for(int v : g[u]){
        if( v == p ) continue;
        res += dfs(v,u);
    }
    res += (g[u].size() == 0);
    numleaves.push_back(res);
    return res;
}


int main(){
    Shazam;
    int n; cin >> n;
    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        g[p].push_back(i);
    }
    dfs(1);
    sort(all(numleaves));
    pra(numleaves);
    return 0;
}