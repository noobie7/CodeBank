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
    test(){
        int n; cin >> n;
        vector<int> a(n);
        get(a);
        vector<int> pref(n + 1, INT_MIN), suff(n + 1, INT_MIN);
        for(int i = 1; i < n + 1; i++){
            pref[i] = max(pref[i-1], a[i-1]);
        }
        for(int i = n-1; i >= 0; i--){
            suff[i] = max(suff[i + 1], a[i]);
        }
        vector<vector<int>> rmq(n, vector<int> (32));
        for(int i = 0; i < n; i++)
                rmq[i][0] = a[i];
  
        for(int pw = 1; pw < 32; pw++){
            for(int i = 0; i <= n - (1 << pw); i++){
                rmq[i][pw] = min(rmq[i][pw - 1], rmq[i + (1 << (pw - 1))][pw - 1]);
            }
        }
        for(int i = n - 1; i >= 0; i--){
            int val = suff[i];
            int lo = (lower_bound(pref.begin(), pref.begin() + i, val) - pref.begin());
            int hi = (lower_bound(pref.begin(), pref.begin() + i, val + 1) - pref.begin());
            if(lo >= hi) continue;
            auto ok = [&](int a, int b){
                int len = b - a;
                int bit = (len == 0 ? -1 : 31 - __builtin_clz(len));
                return min(rmq[a][bit], rmq[b - (1 << bit)][bit]) <= val;
            };
            while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(ok(mid, i)){
                    lo = mid;
                }
                else{
                    hi = mid;
                }
            }
            int len = i - lo;
            int bit = (len == 0 ? -1 : 31 - __builtin_clz(len));
            if(min(rmq[lo][bit], rmq[i - (1 << bit)][bit]) == val){
                cout << "YES" << endl;
                cout << lo << " " << i - lo << " " << n - i << endl;
                goto here;
            }
        }
        cout << "NO" << endl;
        here :;
    }
    return 0;
}