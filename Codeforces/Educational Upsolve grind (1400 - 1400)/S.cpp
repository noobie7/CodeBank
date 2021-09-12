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
    string s; cin >> s;
    string t = "";
    t += s[0];
    t += s[2];
    t += s[4];
    t += s[3];
    t += s[1];
    s = t;
    ll n = stoll(s);
    ll k = 1;
    for(int i = 0 ; i < 5; i++){
        k *= n;
        k %= 100000;
    }
   
    
    string ans = "", temp = to_string(k);

    while(ans.size() < 5 && temp.size()){
        ans.push_back(temp.back());
        temp.pop_back();
    }
    while(ans.size() < 5){
        ans.push_back('0');
    }
    reverse(all(ans));
    cout << ans << endl;
    return 0;
}