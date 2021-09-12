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
#define Y cout << "YES" << endl; return 0;
#define F cout << "NO" << endl; 


int main(){
    Shazam;
    vector<int> c(12);
    // x1 y1 x2 y2 x3 y3 x4 y4 x5 y5 x6 y6
    //  0  1  2  3  4  5  6  7  8  9 10 11
    for(int &i : c){
        cin >> i;
        i *= 2;
    }
    auto ok = [&](int x, int y){
        return (x < c[4] || c[6] < x || y < c[5] || c[7] < y) && (x < c[8] || c[10] < x || y < c[9] || c[11] < y);
    };
    for(int i = c[0]; i <= c[2]; i++){
        if(ok(i, c[1])){Y}
        if(ok(i, c[3])){Y}
    }
    for(int i = c[1]; i <= c[3]; i++){
        if(ok(c[0], i)){Y}
        if(ok(c[2], i)){Y}
    }
    F
    return 0;
}