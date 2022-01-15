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
    int n, q; cin >> n >> q;
    map<int, vector<int>> f;
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        f[k].push_back(i);
    }
    for(int i = 0; i < q; i++){
        int x, k; cin >> x >> k;
        if(f[x].size() < k){
            cout << -1 << endl;
            continue;
        }
        cout << f[x][k - 1] << endl;
    }
    return 0;
}