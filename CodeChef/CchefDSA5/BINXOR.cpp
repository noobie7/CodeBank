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

void precompute(int n){
    fac.resize(n+1,1);
    ifac.resize(n+1);
    for(int i =2; i <=n; i++){
        fac[i] = i*fac[i-1]%mod;
    }
    ifac[n] = binmodulo(fac[n], mod-2);
    for(int i = n-1; i>=0; i--){
        ifac[i] = (i+1)*ifac[i+1]%mod;
    }
}

ll ncr(ll n, ll r){
    return fac[n]*ifac[n-r]%mod*ifac[r]%mod;
}

int main(){
    Shazam;
    precompute(1e5 + 5);
    test(){
        int n; cin >> n;
        string a, b; 
        cin >> a >> b;
        ll x = count(all(a), '1');
        ll y = count(all(b), '1');
        ll mx = ((x + y >= n)? n - ((x + y - n)) : x + y);
        ll mn = abs(x - y);
        if(mn > mx) swap(mn, mx);
        auto add = [&](ll &a, ll b){
            a = (a%mod + b%mod)%mod;
        };
        ll ans = 0;
        for(ll i = mn; i <= mx; i += 2 ){
            add(ans, ncr(n , i));
        }
        cout << ans << endl;
    }
    return 0;
}