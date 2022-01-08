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
    test(){
        int n; cin >> n;
        int m; cin >> m;
        int k; cin >> k;
        vector<string> a(n);
        vector<string> d(n, string(m, '.'));
        get(a);
        auto draw = [&](int x, int y){
            int left = 0, right = 0;
            for(int i = x; i >= 0; i--){
                if(y - (x - i) >= 0)
                    left++;
                if(y + (x - i) < m)
                    right++;
            }
            right = min(right, left);
            if(right < k + 1)
                return ;
            left = 0;
            for(int i = x; i >= 0 && right > 0; i--){
                if(a[i][y - (x - i)] == '*' &&  a[i][y + (x - i)] == '*'){
                    left++;
                    right--;
                }
                else
                    break;
            }
            if(left < k + 1)
                return ;
            for(int i = x; i >= 0 && left; i--){
                d[i][y - (x - i)] = '*';
                d[i][y + (x - i)] = '*';
                left--;
            }
        };
        for(int i = k ; i < n; i++){
            for(int j = k ; j < m; j++){
                if(a[i][j] == '*'){
                    draw(i, j);
                }
            }
        }
        int ok = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == '*')
                    ok &= (d[i][j] == '*');
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}