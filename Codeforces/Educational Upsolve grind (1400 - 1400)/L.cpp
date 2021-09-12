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
    vector<vector<string>> a(4, vector<string>(n));
    for(int i = 0; i < 4; i++){
        for(int row = 0; row < n; row++){
            cin >> a[i][row];
        }
    }
    auto process1 = [&](int x){
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((i + j)%2 == 0 && a[x][i][j] != '1') res++;
                if((i + j)%2 == 1 && a[x][i][j] != '0') res++;
            }
        }
        return res;
    };
    auto process2 = [&](int x){
        int opp = 0;
        for(int i = 0; i < n; i++){
            for(int j= 0 ;j  < n; j++){
                if((i + j)%2 == 1 && a[x][i][j] != '1') opp++;
                if((i + j)%2 == 0 && a[x][i][j] != '0') opp++;
            }
        }
        return opp;
    };
    int ans = inf;
    for(int i = 0; i < 3; i++){
        int first = process1(i);
        int second, other;
        for(int j = i+1; j < 4; j++){
            second = process1(j);
            other = 0;
            for(int k = 0; k < 4; k++){
                if(k == i || k == j) continue;
                other += process2(k);
            }
            ans = min(ans, first + second + other);
        }  
    }
    cout << ans << endl;
    return 0;
}