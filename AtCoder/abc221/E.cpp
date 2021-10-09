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
const int mod = 998244353;

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

struct BIT{
    int N;
    vector<ll> bit;
    BIT(int n):N(n){
        bit.resize(n + 1, 0);
    }
    void addition(ll &a, ll b){
        a = (a%mod + b%mod)%mod;
    }

    void add(int x, ll a){
        x++;
        for(x; x <= N; x += (x & (-x))) 
            addition(bit[x], a);
    }

    ll get_sum(int x){
        x++;
        ll ans = 0;
        for(x; x > 0 ; x -= (x &(-x)))
            addition(ans, bit[x]);
        return ans;
    }

};

int comp(vector<int> &A){
    map<int,int> f;
    int sz = 0;
    for(int i : A) f[i] = 0;
    for(auto &pp : f) pp.ss = sz++;
    for(int &i : A) i = f[i];
    return sz;
}

int main(){
    Shazam;
    const ll div = binmodulo(2, mod - 2);
    int N; cin >> N;
    vector<int> a(N);
    get(a);
    int n = comp(a);
    BIT bit(n);
    ll ans = 0;
    for(int i = 0; i < N ; i++){
        ans += (bit.get_sum(a[i]) * (binmodulo(2, i)));
        ans %= mod;
        bit.add(a[i], binmodulo(div, i + 1));
    }
    cout << ans << endl;
    return 0;
}