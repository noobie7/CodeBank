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
    int a = 0, b = 0;
    for(int i = 0; i < 6; i++){
        if(i < 3){
            a += s[i] - '0';
        }
        else{
            b += s[i] - '0';
        }
    }
    sort(s.begin() , s.begin() + 3);
    sort(s.begin() + 3, s.end());

    int off = (a > b);
    int dif = abs(a - b);
    if(a == b){
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    priority_queue<int> q;
    for(int i = 0 ;i < 3; i++){
        int can = 9 - (s[off * 3 + i] - '0');
        q.push(can);
    }

    for(int i = 2 ;i >= 0; i--){
        int can = (s[(!off) * 3 + i] - '0');
        q.push(can);
    }
    while(dif > 0){
        dif -= q.top();
        q.pop();
        ans++;
    }
    cout << ans << endl;
    return 0;
}