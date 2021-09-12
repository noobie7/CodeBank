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
    vector<ll> a(n); get(a);
    // vector<ll> dp(n+1, INF );
    // dp[0] = -INF;
    // for(int i = 0; i < n; i++){
    //     int j = lower_bound(all(dp), a[i]+1) - dp.begin();
    //     if(dp[j - 1] <=a[i] && dp[j] > a[i])
    //         dp[j] = a[i];
    // }
    // int ans = 0;
    // for(int i = 0; i <=n; i++){
    //     if(dp[i] != INF){ 
    //         ans = i;
    //     }
    // }
    // cout << ans << endl;
    vector<ll> l;
    for(ll i : a){
        int pos = upper_bound(all(l), i) - l.begin();
        if(pos < l.size()){
            l[pos] = i;
        }
        else{
            l.push_back(i);
        }
    }
    cout << l.size() << endl;
    return 0;
}