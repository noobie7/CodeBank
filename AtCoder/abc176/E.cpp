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
    int n, m; cin >> n >> m;
    vector<pair<int,int>> cntr(n), cntc(m);
    int k; cin >> k;
    for(int i =0 ; i < n; i++){
        cntr[i].ss = i;
    }
    for(int i = 0; i < m; i++){
        cntc[i].ss = i;
    }
    
    map<pair<int,int>, int> f;
    
    while(k--){
        int x, y; 
        cin >> x >> y;
        x--;
        y--;
        f[{x,y}]++;
        cntr[x].ff++;
        cntc[y].ff++;
    }
    sort(cntr.rbegin(), cntr.rend());
    sort(cntc.rbegin(), cntc.rend());
    ll ans = cntr.front().ff + cntc.front().ff - 1;
    vector<int> okr, okc;
    for(int i = 0; i < n; i++){
        if(cntr[i].ff == cntr.front().ff){
            okr.push_back(cntr[i].ss);
        }
        else{
            break;
        }
    }
    for(int i = 0; i < m; i++){
        if(cntc[i].ff == cntc.front().ff){
            okc.push_back(cntc[i].ss);
        }
        else{
            break;
        }
    }
    for(int i = 0; i < okr.size(); i++){
        for(int j = 0; j < okc.size(); j++){
            if(f.find({okr[i],okc[j]}) == f.end()){
                ans++;
                goto here;
            }
        }
    }
    here:
    cout << ans << endl;
    return 0;
}