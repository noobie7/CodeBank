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
const int nag = 2e5 + 5;


int main(){
    Shazam;
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    get(a);
    vector<int> cnt(nag);
    for(int i : a){
        cnt[i]++;
    }
    vector<int> t;
    auto ok = [&](int x){
        t.clear();
        for(int i = 0; i < nag; i++){
            int need = min(cnt[i] / x, k - (int)t.size());
            for(int j = 0; j < need; j++){
                t.push_back(i);
            }
        }
        return t.size() == k;
    };
    
    auto bs = [&](long long lo, long long hi){
        while(hi-lo > 1){
            long long mid = lo + (hi - lo)/2;
            if(ok(mid))
                lo = mid;
                // hi = mid;
            else 
                hi = mid;
                // lo = mid;
        }
        return lo;
        //return hi;
    };
    
    ok(bs(1, n+1));
    pra(t);
    return 0;
}