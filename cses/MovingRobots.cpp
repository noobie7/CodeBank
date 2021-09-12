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
    int k; cin >> k;
    vector<int> dr = {0, 0, -1, 1}, dc = {-1, 1, 0, 0};

    long double dp[k+1][8][8] = {}, ans[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            ans[i][j] = 1;
        }
    }

    auto ok = [&](int i, int j){
        if(i < 0 || j < 0 || i > 7 || j > 7) return false;
        return true;
    };

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            for(int move = 0; move <= k; move++){
                for(int x = 0; x < 8; x++){
                    for(int y = 0; y < 8; y++){
                        dp[move][x][y] = 0;
                    }
                }
            }
            dp[0][i][j] = 1;
            for(int move = 0; move < k; move++){
                for(int fx = 0; fx < 8; fx++){
                    for(int fy = 0; fy < 8; fy++){
                        long double tot = 0;
                        for(int d = 0; d < 4; d++){
                            int tx = fx + dr[d];
                            int ty = fy + dc[d];
                            if(ok(tx, ty)){
                                tot++;
                            }
                        }
                        for(int d = 0; d < 4; d++){
                            int tx = fx + dr[d];
                            int ty = fy + dc[d];
                            if(ok(tx, ty)){
                                dp[move+1][tx][ty] += dp[move][fx][fy]/tot;
                            }
                        }
                    }
                }
            }
            for(int x = 0; x < 8; x++){
                for(int y = 0; y < 8; y++){
                    ans[x][y] *= (1.0 - dp[k][x][y]);
                }
            }
        }
    }
    long double res = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            res += ans[i][j];
        }
    }
    cout << fixed << setprecision(6) << res << endl;

    return 0;
}