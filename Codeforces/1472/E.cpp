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

#define ppp pair<int, pair<ll,ll>>
ppp a[200005];
ll ans[200005];
ll best_value_at[200005];
ll best_index_at[200005];
int n; 
int main(){
    Shazam;
    test(){
        cin >> n;
        for(int i = 0; i < n; i++){
            a[i].ff = i;
            cin >> a[i].ss.ff >> a[i].ss.ss;
            if(a[i].ss.ff > a[i].ss.ss){
                swap(a[i].ss.ss, a[i].ss.ff);
            }
        }
        auto sorter = [&](ppp &a, ppp &b){
            return a.ss.ff < b.ss.ff;
        };
        sort(a, a + n, sorter);
        ll best_index = -1;
        ll best_value = 2e9 + 5;
        int ptr = -1;
        for(int i = 0; i < n; i++){
            ans[a[i].ff] = -1;
            if(i > 0){
                if(a[i].ss.ff != a[i-1].ss.ff){
                    ptr = i - 1;
                }
                if(ptr >= 0){
                    if(a[i].ss.ss > best_value_at[ptr]){
                        ans[a[i].ff] = best_index_at[ptr];
                    }
                }
            }
            if(a[i].ss.ss < best_value){
                best_value = a[i].ss.ss;
                best_index = a[i].ff + 1;
            }
            best_value_at[i] = best_value;
            best_index_at[i] = best_index;
        }
        for(int i = 0 ;i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}