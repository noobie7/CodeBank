/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
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
const int mod = 998244353;
vector<ll> fac;
vector<ll> ifac;

ll binmodulo(ll x, ll y){
    
    ll res = 1;
    while(y){
        if(y&1){
            res = res*x%mod;
        }
        y>>=1;
        x = x*x%mod;
    }
    return res;
}

void precompute(int n){
    fac.resize(n+1,1);
    ifac.resize(n+1,1);
    for(int i =1; i <=n; i++){
        fac[i] = i*fac[i-1]%mod;
    }
    ifac[n] = binmodulo(fac[n], mod-2);
    for(int i = n-1; i>0; i--){
        ifac[i] = (i+1)*ifac[i+1]%mod;
    }
}

ll ncr(ll n, ll r){
    if(r==0) return 1;
    return fac[n]*ifac[n-r]%mod*ifac[r]%mod;
}

int main(){
    Shazam;
    ll n,m,k; 
    cin>>n>>m>>k;
    precompute(4e5 + 10);
    auto add = [&](ll &a, ll b){
        a = (a%mod + b%mod)%mod;
    };
    ll ans = 0;
    for(int i = 0 ; i <= k ; i++){
        add(ans, m*ncr(n-1,i)%mod*binmodulo(m-1,n-1-i)%mod);
    }
    cout<<ans<<endl;
    return 0;
}