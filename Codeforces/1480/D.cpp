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
    vector<int> a(n+1);
    vector<vector<int>> pos(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    
    int la = 0;
    int lb = 0;
    int ans = 0;
    auto nxt = [&](int i){
        int val = a[i];
        int ps = upper_bound(all(pos[val]), i) - pos[val].begin();
        if(ps == pos[val].size()) return n + 1;
        return pos[val][ps];
    };
    for(int i = 1; i <= n; i++){
        if(a[i] == a[lb]){
            ans += (a[i] != a[la]);
            la = i;
        }
        else if(a[i] == a[la]){
            ans += (a[i] != a[lb]);
            lb = i;
        }
        else if(nxt(la) < nxt(lb)){
            ans += (a[i] != a[la]);
            la = i;
        }
        else{
            ans += (a[i] != a[lb]);
            lb = i;
        }
    }
    cout << ans << endl;
    return 0;
}