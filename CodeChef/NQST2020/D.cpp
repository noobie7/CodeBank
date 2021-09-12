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
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        ll n, m; cin >> n >> m;
        ll a, d; cin >> a >> d;
        vector<ll> v(5);
        ll l = a, g = 0 ;
        for(int i = 0; i < 5; i++){
            v[i] = a + i * d;
        }
        ll ans = 0;
        ans += m / v[0] - (n - 1)/v[0];
        ans += m / v[1] - (n - 1)/v[1];
        ans += m / v[2] - (n - 1)/v[2];
        ans += m / v[3] - (n - 1)/v[3];
        ans += m / v[4] - (n - 1)/v[4];
        cout << ans << endl;
        for(int i = 0; i < 5; i++){
            for(int j = i + 1; j < 5; j++){
                ll lcm = v[i] * v[j] / __gcd(v[i], v[j]);
                ans -= m / lcm - (n - 1) / lcm;
            }
        }
        cout << ans << endl;
        for(int i = 0; i < 5; i++){
            for(int j = i + 1; j < 5; j++){
                ll lcm = v[i] * v[j] / __gcd(v[i], v[j]);
                for(int k = j + 1; k < 5; k++){
                    ll nl = lcm * v[k] / __gcd(lcm, v[k]);
                    ans += m / nl - (n - 1) / nl;
                }
            }
        }
        cout << ans << endl;
        for(int i = 0; i < 5; i++){
            for(int j = i + 1; j < 5; j++){
                ll lcm = v[i] * v[j] / __gcd(v[i], v[j]);
                for(int k = j + 1; k < 5; k++){
                    ll nl = lcm * v[k] / __gcd(lcm, v[k]);
                    for(int l = k + 1; l < 5; l++){
                        ll lm = nl * v[l] / __gcd(nl, v[l]);
                        ans -= m/lm - (n - 1)/ lm;
                    }
                }
            }
        }
        cout << ans << endl;
        ll an = v[0];
        for(int i = 1; i < 5; i++){
            an = an * v[i] / __gcd(v[i], an);
        }
        ans += m / an - (n - 1) / an;
        cout << ans << endl;
        cout << m - n + 1 - ans << endl;
    }
    return 0;
}