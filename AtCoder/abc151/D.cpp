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



int main(){
    Shazam;
    int h,w; cin>>h>>w;
    swap(h,w);

    vector<string> s(w);
    for(string &st : s) cin>>st;
    vector<int> xdir = {0,0,1,-1};
    vector<int> ydir = {1,-1,0,0};

    auto legal = [&](int x, int y){
        if(x<0||y<0||x>=w||y>=h||s[x][y]=='#') return false;
        return true;
    };
    int dis[w][h][w][h];
    for(int i = 0 ; i < w; i++){
        for(int j = 0; j < h; j++){
            for(int k = 0; k < w; k++){
                for(int l = 0; l < h; l++){
                    dis[i][j][k][l] = 1e5;
                }
            }
        }
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            if(!legal(i,j)) continue;
            for(int k = 0; k < 4; k++){
                int x = i + xdir[k];
                int y = j + ydir[k];
                if(legal(x,y)){
                    dis[i][j][x][y] = 1;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            for(int a = 0; a < w; a++){
                for(int b = 0; b < h; b++){
                    for(int c = 0; c < w ; c++){
                        for(int d =0 ;d < h; d++){
                            if(c==a&&d==b) continue;
                            dis[a][b][c][d] = min(dis[a][b][c][d], dis[a][b][i][j] + dis[i][j][c][d]);
                        }
                    }
                }
            }
        }
    }
    for(int i = 0 ; i < w; i++){
        for(int j = 0; j < h; j++){
            for(int k = 0; k < w; k++){
                for(int l = 0; l < h; l++){
                    if(dis[i][j][k][l]!=100000)
                       ans = max(ans, dis[i][j][k][l]);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}