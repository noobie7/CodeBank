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
        vector<int> a(n);
        get(a);
        vector<vector<int>> freq(n + 2);
        for(int i = n - 1; i >= 0; i--){
            freq[a[i]].push_back(i);
        }
        int mx = 0;
        for(int i = 0; i < n + 2; i++){
            if(freq[i].size() == 0){
                mx = i;
                break;
            }
        }
        vector<int> ans;
        int start = 0;
        while(start < n){
            ans.push_back(mx);  
            int last = start;
            for(int i = 0; i < mx; i++){
                assert(freq[i].size() > 0);
                last = max(last, freq[i].back());
            }
            for(int i = start; i <= last; i++){
                freq[a[i]].pop_back();
                if(freq[a[i]].size() == 0){
                    if(a[i] < mx){
                        mx = a[i];
                    }
                }
            }
            start = last + 1;
        }
        cout << ans.size() << endl;
        pra(ans);
    }
    
    return 0;
}