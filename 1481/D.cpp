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

const int nag = 1e3 + 5;
vector<vector<int>> in1(nag), in2(nag), out1(nag), out2(nag);

int main(){
    Shazam;
    test(){
        int n, k; cin >> n >> k;
        for(int i = 0; i <= n; i++){
            in1.clear();
            in2.clear();
            out1.clear();
            out2.clear();
        }
        vector<string> g;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            g.push_back(s);
        }
        if(k & 1){
            cout << "YES" << endl;
            for(int i = 0; i <= k; i++){
                cout << (i & 1) + 1 << " ";
            }
            cout << endl;
            goto here;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(i == j) continue;
                if(g[i][j] == g[j][i]){
                    cout << "YES" << endl;
                    while(k + 1){
                        k--;
                        if(k & 1){
                            cout << i + 1 << " ";
                        }
                        else{
                            cout << j + 1 << " ";
                        }
                    }
                    cout << endl;
                    goto here;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                for(int l = 0; l < n; l++){
                    if(l == j) continue;
                    if(g[i][j] == g[j][l]){
                        vector<int> nodes = {i + 1, j + 1, l + 1};
                        int curr = (k >> 1) & 1 ^ 1;
                        k++;
                        cout << "YES" << endl;
                        while(k){ 
                            for( ; curr < 3 && k; curr++){
                                cout << nodes[curr] << " ";
                                k--;
                            }
                            curr = 1;
                            for( ; curr >= 0 && k ; curr--){
                                cout << nodes[curr] << " ";
                                k--;
                            }
                            curr = 1;
                        }
                        goto here;
                    }
                }
                
            }
        }
        cout << "NO" << endl;
        continue;
        here :;
    }
    return 0;
}