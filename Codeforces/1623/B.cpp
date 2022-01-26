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
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define get(a) for(auto &i : a)  cin>>i;
#define pra(a) for(auto i : a) cout<< i <<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n; cin >> n;
        vector<set<pair<int,int>>> cnt(n);
        for(int i = 0; i < n; i++){
            int l, r; cin >> l >> r;
            for(int j = l - 1; j < r; j++){
                cnt[j].insert(make_pair(l, r));
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int idx = 0;
            while(idx < n && cnt[idx].size() != 1){
                idx++;
            }   
            if(idx == n) 
                break;
            vector<int> curr(3);
            curr[0] = cnt[idx].begin() -> first;
            curr[1] = cnt[idx].begin() -> second;
            curr[2] = idx + 1;
            for(int j = curr[0] - 1; j < curr[1]; j++){
                cnt[j].erase(cnt[j].find(make_pair(curr[0], curr[1])));
            }
            ans.push_back(curr);
        }
        for(int i = 0; i < ans.size(); i++){
            pra(ans[i]);
        }
        cout << endl;
    }
    return 0;
}