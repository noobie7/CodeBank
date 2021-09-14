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
#define pr(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pra(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = (int)1e9 + 7;
vector<ll> fac, ifac;
ll binmodulo(ll x, ll y){
    ll res = 1;
    x%=mod1;
    if(!x) return 1;
    while(y){
        if(y&1){
            res = res*x%mod1;
        }
        x = x*x%mod1;
        y>>=1;
    }
    return  res;
}

void precompute(int n){
    fac.resize(n+1,1);
    ifac.resize(n+1);
    for(ll i = 2; i <=n; i++){
        fac[i] = fac[i-1]*i%mod1;
    }
    ifac[n] = binmodulo(fac[n],mod1-2);
    for(ll i = n-1; i>=0; i--){
        ifac[i] = ifac[i+1]*(i+1)%mod1;
    }
}
ll npr(ll n, ll r){
    return fac[n]*ifac[n-r]%mod1;
}
ll ncr(ll n, ll r){
    return fac[n]*ifac[n-r]%mod1*ifac[r]%mod1;
}
int main(){
    Shazam;
    int n,m; cin>>n>>m;
    precompute(m);
    ll ans = 0;
    for(int i = 0; i<= n; i++){
        if(i&1){
            ans = (ans + mod1 - ncr(n,i)*npr(m,i)%mod1*npr(m-i, n-i)%mod1*npr(m-i,n-i)%mod1)%mod1;
        }
        else{
            ans = (ans + ncr(n,i)*npr(m,i)%mod1*npr(m-i, n-i)%mod1*npr(m-i,n-i)%mod1)%mod1;
        }
    }
    cout<<ans<<endl;
    return 0;
}