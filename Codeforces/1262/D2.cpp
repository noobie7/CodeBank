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
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    Shazam;
    int n; cin >> n;
    vector<int> a(n);
    vector<pair<int,int>> b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b.push_back({-a[i], i});
    }
    sort(all(b));

    int m; cin >> m;
    vector<pair<pair<int,int>, int>> q(m);
    for(int i = 0; i < m; i++){
        cin >> q[i].ff.ff >> q[i].ff.ss;
        q[i].ss = i;
    }
    sort(all(q));

    vector<int> ans(m);
    
    ordered_set pos;

    int len = 0;
    for(int i = 0; i < m; i++){
        while( len < q[i].ff.ff){
            pos.insert(b[len++].ss);
        }
        ans[q[i].ss] = a[*pos.find_by_order(q[i].ff.ss - 1)];
    }
    pra(ans);
    return 0;
}