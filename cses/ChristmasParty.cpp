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

vector<ll> fac;
vector<ll> ifac;

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
    vector<ll> a(n+1,1);
    vector<ll> ia(n+1,1);

    for(int i = 0; i <= n; i++){
        if(i)
            a[i] = a[i-1] * i % mod;    
        ia[i] = binmodulo(a[i], mod - 2);
    }
    auto sub = [&](ll &a, ll b){
        a = (a%mod - b%mod + mod)%mod;
    };

    auto add = [&](ll &a, ll b){
        a = (a%mod + b%mod)%mod;
    };

    auto NcR = [&](ll n, ll r){
        return (a[n] * ia[r]) % mod;
    };
    ll ans = 0;
    for(int i = 1; i <=n; i++){
        if(i & 1)
            add(ans, (NcR(n, i) ) % mod );
        else
            sub(ans, (NcR(n, i) ) % mod );
    }
    sub(a[n], ans);
    cout << a[n] << endl;
    return 0;
}