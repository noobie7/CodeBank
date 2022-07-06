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
    vector<pair<int, int>> st;
    int n; cin >> n;

    auto process = [&](){
        if(st.size() == 1) return false;
        if(st.back().first != st.back().second) return false;
        int cnt = st.back().first;
        while(cnt--){
            st.pop_back();
        }
        return true;
    };

    for(int i = 0; i < n ; i++){
        int k; cin >> k;
        st.push_back({k, 1});
        int sz = (int)st.size();
        
        if(st.size() == 1){
            goto here;
        }
        
        if(st[sz - 2].first == st.back().first){
            st.back().second = st[sz - 2].second + 1;
            int flag = true;
            while(flag){
                flag &= process();
                flag &= (st.size() > 0);
            }
        }
        
        here :;
        cout << st.size() << endl;
    }
    return 0;
}