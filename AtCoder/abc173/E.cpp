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
    int n; cin >> n;
    int k; cin >> k;
    vector<ll> a(n);
    get(a);
    sort(all(a));
    int l = 0;
    int r = n-1;
    ll ans = 1;
    ll pm = 1;
    if(k & 1){
        ans *= a[r];
        r--;
        k--;
        if(ans < 0){
            pm = -1;
        }
    }
    while(k > 0){
        ll x = a[l] * a[l + 1];
        ll y = a[r] * a[r - 1];
        if(x * pm > y * pm){
            ans *= x % mod;
            ans %= mod;
            l += 2;
        }
        else{
            ans *= y % mod;
            ans %= mod;
            r -= 2;
        }
        k -= 2;
    }
    ans += mod;
    cout << ans % mod << endl;
    return 0;
}