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
    int n; cin >> n;
    int m; cin >> m;
    map<int, set<int>> f;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        f[a].insert(b);
    }
    for(auto pp : f){
        if(pp.ss.size() > 1){
            cout << -1 << endl;
            return 0;
        }
    }
    
    for(int i = (pow(10, n - 1) == 1 ? 0 : pow(10, n - 1) ); i < pow(10, n); i++){
        bool ok = 1;
        string s = to_string(i);
        for(auto pp : f){
            int pos = pp.ff - 1;
            int val = *pp.ss.begin();
            ok &= (s[pos] == (char)('0' + val));
        }
        if(ok){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}