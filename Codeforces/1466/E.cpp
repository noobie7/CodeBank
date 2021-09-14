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

// i != j,  j != k , k != i -> (a[i] & a[j]) * ( a[j] | a[k])   // contribution should be counted thrice
// i == j , j != k    -> ans += a[i] * (a[j] | a[k])            // contribution should be counted twice
// i != j , j == k    -> ans += (a[i] & a[j]) * a[j]            // contribution should be counted twice
// i == j , j == k    -> ans += (a[i] * a[i])                   // contribution should be counted once
int main(){
    Shazam;
    test(){
        int n;
        cin >> n;
        vector<ll> a(n);
        get(a);
        ll ans = 0;
        auto add = [&](ll &a, ll b){
            a = (a + b)%mod;
        };
        vector<int> cnt(61);
        for(ll i : a){
            for(int bit = 0; bit < 61; bit++){
                cnt[bit] += ((i & (1LL << bit)) > 0);
            }
        }
        for(int i = 0; i < n; i++){
            ll orval = 0;
            ll andval = 0;
            for(int bit = 0; bit < 61; bit++){
                if(a[i] & (1LL << bit)){
                    andval += (1LL << bit) % mod * cnt[bit];
                    orval  += (1LL << bit) % mod * n;
                }
                else{
                    orval  += (1LL << bit) % mod * cnt[bit];
                }
            } 
            andval %= mod;
            orval  %= mod;
            add(ans, andval * orval % mod); 
        }
        cout << ans << endl;
    }
    return 0;
}