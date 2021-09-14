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
const int mod = 998244353;



int main(){
    Shazam;
    int n; cin >> n;
    map<int,pair<int,int>> f;
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        if(f.find(k) != f.end()){
            f[k].ss = i;
        }
        else{
            f[k] = {i,i};
        }
    }
    int l = inf, r = -1;
    vector<pair<int,int>> ranges;
    set<int> leftend;
    for(auto pp : f){
        if(pp.ss.ss == pp.ss.ff) continue;
        l = min(l, pp.ss.ff);
        r = max(r, pp.ss.ss);
        ranges.push_back({pp.ss.ff, pp.ss.ss});
        leftend.insert(pp.ss.ff);
    }
    if(l == inf){
        ll ans = 1;
        for(int i = 0; i < n - 1; i++){
            ans = ans * 2 % mod;
        }
        cout << ans << endl;
        return 0;
    }
    sort(all(ranges));
    int between = 0;
    int m = ranges.size();
    int rightend = ranges.front().ss;
    leftend.erase(leftend.find(ranges.front().ff));
    for(int i = 1; i < m; i++){
        while(i < m && ranges[i].ff < rightend && leftend.size() > 0){
            leftend.erase(leftend.find(ranges[i].ff));
            rightend = max(rightend, ranges[i].ss);
            i++;
        }
        if(leftend.size()){
            between  += *leftend.begin() - rightend;
            leftend.erase(leftend.begin());
            rightend = ranges[i].ss;
        }
    }

    
    int lrem = max(0, l - 1);
    int rrem = max(0, n - r);
    ll ans = 1;
    for(int i = 0; i < lrem; i++){
        ans = ans * 2LL % mod;
    }
    for(int i = 0; i < rrem; i++){
        ans = ans * 2LL % mod;
    }
    for(int i = 0; i < between; i++){
        ans = ans * 2LL % mod;
    }
    cout << ans << endl;
    return 0;
}