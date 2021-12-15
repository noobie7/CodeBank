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
        if(y & 1){
            res = res * x % mod;
        }
        y /= 2;
        x = x * x % mod;
    }
    return res;
}
ll binmodulo2(ll x, ll y){
    ll mod2 = mod - 1;
    x%=mod2;
    ll res = 1;
    while(y){
        if(y&1){
            res = res*x%mod2;
        }
        y/=2;
        x = x*x%mod2;
    }
    return res;
}

int main(){
    Shazam;
    ll n, k, m; 
    cin >> n >> k >> m;
    if(m % mod == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << binmodulo(m, binmodulo2(k, n)) << endl;
    return 0;
}