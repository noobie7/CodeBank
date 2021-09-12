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
        map<int,int> f;
        for(int i : a) f[i]++;
        map<int,int> s;
        for(auto pp : f){
            s[pp.ss]++;
        }
        int ans = 0;
        f = s;
        while(f.size() > 1 || (f.size() == 1 && f.begin() -> ss > 1)){
            ll mx = f.rbegin() -> ff;
            ll mn = f.begin() -> ff;
            f[mx]--;
            f[mn]--;
            if(f[mx] == 0) f.erase(mx);
            if(f[mn] == 0) f.erase(mn);
            if(mn - 1 > 0){
                f[mn - 1]++;
            }
            if(mx - 1 > 0){
                f[mx - 1]++;
            }
        }
        if(f.size()){
            ans = f.begin() -> ff;
        }
        cout << ans << endl;
        
    }
    return 0;
}