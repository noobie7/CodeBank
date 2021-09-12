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
#define fl(i,a,b) for(int i = a ; i < b ;i++)
#define get(a) fl(i,0,a.size())  cin>>a[i];
#define pra(a) fl(i,0,a.size()) cout<<a[i];	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin >> n;
    string s; cin >> s;
    vector<int> ans(10);
    int left = 0;
    int right = 9;

    for(char c : s){
        if(c == 'L'){
            ans[left] = 1;
           // while(left < 10 && ans[left]) left++;
            for(int i = 0; i < 10; i++){
                if(ans[i] == 0){
                    left = i;
                    break;
                }
            }
        }
        else if(c == 'R'){
            ans[right] = 1;
            while(right >= 0 && ans[right]) right--;
        }
        else{
            string s = "111234";
            ans[c - '0'] = 0;
            for(int i = 0; i < 10; i++){
                if(!ans[i]){
                    left = i;
                    break;
                }
            }
            for(int i = 9; i >= 0; i--){
                if(!ans[i]){
                    right = i;
                    break;
                }
            }
        }
        
    }
    pra(ans);

    return 0;
}