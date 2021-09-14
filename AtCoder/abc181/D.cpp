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
    string  s; cin >> s;
    map<int,int> f;
    for(char c : s){
        f[c-'a'] += 1;
    }
    if(s.size() < 2){
        if(s == "8"){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        return 0;
    }
    if(s.size() < 3){
        for(int i = 16; i < 100 ; i += 8){
            string k = to_string(i);
            map<int,int> req;
            for(auto c : k){
                req[c - 'a'] += 1;
            }
            bool can = true;
            for(auto pp : req){
                can &= (pp.ss <= f[pp.ff]);
            }
            if(can){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    for(int i = 104; i < 1000 ; i += 8){
            string k = to_string(i);
            map<int,int> req;
            for(auto c : k){
                req[c - 'a'] += 1;
            }
            bool can = true;
            for(auto pp : req){
                can &= (pp.ss <= f[pp.ff]);
            }
            if(can){
                cout << "Yes" << endl;
                return 0;
            }
    }
    cout << "No" << endl;
    return 0;
}