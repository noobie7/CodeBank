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
        int n, q; cin >> n >> q;
        string s; cin >> s;
        int p[n][2], su[n][2];
        int one = 0, zer = 0;
        for(int i = 0; i < n; i++){
            p[i][0] = zer;
            p[i][1] = one;
            one += (s[i] == '1');
            zer += (s[i] == '0');
        }
        one = 0;
        zer = 0;
        for(int i = n - 1; i >= 0; i--){
            su[i][0] = zer;
            su[i][1] = one;
            one += (s[i] == '1');
            zer += (s[i] == '0');
        }
      
        while(q--){
            int l, r;
            cin >> l >> r;
            cout << (((p[l-1][(int)(s[l-1] - '0')] || su[r-1][(int)(s[r-1] - '0')] ))? "YES":"NO" )<< endl;
        }

    }
    return 0;
}