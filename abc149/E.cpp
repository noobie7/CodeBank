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
    int n; cin >> n;
    ll m; cin >> m;
    vector<ll> a(n);
    get(a);
    sort(a.rbegin(), a.rend());
    vector<ll> pref(n + 1);  // pref[i] tells you the pref of top i elements
    vector<ll> cnt(1e5 + 2); // cnt[i] tells you how many numbers in the array are greater or equal to i;
    for(int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + a[i];
        cnt[a[i]]++;        
    }
    for(int i = 1e5 + 4; i > 0; i--){
        cnt[i - 1] += cnt[i]; 
    }

    auto ok = [&]( ll x){
        ll count = 0;
        for(ll  i : a){
            int t = max(0LL,min(x - i, (ll)1e5 + 1));
            count += cnt[t];
        }

        return count >= m;
    };
    ll lo = 0;
    ll hi = 2e5 + 2;

    while(hi-lo > 1){
        ll mid = lo + (hi - lo)/2;                                                                                                                                                                                                                                                                                                                                                        
        if(ok(mid))
            lo = mid;
            //hi = mid;
        else 
            hi = mid;
            //lo = mid;
    }

    ll sum = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int k = max(0LL, min(hi- a[i], (ll)(1e5 + 5)));
        int res = cnt[k];
        sum += res;
        ans += (a[i] * res  + pref[res]);
    }
    ans += lo * (m - sum);
    cout << ans << endl;
    return 0;
    
}