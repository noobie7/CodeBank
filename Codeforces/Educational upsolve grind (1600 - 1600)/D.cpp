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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    get(a);
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++){
        p[i] = p[i - 1]  + a[i - 1];
    }
    int from = -1;
    auto ok = [&](int x){
        for(int i = x; i <=n ; i++){
            int cnt = x - (p[i] - p[i - x]); 
            if(cnt <= k){ 
                from = i;
                return 1;
            }
        }
        return 0;
    };
    
    auto bs = [&](int lo, int hi){
        while(hi-lo > 1){
            int mid = lo + (hi - lo)/2;
            if(ok(mid))
                lo = mid;
  
            else 
                hi = mid;
  
        }
        return lo;
 
    };
    
    int res = bs(0, n + 1);
    cout << res << endl;
    ok(res);

    for(int i = 0 ; i < n; i++){
        cout << (from - res <= i && i < from  ? 1 : a[i]) << " ";
    }
    cout << endl;
    return 0;
}