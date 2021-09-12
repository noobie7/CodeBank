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
    vector<int> p(1e5 + 5);
    // p[i] = 0; prime
    // p[i] = k; has k prime factors 
    for(int i = 2; i < 1e5 + 5; i++){
        for(int j = 2 * i; !p[i] && j < 1e5 + 5; j += i ){
            p[j]++;
        }
    }
    for(int i = 2; i < 1e5 + 5; i++) if(!p[i]) p[i] = 1;
    vector<vector<int>> cnt(1e5 + 5, vector<int>(6));
    for(int i = 0; i < 1e5 + 5; i++){
        if(p[i] < 6)
            cnt[i][p[i]]++;
    }
    for(int i = 2; i < 1e5 + 5; i++){
        for(int j = 1; j < 6; j++){
            cnt[i][j] += cnt[i-1][j];
        }
    }
    test(){
        int a, b; cin >> a >> b;
        int k; cin >> k;
        cout << cnt[b][k] - cnt[a - 1][k] << endl;
    }
    return 0;
}