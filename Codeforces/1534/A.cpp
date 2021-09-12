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
        int m; cin >> m;
        vector<string> a(n);
        int p1 = 0;
        int p2 = 0;
        for(string &s : a) cin >> s;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 'W'){
                    p1 |= (1 << ((i + j) & 1 ));
                }
                else if(a[i][j] == 'R'){
                    p2 |= (1 << ((i + j) & 1 ));
                }
            }
        }
        
        if( (p1 & p2) == 0 ){
            cout << "YES" << endl;
            bool ok = true;
            vector<string> ans(n , string(m, '.'));

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if((j + i) & 1){
                        ans[i][j] = 'W';
                        if(a[i][j] != '.')
                            ok &= (ans[i][j] == a[i][j]);
                        
                    }
                    else{
                        ans[i][j] = 'R';
                        if(a[i][j] != '.')
                            ok &= (ans[i][j] == a[i][j]);
                        
                    }
                } 
            }
            if((p1 == 0 && p2 == 0 && ok) || ok){
                for(string s : ans) 
                    cout << s << endl;
            }
            else if(!ok){
                for(int i = 0;i < n; i++){
                    for(int j = 0; j < m; j++){
                        cout << (ans[i][j] == 'W' ? 'R' : 'W'); 
                    }
                    cout << endl;
                }
            }
            else{
                cout << "NO" << endl;
            }
        } 
        else{
            cout << "NO" <<endl;
        }
    }
    return 0;
}