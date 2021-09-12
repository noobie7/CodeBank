/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
*/
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
const int mod1 = 1e9 + 7;

vector<ll> fac,ifac;
//ll binexpomodulo(ll x, ll y){ll res =1;x%=mod;if(!x)return 0;while(y){if(y&1){mul(res, x);}mul(x,x);y>>=1;}return res;}
ll binmodulo(ll x, ll y){
    x%=mod1;
    if(x==0){
        return 0;
    }
    
    ll res = 1;
    while(y){
        if(y&1){
            res = res*x%mod1;
        }
        y/=2;
        x = x*x%mod1;
    }
    return res;
}
void precompute(ll n){
    fac.resize(n+1,1);
    ifac.resize(n+1);
    for(int i =1; i < n+1; i++){
        fac[i] = i*fac[i-1]%mod1;
    }
    ifac[n] = binmodulo(fac[n], mod1-2);
    for(int i = n-1; i >=0; i--){
        ifac[i] = (i+1)*ifac[i+1]%mod1;
    }
}
ll ncr(ll n, ll r){
    return fac[n]*ifac[n-r]%mod1*ifac[r]%mod1;
}
//vector<ll> fac, ifac; void precompute(ll n){fac.resize(n+1,1);ifac.resize(n+1);for(ll i = 2; i<=n;i++){	fac[i] = (fac[i-1]*i)%mod;}ifac[n] = binexpomodulo(fac[n],mod-2);for(ll i = n-1; i>=0; i--)ifac[i] = (ifac[i+1]*(i+1))%mod;}ll nCr(ll n, ll r){return fac[n]*(ifac[n-r])%mod * (ifac[r])%mod;}
int main(){
    Shazam;
    ll s; cin>>s;
    precompute(5*s+100);
    if(s < 3){
        cout<<0<<endl;
        return 0;
    }
    ll ans = 0;
    auto add = [&](ll &a, ll b){
        a+=b;
        while(a>=mod1){
            a-=mod1;
        }
    };
    for(ll tot = 1; tot <= s/3; tot++ ){
        add(ans, ncr(s-3*tot + tot - 1, tot-1));
    }
    cout<<ans<<endl;
    return 0;
}