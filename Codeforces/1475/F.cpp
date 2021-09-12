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
        vector<vector<int>> a(n , vector<int> (n)), b(n, vector<int>(n));
        string s; 
        for(int i = 0; i < n; i++){
            cin >> s;
            for(int j = 0; j < n; j++){
                a[i][j] = (int)s[j] - '0';
            }
        }
        for(int i = 0; i < n; i++){
            cin >> s;
            for(int j = 0; j < n; j++){
                b[i][j] = (int)s[j] - '0';
            }
        }
        auto check = [&](){
            for(int j = 0; j < n; j++){
                if(a[0][j] ^ b[0][j]){
                    for(int i = 0; i < n; i++){
                        a[i][j] ^= 1;
                    }
                }
            }
            for(int i = 1; i < n; i++){
                int doit = a[i][0] ^ b[i][0];
                for(int j = 0; j < n; j++){
                    if(a[i][j] ^ b[i][j] ^ doit) return 0;
                }
            }
            return 1;
        };
        for(int i = 0; i < 2; i++){
            if(check()){
                cout << "YES" << endl;
                goto here;
            }
            for(int j = 0; j < n; j++){
                a[0][j] ^= 1;
            }
        }
        cout << "NO" << endl;
        here :;
    }
    return 0;
}