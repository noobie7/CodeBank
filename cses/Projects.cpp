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
    vector<array<ll,3>> a(n);
    map<int,int> f;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i][1] >> a[i][0] >> a[i][2];
        a[i][0]++;
        f[a[i][1]], f[a[i][0]];
    }
    int c = 0;
    for(auto &pp : f){
        pp.ss = c++;
    }
    auto max_self = [&](ll &x, ll y){
        x = max(x , y);
    };
    vector<vector<array<ll,2>>> end(c);
    for(int i = 0; i < n; i++){
        end[f[a[i][0]]].push_back({f[a[i][1]], a[i][2]});
    }
    vector<ll> dp(c + 1);
    for(int i = 0; i < c; i++){
        if(i)
            dp[i] = dp[i-1];
        for(auto pp : end[i]){
            max_self(dp[i], dp[pp[0]] + pp[1]);
        } 
    }

    cout << dp[c-1] << endl;
    return 0;
}