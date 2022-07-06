/*
    "An anomaly, I'm Muhammad Ali
    Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
    int n, x; cin >> n >> x;
    vector<pair<int, int>> ans(x + 5);
    ans[0] = {1, 0};
    for(int i = 0; i < n; i++){
        int a, b; 
        cin >> a >> b;
        for(int p = 0; p <= x; p++){
            if(ans[p].first == 1){
                if(p + a < x + 5)
                    ans[p + a].second = 1;
                if(p + b < x + 5)
                    ans[p + b].second = 1;
                ans[p].first = 0;
            }
        }

        for(auto &i : ans){
            if(i.first == 1){
                i.first = 0;
            }
            if(i.second == 1){
                i.first = 1;
                i.second = 0;
            }
        }

        
    }
    cout << ( (ans[x].first == 1) ? "Yes" : "No") << endl;
    return 0;
}