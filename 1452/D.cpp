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
const int mod = 998244353;

ll binmodulo(ll x, ll y){
  x%=mod;
  if(!x) return 0;
  ll res = 1;
  while(y){
    if(y&1){
      res = res*x%mod;
    }
    y/=2;
    x = x*x%mod;
  }
  return res;
}

int main(){
    Shazam;
    ll n; cin >> n;
    ll a = 1;
    ll b = 0;
    for(int i = 0; i <= n - 2; i++){
        ll c = a;
        a = (a % mod  + b % mod) % mod;
        b = c;
    }
    ll res = 1;
    for(int i = 0; i < n; i++){
        res = res * 2 % mod;
    }
    cout << a * binmodulo(res , mod - 2) % mod << endl;
    return 0;
}