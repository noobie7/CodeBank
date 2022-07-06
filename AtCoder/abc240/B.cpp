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
    int n; cin >> n;
    set<int> bag;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        bag.insert(k);
    }
    cout << (int)bag.size() << endl;
    return 0;
}