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
        int curr = 1;
        vector<vector<int>> a(n,vector<int>(n));
        for(int d = 0; d <= n * 2; d += 2){
            for(int i = 0; i < n; i++){
                if(d - i < 0 || d - i >= n) continue;
                a[i][d - i] = curr++;
            }
        }

        for(int d = 1; d <= n * 2; d += 2){
            for(int i = 0; i < n; i++){
                if(d - i < 0 || d - i >= n) continue;
                a[i][d - i] = curr++;
            }
        }
        auto ok = [&](int i, int j){
            for(int dx = -1; dx < 2; dx++){
                for(int dy = -1; dy < 2; dy++){
                    if(dx * dy != 0) continue;
                    if(dx == 0 && dy == 0) continue;
                    if(i + dx < n && i + dx >= 0 && j + dy >= 0 && j + dy < n){
                        if(abs(a[i + dx][j + dy] - a[i][j]) == 1){
                            return 0;
                        }
                    }
                }
            }
            return 1;
        };
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!ok(i, j)){
                    goto here;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        continue;
        here :;
        cout << -1 << endl;
    }
    return 0;
}