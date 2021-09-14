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
//#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n, m;
    cin >> n >> m;
    vector<ll> r(n), c(n);
    get(r);
    get(c);
    vector<vector<ll>> q(m, vector<ll> (4));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 4; j++){
            cin >> q[i][j];
        }
    }
    vector<pair<int,int>> pr(n+1), pc(n+1);
    for(int i = 0; i < n; i++){
        pr[i+1].ff = pr[i].ff + (r[i] & 1 ^ 1);
        pr[i+1].ss = pr[i].ss + (r[i] & 1);
        pc[i+1].ff = pc[i].ff + (c[i] & 1 ^ 1);
        pc[i+1].ss = pc[i].ss + (c[i] & 1);
    }
    for(int i = 0; i < m; i++){
        int a = q[i][0];
        int b = q[i][1];
        int x = q[i][2];
        int y = q[i][3];
        bool odd = (r[a-1] & 1);
        if(1){
            int lx = min(a,x);
            int hx = max(a,x);
            int ly = min(b,y);
            int hy = max(b,y);

            int ix = (odd)?(pr[hx].ss - pr[lx - 1].ss):(pr[hx].ff - pr[lx - 1].ff);
            int iy = (odd)?(pc[hy].ss - pc[ly - 1].ss):(pc[hy].ff - pc[ly - 1].ff);

            if(ix == (hx - lx + 1) && iy == (hy - ly + 1)){ cout << "YES" << endl; continue;}
        }
        cout << "NO" << endl;
    }
    return 0;
}