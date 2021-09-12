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
    // int nag = 1e7 + 5;
    // vector<int> p(nag, 1);
    // p[0] = p[1] = 1;
    // for(int i = 2; i * i <= nag; i++){
    //     for(int j = 2 * i; p[i] && j <= nag; j += i){
    //         p[j] = 0;
    //     }
    // }
    // vector<int> l;
    // for(int i = 2; i < nag; i++){
    //     l.push_back(i);
    // }
    test(){
        int n; cin >> n;
        vector<ll> a(n);
        get(a);
        vector<array<ll, 4>> ans;
        for(int i = 0; i + 1 < n; i += 2){
            array<ll, 4> temp;
            {
                temp[0] = i + 1;
                temp[1] = i + 2;
                temp[2] = a[i] = min(a[i], a[i + 1]);
                temp[3] = a[i + 1] = (ll)(1e9 + 7);
                ans.push_back(temp);
            }
        }

        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < 4; j++){
                cout << ans[i][j] << " ";
            }
            cout << endl; 
        }

    }
    return 0;
}