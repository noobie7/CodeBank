/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    map<int,int> cnt;
    for(int i = 0; i < n * n; i++){
        int k; cin >> k;
        cnt[k]++;
    }
    priority_queue<pair<int,int>> q;
    for(auto [key , val] : cnt){
        q.push({val, key});
    }
    auto rev = [&](int i){
        return n - 1 - i;
    };
    auto put = [&](vector<pair<int,int>> pos){
        auto t(q.top());
        q.pop();
        if(t.ff < pos.size()){
            cout << "NO" << endl;
            exit(0);
        }
        for(auto pp : pos){
            a[pp.ff][pp.ss] = t.ss;
        }
        t.ff -= (int)pos.size();
        q.push(t);
    };
    vector<vector<int>> ans(n, vector<int>(n));
    int m = n / 2;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            put({{i,j}, {i, rev(j)}, {rev(i), j},{rev(i), rev(j)}});
        }
    }
    if(n&1){
        for(int i = 0; i < m; i++){
            put({{i,m},{rev(i), m}});
            put({{m,i},{m, rev(i)}});
        }
        put({{m,m}});
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}