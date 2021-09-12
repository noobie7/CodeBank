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



int main(){
    Shazam;
    
    ll n = 2 * 2 * 2 * 2 * 2 * 3 * 3 * 3 * 3 * 3 * 6 * 6 * 15 * 15 * 18LL
     * 134* 13412 ;
    ll ans = 1;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            if((ll)sqrt(i) * (ll)sqrt(i) == i){
                cout << i << endl;
                ans += i;
                ans %= mod;
            }
            if(n / i != i){
               if((ll)sqrt(n/i) * (ll)sqrt(n/i) == n/i){
                cout << n/i << endl;
                ans += n/i;
                ans %= mod;
                } 
            }
        }
    }
    cout << ans << endl;
    return 0;
}