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
vector<vector<int>> g(1e6 + 5);
vector<int> subsize(1e6 + 5,-1);
vector<int> path;
int dfs(int u){
    int res = 1;
    for(int v : g[u]){
        if(subsize[v] == -1){
           res += dfs(v);
        }
        else{
            res += subsize[v];
        }
    }
    return subsize[u] = res;
}
void make_path(int u){
    path.push_back(u + 1);
    for(int v : g[u]){
        make_path(v);
    }
}
int main(){
    Shazam;
    int n; cin >> n; 
    vector<int> a(n);
    get(a);
    vector<int> b = a;
    sort(all(b));
    map<int, int> f, lastseenat;

    vector<int> recover(1e6 + 5);
    {
        int c = 0;
        for(int i : b){
            recover[c] = i;
            f[i] = c++;
        }
    }
    
    for(int i = 0 ; i < n; i++){
        if(lastseenat.find(a[i] - 1) != lastseenat.end()){
            int to = lastseenat[a[i] - 1];
            int from = i;
            g[from].clear();
            g[from].push_back(to);
        }
        lastseenat[a[i]] = i;
    }
    for(int i = 0; i < 1e6 + 5; i++){
        dfs(i);
    }
    int mx = *max_element(all(subsize));
    for(int i = 0 ;i < 1e6 + 5; i++){
        if(subsize[i] == mx){
            make_path(i);
            break;
        }
    }
    cout << path.size() << endl;
    reverse(all(path));
    pra(path);
    
    return 0;
}