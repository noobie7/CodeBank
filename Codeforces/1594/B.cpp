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



int main(){
    Shazam;
    test(){
        ll n, k; cin >> n >> k;
        vector<int> power(32, 1);
        for(int i = 1; i < 32; i++){
            power[i] = power[i - 1] * n % mod;
        }
        ll ans = 0;
        for(int bit = 0; bit < 32; bit++){
            if(k & (1 << bit)){
                ans += power[bit];
                ans %= mod;
            }
        }
        cout << ans << endl;
    }
    return 0;
}