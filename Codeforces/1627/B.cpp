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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int> (m, inf));
        vector<pair<int,int>> center;
        vector<int> centerx, centery;
        if((n & 1)){
            centerx.push_back( n / 2 );
        }
        else{
            centerx.push_back( (n / 2) - 1);
            centerx.push_back( n / 2 );
        }
        if( m & 1){
            centery.push_back( m / 2);
        }
        else{
            centery.push_back( m / 2 - 1);
            centery.push_back( m / 2);
        }
        for(int i : centerx){
            for(int j : centery){
                center.push_back({i, j});
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(auto pp : center){
                    a[i][j] = min(a[i][j], abs(i - pp.first) + abs(j - pp.second));
                }
            }
        }
        map<int, int> f;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                f[a[i][j]]++;
            }
        }
        vector<int> freq;
        for(auto pp : f){
            freq.push_back(pp.second);
        }
        int init = (n - 1 - (n / 2  - (n & 1 ^ 1))) + (m - 1 - (m / 2 - (m & 1 ^ 1)));
        for(int cnt : freq){
            for(int i = 0; i < cnt; i++){
                cout << init << " ";
            }
            init++;
        }
        cout << endl;
    }
    return 0;
}