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
    int n = (int)s.size();
    vector<int> dis;
    vector<int> a;
    dis.push_back(s.front());
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != dis.back()){
            a.push_back(cnt);
            dis.push_back(s[i]);
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    a.push_back(cnt);
    if(dis.size() & 1 ^ 1){
        cout << 0 << endl;
        return 0;
    }
    int m = (int)dis.size();

    for(int  i = 0; i < m/2; i++){
        if(dis[i] != dis[m-1-i] || a[i] + a[m-1-i] < 3){
            cout << 0 << endl;
            return 0;
        }
    }
    if(a[m/2] >=2)
        cout << a[m/2] + 1 << endl;
    else{
        cout << 0 << endl;
    }
    return 0;
}