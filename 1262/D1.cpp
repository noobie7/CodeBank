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


bool sorter(pair<int,int> &a, pair<int,int> &b){
    return a.ss < b.ss;
}

int main(){
    Shazam;
    int n; cin >> n;
    vector<int> a(n);
    map<int, vector<int>, greater<int>> f;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        f[a[i]].push_back(i);
    }
    for(auto pp : f){
      //  cout << pp.ff << endl;
        sort(all(pp.ss));
      
    }
    vector<vector<pair<int,int>>> ans(n+1);
    for(int i = 1; i <= n; i++){
        int c = 0;
        for(auto pp : f){
            if(c == i) break;
            for(auto ii : pp.ss){
                ans[i].push_back({pp.ff, ii});
                c++;
                if( c == i ) break;
            }
        }
        sort(all(ans[i]), sorter);
    }
    int m; cin >> m;
    for(int i = 0 ; i < m; i++){
        int idx; cin >> idx;
        int pos; cin >> pos;
        pos--;
        cout << ans[idx][pos].ff << endl;
    }
    return 0;
}