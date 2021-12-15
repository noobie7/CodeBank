/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
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
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int> (3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> a[i][j];
            if(j)
                a[i][j] += a[i][j - 1];
        }
    }
    vector<pair<int,int>> score(n);
    for(int i = 0; i < n; i++){
        score[i] = {a[i][2], i};
    }
    sort(score.begin(), score.end());
    vector<string> ans(n);
    for(int i = 0; i < n; i++){
        int pos = upper_bound(score.begin(), score.end(), make_pair(score[i].ff + 300, n)) - score.begin() - 1;
        if(n - pos <= k){
            ans[score[i].ss] = "Yes";
        }
        else{
            ans[score[i].ss] = "No";
        }
    }
    for(auto s : ans){
        cout << s << endl;
    }

    return 0;
}