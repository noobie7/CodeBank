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
        vector<string> a(n); get(a);
        vector<int> ans(10);
        vector<int> mxr(10), mxc(10), mnr(10, n + 100), mnc(10, n + 100);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x = a[i][j] - '0';
                mxc[x] = max(mxc[x], j);
                mnc[x] = min(mnc[x], j);
                mxr[x] = max(mxr[x], i);
                mnr[x] = min(mnr[x], i);
            }
        }
        auto max_self = [&](int &a, int b){
            a = max(a, b);
        };
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x = a[i][j] - '0';
                max_self(ans[x] , max(j, n - 1 - j) * max(mxr[x] - i, i - mnr[x]));
                max_self(ans[x] , max(i, n - 1 - i) * max(mxc[x] - j, j - mnc[x]));
            }
        }
        pra(ans);
    }
    return 0;
}