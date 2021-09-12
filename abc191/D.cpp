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
const double eps = 1e-9;
const double ep = 1e-5;

int main(){
    Shazam;
    long long a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    a *= 10000;
    b *= 10000;
    c *= 10000;
    auto ok = [&](long long x, long long k){
        return x * x <= k;
    };
    
    auto bs = [&](long long lo, long long hi, long long x){
        while(hi-lo > 1){
            long long mid = lo + (hi - lo)/2;
            if(ok(mid, x))
                lo = mid;
                
            else 
                hi = mid;
              
        }
        return lo;
      
    };
    auto calc = [&](long long y, long long x){
        return (x - a) * (x - a) + (y - b) * (y - b);
    };
    for(int i = (a - c) - 1; i <= (a + c) + 1; i++){
        long long  root = c * c - (i - a) * (i - a);
        root /= 10000;
        if(root <= 0) continue;
        long long up = (b + bs(0, root, root) ) / 10000;
        long long down = ((b - bs(0, root, root)) ) / 10000;
        
        ans += (up - down + 1) ;
    }
    cout << ans << endl;
    return 0;
}