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
    string s, t; cin >> s >> t;
    ll n = s.size();
    int m = t.size();
    ll prev = -1;
    vector<vector<int>> dic(26);
    for(int i = 0; i < n; i++){
        dic[s[i] - 'a'].push_back(i);
    }
    bool can = true;
    ll ans = 0;
    for(char c : t){
        if(dic[c - 'a'].size() == 0){
            can = false;
            break;
        }
        int pos = upper_bound(all(dic[c - 'a']), prev) - dic[c - 'a'].begin();
        if(pos == dic[c - 'a'].size()){
            pos = 0;
        }
        ans += (prev >= dic[c - 'a'][pos]);
        prev = dic[c - 'a'][pos];
    }
    cout << (can ? ans * n + prev + 1: -1) << endl;
    return 0;
}