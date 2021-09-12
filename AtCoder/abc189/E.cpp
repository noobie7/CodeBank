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

vector<vector<ll>> matmul(vector<vector<ll>> a, vector<vector<ll>> b ){
    vector<vector<ll>> res ( 3, vector<ll>(3));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}
vector<ll> flat( vector<ll> b, vector<vector<ll>> a){
    vector<ll> res(3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            res[i] += a[i][j] * b[j];
        }
    }
    return res;
}
int main(){
    Shazam;

    int n; cin >> n;
    vector<vector<ll>> points(n,  vector<ll> (3));
    for(int i = 0; i < n; i++){
        cin >> points[i][0] >> points[i][1];
        points[i][2] = 1;
    }
    
    int m; cin >> m;
    vector<vector<vector<ll>>> op;
    vector<vector<ll>> init(3, vector<ll> (3));
    init[0][0] = init[1][1] = init[2][2] = 1;
    op.push_back(init);
    for(int i = 0; i < m; i++){
        int t; cin >> t;
        ll p = 0;
        if(t > 2){
            cin >> p;
        }
        vector<vector<ll>> curr(3, vector<ll> (3));
        if(t == 1){
            curr[0][1] = 1;
            curr[1][0] = -1;
        }
        else if(t == 2){
            curr[0][1] = -1;
            curr[1][0] = 1;
        }
        else if(t == 3){
            curr[0][0] = -1;
            curr[0][2] = 2 * p;
            curr[1][1] = 1;
        }
        else{
            curr[1][1] = -1;
            curr[1][2] = 2 * p;
            curr[0][0] = 1;
        }
        curr[2][2] = 1;
        op.push_back(matmul( curr, op.back()));
    }
    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        auto res = flat( points[b - 1], op[a]);
        cout << res[0]  << " " << res[1] << endl;
    }
    
    return 0;
}