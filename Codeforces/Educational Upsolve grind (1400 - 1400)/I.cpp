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
    string s; cin >> s;
    int ans = inf;
    auto process = [&](int i, int len){
        string curr = s.substr(0, i);
        string proto = "";
        for(int j = 0; j < len / i; j++){
            proto += curr;
        }
        
        if(proto == s.substr(0, len) && len/i <= 2){
            ans = min(i + len/i - 1 + (n - len), ans);
        }
    };
    for(int len = n; len >= 1; len--){
        for(int i = 1; i * i <= len; i++){
            if(len % i == 0){
                process(i, len);
                process(len / i, len);
            }
        }
    }
    cout << ans << endl;
    return 0;
}