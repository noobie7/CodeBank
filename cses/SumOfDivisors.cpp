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

ll binmodulo(ll x, ll y){
    x%=mod;
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
const int MOD=1000000007;
long long int inverse(long long int i){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
int main(){
    Shazam;
    ll n; cin >> n;
    auto add = [&](ll &a, ll b){
        a = (a%mod + b%mod)%mod;
    };
    auto sub = [&](ll &a, ll b){
        a = (a % mod - (b % mod) + mod)%mod;
    };
    ll ans = 0;
    for(ll i = 1; i * i <= n; i++){
        add(ans, ((n/i) * i) % mod);
    }
    ll l = (ll)sqrt(n);
    for(ll i = sqrt(n); i >= 1; i--){
        ll r = n / i;
        ll sum = 0;
        add(sum , ((((r % mod ) * ((r + 1) % mod)) % mod )* binmodulo(2, mod - 2)) % mod);
        assert(sum % mod == sum);
        sub(sum , ((((l % mod ) * ((l + 1) % mod)) % mod )* binmodulo(2, mod - 2)) % mod);
        assert(sum % mod == sum);
        sum = ((sum % mod) * (i % mod)) % mod;
        assert(sum % mod == sum);
        l = r;
        add(ans, sum);
    }
    cout << ans << endl;
    return 0;
}