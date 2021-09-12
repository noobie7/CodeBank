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
    vector<int> a(n);
    get(a);
    string ans = "";
    int i = 0;
    int j = n-1;
    int last = 0;
    while(i <= j){
        vector<pair<int,char>> curr;
        if(a[i] > last) curr.push_back({a[i], 'L'});
        if(a[j] > last) curr.push_back({a[j], 'R'});
        sort(all(curr));
        if(curr.size() == 1){
            last = curr.back().ff;
            ans.push_back(curr.back().ss);
            (curr.back().ss == 'R' ? j-- : i++);
        }
        else if(curr.size() == 2 && curr.back().ff != curr.front().ff){
            last = curr.front().ff;
            ans.push_back(curr.front().ss);
            (curr.front().ss == 'R' ? j-- : i++);
        }
        else if(curr.size() == 2){
            int left = 1, right = 1;
            while(i + left <= j && a[i + left] > a[i + left - 1]) left++;
            while(j - right >= i && a[j - right] > a[j - right + 1]) right++;
            if(left > right){
                ans += string(left, 'L');
            }
            else{
                ans += string(right, 'R');
            }
            cout << ans.size() << endl;
            cout << ans << endl;
            return 0;
        }
        else{
            break;
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}