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
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> xors(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    auto check = [&](int l, int r, int bit){
        map<int,vector<vector<int>>> f;
        int x = 0;
        f[0] = vector<vector<int>> (2);
        f[x][(l - 1) & 1].push_back(l - 1);
        for(int i = l; i <= r; i++){
            x ^= xors[i];
            if(f.count(x) == 0){
                f[x] = vector<vector<int>> (2);
            }
            f[x][i & 1].push_back(i);   
        }
        for(auto pv : f){
            vector<vector<int>> pos = pv.second;
            if(pos[0].size() > 1){
                ans = max(ans, pos[0].back() - pos[0].front());
            }
            if(pos[1].size() > 1){
                ans = max(ans, pos[1].back() - pos[1].front());
            }
        }
    };
    for(int bit = 31; bit >= 0; bit--){
        vector<int> curr(n + 1);
        for(int i = 1; i <= n; i++){
            curr[i] = (a[i] >> bit) & 1;
        }
        for(int i = 1; i <= n; i++){
            if(curr[i]){
                xors[i] |= (1 << bit);
            }
        }
        for(int i = 1; i <= n; i++){
            if(curr[i] == 0) continue;
            int j = i + 1;
            while(j <= n && curr[j]){
                j++;
            }
            int len = j - i;
            if(len <= ans){
                i = j - 1;
                continue;
            }
            if(len & 1){
                check(i + 1, j - 1, bit);
                check(i, j - 2, bit);
            }
            else{
                check(i, j - 1, bit);
            }
            i = j - 1;
        }    
    }
    cout << ans << endl;
    return 0;
}