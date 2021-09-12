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
    int n; cin >> n;
    int m; cin >> m;
    vector<string> s(n);
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<array<int,3>> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '.') continue;
            int left = 0, right = 0, top = 0, bot = 0;
            for(int x = j + 1; x < m; x++){if(s[i][x] != '*') break; right++; a[i][x]++; }
            for(int y = i + 1; y < n; y++){if(s[y][j] != '*') break; bot++; a[y][j]++;}
            for(int x = j - 1; x >= 0; x--){if(s[i][x] != '*') break; left++; a[i][x]++; }
            for(int y = i - 1; y >= 0; y--){if(s[y][j] != '*') break; top++; a[y][j]++; }
            int sz = min({right, left, top, bot});
            if(sz)
                ans.push_back({i+1, j+1, sz});
        }
    }
    for(int i = 0; i < ans.size(); i++){
        int x = ans[i][0] - 1;
        int y = ans[i][1] - 1;
        int len = ans[i][2];
        s[x][y] = '.';
        for(int i = x + 1; i <= x + len; i++) s[i][y] = '.';
        for(int i = x - 1; i >= x - len; i--) s[i][y] = '.';
        for(int j = y + 1; j <= y + len; j++) s[x][j] = '.';
        for(int j = y - 1; j >= y - len; j--) s[x][j] = '.';
    }
    for(int i = 0; i < n; i++){
        if(count(all(s[i]), '*')){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        for(int j : ans[i]){
            cout << j << " ";
        }
        cout << endl;
    }
   
    return 0;
}