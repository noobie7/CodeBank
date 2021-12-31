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
    if(r > n) 
        return 0;
    return fac[n]*ifac[n-r]%mod*ifac[r]%mod;
}

int main(){
    Shazam;
    precompute(4e5 + 1);
    ll n, m; cin >> n >> m;
    vector<int> a(n);
    get(a);
    ll ans = ncr(m, n) * fac[n] % mod;
    int x = 0;
    for(int i = 0; i < n; i++){
        x += (a[i] <= m);
    }
    if(m < n){
        cout << 0 << endl;
        return 0;
    }
    for(ll i = 1; i <= x; i++){
        ll val = ncr(x, i);
        val *= ncr(m - i, n - i);
        val %= mod;
        val *= fac[n - i];
        val %= mod;
        if(i & 1){
            ans -= val;
        }
        else{
            ans += val;
        }
        ans %= mod;
        ans += mod;
        ans %= mod;
    }
    cout << ans << endl; 
    return 0;
}