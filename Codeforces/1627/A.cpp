/*
    "An anomaly, I'm Muhammad Ali
      Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define get(a) for(auto &i : a)  cin>>i;
#define pra(a) for(auto i : a) cout<< i <<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n, m; cin >> n >> m;
        int r, c; cin >> r >> c;
        r--; c--;
        vector<string> a(n);
        get(a);
        vector<string> b = a;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += count(all(a[i]), 'B');
        }
        if(cnt == 0){
            cout << -1 << endl;
            continue;
        }
        if(a[r][c] == 'B'){
            cout << 0 << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 'B'){
                    for(int k = 0; k < n; k++){
                        b[k][j] = 'B';
                    }
                    for(int k = 0; k < m; k++){
                        b[i][k] = 'B';
                    }
                }
            }
        }
        if(b[r][c] == 'B'){
            cout << 1 << endl;
            continue;
        }
        a = b;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 'B'){
                    for(int k = 0; k < n; k++){
                        b[k][j] = 'B';
                    }
                    for(int k = 0; k < m; k++){
                        b[i][k] = 'B';
                    }
                }
            }
        }
        if(b[r][c] == 'B'){
            cout << 2 << endl;
        }
    }
    return 0;
}