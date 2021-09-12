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
    vector<int> a(n);
    get(a);
    vector<vector<int>> divs(n);
    for(int i = 0; i < n; i++){
        for(int x = 1; x * x <= a[i] && x <= (i + 1) ; x++){
            if(a[i] % x == 0){
                divs[i].push_back(x);
                if(x != a[i] / x){
                    if(a[i] / x <= (i + 1)){
                        divs[i].push_back(a[i]/x);
                    }
                }
            }
        }
        sort(divs[i].rbegin(), divs[i].rend());
        //can sort divs[i] here, but not sure.
    }

    auto add = [&](ll &a, ll b){
        a = (a%mod + b%mod)%mod;
    };

    vector<ll> dp(n + 1); // dp[i] - number of good subsequences of size i;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int divisor : divs[i]){
            add(dp[divisor], dp[divisor - 1]);
        }
    }
    for(int i = 2; i <= n; i++){
        add(dp[i], dp[i-1]);
    }
    cout << dp[n] << endl;
    return 0;
}