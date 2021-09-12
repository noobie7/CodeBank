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

vector<pair<int,int>> ans;
void calc(int n){
    if(n == 2) return;
    int y = max(1, (int)sqrt(n) - 1);
    while(y < (n + y - 1) / y)  y++;
    for(int i = y + 1; i < n; i++){
        ans.push_back({i,n});
    }
    ans.push_back({n, y});
    ans.push_back({n, y});
    calc(y);
}

int main(){
    Shazam;
    test(){
        ans.clear();
        int n; cin >> n;
        calc(n);
        cout << ans.size() << endl;
        for(auto pp : ans){
            cout << pp.ff << " " << pp.ss << endl;
        }
    }

    return 0;
}