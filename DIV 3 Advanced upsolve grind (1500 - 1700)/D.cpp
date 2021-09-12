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
    string s; cin >> s;
    map<int,int> f;
    for(char c : s){
        f[c - '0']++;
    }
    string ans(n, '3');
    string t = s;
    map<int,int> l = f;
    for(int i = 0; i < n; i++){
        if(f[s[i] - '0'] > n/3){
            for(int j = 0; j < s[i] - '0'; j++){
                if(f[j] < n / 3){
                    f[s[i] - '0']--;
                    s[i] = (char)(j + '0');
                    f[s[i] - '0']++;
                    break;
                }
            }
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(f[s[i] - '0'] > n/3){
            for(int j = 2; j > s[i] - '0'; j--){
                if(f[j] < n / 3){
                    f[s[i] - '0']--;
                    s[i] = (char)(j + '0');
                    f[s[i] - '0']++;
                }
            }
        }
    }

    ans = min(s, ans);
    s = t;
    f = l;
    for(int i = n-1; i >= 0; i--){
        if(f[s[i] - '0'] > n/3){
            for(int j = 2; j > s[i] - '0'; j--){
                if(f[j] < n / 3){
                    f[s[i] - '0']--;
                    s[i] = (char)(j + '0');
                    f[s[i] - '0']++;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(f[s[i] - '0'] > n/3){
            for(int j = 0; j < s[i] - '0'; j++){
                if(f[j] < n / 3){
                    f[s[i] - '0']--;
                    s[i] = (char)(j + '0');
                    f[s[i] - '0']++;
                    break;
                }
            }
        }
    }

    ans = min(s, ans);
    cout << ans << endl;
    return 0;
}