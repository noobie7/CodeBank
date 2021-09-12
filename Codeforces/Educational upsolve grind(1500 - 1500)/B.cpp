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
#define iii pair<pair<int,int>,int>


int main(){
    Shazam;
    int n; cin >> n;
    vector<array<int,3>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i + 1;
    }
    auto sorter = [&](array<int,3> &a , array<int,3> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    };
    sort(all(a), sorter);
    int mx = a[0][1];
    int at = a[0][2];
    for(int i = 1; i < n; i++){
        if(a[i][1] <= mx){
            cout << a[i][2] << " "  << at << endl;
            return 0;
        }
        if(mx < a[i][1]){
            mx = a[i][1];
            at = a[i][2];
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}