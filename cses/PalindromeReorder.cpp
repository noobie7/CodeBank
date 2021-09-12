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
    vector<int> cnt(26);
    for(auto c : s){
        cnt[c - 'A']++;
    }
  
    int odd = 0;
    int ch = -1;

    for(int i = 0; i < 26; i++){
        if(cnt[i] & 1){
            ch = i;
            odd++;
        }
    }
    if(((n&1) && (odd != 1) )||(n&1^1)&&odd){
        cout << "NO SOLUTION" << endl;
        return 0;
    } 
    else{
        deque<char> ans;
        if(n&1){
            ans.push_back((char)(ch + 'A'));
            cnt[ch]--;
        }
        for(int i = 0; i < 26; i++){
            while(cnt[i]){
                ans.push_back((char)(i + 'A'));
                ans.push_front((char)(i + 'A'));
                cnt[i] -= 2;
            }
        }
        for(auto c : ans) cout << c ;
        cout << endl;
    }
    
    return 0;
}