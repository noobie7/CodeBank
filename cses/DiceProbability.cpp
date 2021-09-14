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

long double dp[102][1000];

int main(){
    Shazam;
    int n; cin >> n;
    int a, b; cin >> a >> b;
    
    long double den = 1;
    for(int i = 0; i < n; i++) den *= 6;
    dp[0][0] = (long double)1/den;
    
    auto add = [&](long double &a, long double b){
        a = (a + b);
    };

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= b; j++){
            for(int f = 1; f <= 6; f++){
                add(dp[i][j + f], dp[i-1][j]);
            }
        }
    }
    long double ans = 0;
    for(int i = a; i <= b; i++) ans += dp[n][i];
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}