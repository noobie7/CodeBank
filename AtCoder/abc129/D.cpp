/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
 */
#include<bits/stdc++.h>
using namespace std;
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
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

vector<vector<int>> vis;
vector<string> g;
int ans = 0;
int n,m;
vector<int> xdir = {0,0,-1,1};
vector<int> ydir = {1,-1,0,0};
bool legal(int x, int y){
    if(x<0||y<0||x>=n||y>=m||g[x][y]=='#') return false;
    return true; 
}

void dfs(int i, int j, int &comp){
    vis[i][j] = 1;
    comp++;
    ans = max(ans, comp);
    for(int k = 0; k < 4; k++){
        int x = i + xdir[k];
        int y = j + ydir[k];
        if(legal(x,y)&&!vis[x][y])
            dfs(x,y, comp);
    }
}

int main(){
    Shazam;
    cin>>n>>m;
    g = vector<string>(n);
    for(string &s : g) cin>>s;
    vector<vector<int>> top(n,vector<int> (m)), bot(n,vector<int> (m)), left(n,vector<int> (m)), right(n,vector<int> (m));
    for(int i = 0 ; i < n; i++){
        int last = -1;
        for(int j = 0; j < m; j++){
            if(g[i][j]=='#') last = j;
            left[i][j] = (j-last);
        }
    }
    for(int i = 0 ; i < n; i++){
        int last = m;
        for(int j = m-1; j >=0; j--){
            if(g[i][j]=='#') last = j;
            right[i][j] = (last-j);
        }
    }
    for(int i = 0 ; i < m; i++){
        int last = -1;
        for(int j = 0; j < n; j++){
            if(g[j][i]=='#') last = j;
            top[j][i] = (j-last);
        }
    }
    for(int i = 0 ; i < m; i++){
        int last = n;
        for(int j = n-1; j >=0; j--){
            if(g[j][i]=='#') last = j;
            bot[j][i] = (last-j);
        }
    }
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            ans = max(ans, left[i][j] + bot[i][j] + right[i][j] + top[i][j] - 3);
        }
    }
    cout<<ans<<endl;
    return 0;
}