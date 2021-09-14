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
const int mod = 1e9 + 7;

int dim;
vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b){
    vector<vector<ll>> res(dim, vector<ll> (dim));
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            for(int k = 0; k < dim; k++){
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % mod ) % mod;
    
    }
        }
    }
    return res;
}

vector<vector<ll>> binmatexp(vector<vector<ll>> &a, ll n){
    if(n == 0){
        vector<vector<ll>> baseres(dim, vector<ll>(dim));
        for(int i = 0; i < dim; i++) baseres[i][i] = 1;
        return baseres;
    }
    vector<vector<ll>> res = binmatexp(a, n/2);
    res = mul(res,res);
    if(n & 1){
        res = mul(res, a);
    }
    return res;
}

int main(){
    Shazam;
    int n, m; cin >> n >> m;
    ll k; cin >> k;
    dim = n;
    vector<vector<ll>> g(n , vector<ll> (n)); 
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[a][b]++;
    }
    vector<vector<ll>> ans = binmatexp(g, k);
    cout << ans[0][n-1] << endl;
    return 0;
}