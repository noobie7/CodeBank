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
const ll mod1 = 1e9 + 7;

ll binmodulo(ll x, ll y){
    x%=mod1;
    if(!x) return 0;
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
long power(long a,long b){return b?power(a*a%mod1,b/2)*(b%2?a:1)%mod1:1;}

int main(){
    Shazam;
    ll k,n; cin>>n>>k;
    ll ans = 0;

    auto add = [&](ll & a, ll b){
        a = (a%mod1 + b%mod1) % mod1;
    };

    vector<ll> cnt(k+1);
    for(ll i = k; i > 0; i--){
        cnt[i] = binmodulo(k/i, n);
        for(ll j = i+i; j <= k; j+=i) cnt[i] = (cnt[i]-cnt[j]+mod1)%mod1;
        add(ans, i*cnt[i]%mod1);
    }
    cout<<ans%mod1<<endl;


    return 0;
}
