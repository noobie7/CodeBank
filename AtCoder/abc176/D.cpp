/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
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


int main(){
    Shazam;
    int n,m; cin>>n>>m;
    int sx,sy,ex,ey; 
    cin>>sx>>sy>>ex>>ey;
    sx--;
    sy--;
    ex--;
    ey--;
    vector<int> xdir = {1,0,-1,0};
    vector<int> ydir = {0,1,0,-1};
    vector<string> g(n);
    for(string &s : g)
        cin>>s;
    vector<vector<int>> dis(n, vector<int> (m, 1e7));
    auto legal = [&](int x, int y){
        if(x<0||y<0||x>=n||y>=m||g[x][y]=='#') return false;
        return true; 
    };
    deque<int> xq, yq;
    xq.push_front(sx);
    yq.push_front(sy);
    dis[sx][sy] = 0;
    while(!xq.empty()){
        int fx = xq.front();
        int fy = yq.front();
        xq.pop_front();
        yq.pop_front();
        for(int i = 0; i < 4; i++){
            int x = fx + xdir[i];
            int y = fy + ydir[i];
            if(!legal(x,y)) continue;
            if(dis[x][y]>dis[fx][fy]){
                dis[x][y] = dis[fx][fy];
                xq.push_front(x);
                yq.push_front(y);
            }
        }
        for(int i = -2; i < 3; i++){
            for(int j = -2 ; j < 3; j++){
                int x = fx + i;
                int y = fy + j;
                if(!legal(x,y)) continue;
                if(dis[x][y]>dis[fx][fy]+1){
                    dis[x][y] = dis[fx][fy] + 1;
                    xq.push_back(x);
                    yq.push_back(y);
                }
            }
        }
    }
    cout<<((dis[ex][ey]==1e7)?-1:dis[ex][ey])<<endl;

    return 0;
}