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
        vector<pair<ll, int>> a(n);
        int idx = 0;
        ll tot = 0;
        for(auto &pp : a){
            cin >> pp.ff;
            tot += pp.ff;
            pp.ss = 1 + idx++;
        }
        sort(a.begin(), a.end());
        if(a.front().ff == a.back().ff){
            cout << n << endl;
            for(int i = 1; i <= n; i++){
                cout << i << " ";
            }
            cout << endl;
            continue;
        }
        ll curr = 0;
        vector<int> ans;
        for(int i = n - 1; i >= 0; i--){
            curr += a[i].ff;
            if(tot - curr < a[i].ff){
                for(int j = i; j < n; j++){
                    ans.push_back(a[j].ss);
                }
                break;
            }
            
        }
        
        
       
        sort(all(ans));
        cout << ans.size() << endl;
        pra(ans);
    }
    return 0;
}