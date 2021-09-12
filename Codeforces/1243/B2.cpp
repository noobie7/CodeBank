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
    test(){
        int n; cin >> n; 
        string s, t; cin >> s >> t;
        vector<pair<int,int>> op;
        bool cant = false;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                bool got = false;
                for(int j = i + 1; j < n; j++){
                    if(t[j] == t[i]){
                        got = true;
                        swap(s[i], t[j]);
                        op.push_back({i+1, j+1});
                        break;
                    }
                }
                for(int j = i + 1; j < n && !got ; j++){
                    if(t[i] == s[j]){
                        got = true;
                        swap(s[j],t[j]);
                        op.push_back({j+1, j+1});
                        swap(s[i],t[j]);
                        op.push_back({i+1, j+1});
                        break;
                    }
                }
                if(!got){
                    cant = true;
                    break;
                }
            }
        }
        if(cant){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            cout << op.size() << endl;
            for(auto pp : op){
                cout << pp.ff << " " << pp.ss << endl;  
            }
        }
    }
    return 0;
}