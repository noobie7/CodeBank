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
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define get(a) for(auto &i : a)  cin>>i;
#define pra(a) for(auto i : a) cout<< i <<" ";	cout<<endl;
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

int main(){
    Shazam;
    vector<ll> fac(2e5 + 5);
    fac[1] = 1;
    for(ll i = 2; i <= 2e5 + 4; i++){
        fac[i] = (i * fac[i - 1]) % mod;
    }
    test(){
        int n; cin >> n;
        cout << (fac[2 * n] * binmodulo(2, mod - 2) % mod) << endl;
    }
    return 0;
}