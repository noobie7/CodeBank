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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    get(a);
    vector<int> ans(n, -1);
    priority_queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        q.push({a[i], i});
    }
    int turn = 0;
    vector<int> next(n), prev(n);
    iota(all(next), 1);
    iota(all(prev), -1);
    while(!q.empty()){
        while(q.size() && ans[q.top().ss] != -1) q.pop();
        if(q.size() == 0) break;
        auto tp = q.top();
        q.pop();
        int idx = tp.ss;    
        ans[idx] = turn + 1;
        int lft = idx , rgt = idx;
        int j = next[idx];
        int rcnt = 0, lcnt = 0;
        while(j < n && rcnt < k){
            ans[j] = turn + 1;
            j = next[j];
            rcnt++;
        }
        rgt = j;
        j = prev[idx];
        while(j >= 0 && lcnt < k){
            ans[j] = turn + 1;
            j = prev[j];
            lcnt++;
        }
        lft = j;
        if(lft >= 0)
            next[lft] = rgt;
        if(rgt < n)
            prev[rgt] = lft;

        turn ^= 1;
    }
    for(int i : ans){
        cout << i;
    }
    cout << endl;
    return 0;
}