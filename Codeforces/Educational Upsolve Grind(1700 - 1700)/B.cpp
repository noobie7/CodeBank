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

int n, m, q; 
int val;
vector<vector<char>> grid(1005, vector<char> (1005));
vector<vector<int>> vis(1005, vector<int> (1005));
vector<vector<int>> ans(1005, vector<int> (1005,-1));
set<pair<int,int>> was_here;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {-1, 1, 0, 0};
bool is_safe(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.' && !vis[i][j]);
}
bool is_painting(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '*');
}

void dfs(int x, int y){
    vis[x][y] = 1;
    was_here.insert({x, y});
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_safe(nx, ny)){
            dfs(nx , ny);
        }
        if(is_painting(nx, ny)){ 
            val++;
        }
    }
}

int main(){
    Shazam;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        if(ans[x][y] == -1){
            was_here.clear();
            val = 0;
            dfs(x, y);
            for(auto pp : was_here){
                ans[pp.ff][pp.ss] = val;
            }
            cout << val << endl;
        }
        else{
            cout << ans[x][y] << endl;
        }
    }
    return 0;
}