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
    string a = "-", b = "-";
    vector<string> s(2 * n - 2);
    for(string &x : s){
        cin >> x;
        if(x.size() == n-1){
            if(a == "-") a = x;
            else         b = x;
        }
    }
    string res = "";
    auto check = [&](string &a, string &b){
        string ts = a + b[n - 2];
        multiset<string> uni, pre, suf;
        for(int i = 1; i < n; i++){
            uni.insert(ts.substr(0, i));
            pre.insert(ts.substr(0, i));
            uni.insert(ts.substr(i, n - i ));
            suf.insert(ts.substr(i, n - i ));
        }
        if(uni == multiset<string>(all(s))){
            for(int i = 0; i < 2 * n - 2; i++){
                if(pre.count(s[i])){
                    res += "P";
                    pre.erase(pre.find(s[i]));
                }
                else if(suf.count(s[i])){
                    res += "S";
                    suf.erase(suf.find(s[i]));
                }
                else{
                    return 0;
                }
            }
            return 1;
        }
        return 0;
    };
    if(check(a, b)){
        cout << res << endl;
        return 0;
    }
    else{
        res.clear();
        check(b, a);
        cout << res << endl;
        return 0;
    }
    
    
}