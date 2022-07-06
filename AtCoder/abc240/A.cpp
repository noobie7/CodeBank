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
    int a, b; cin >> a >> b;
    if(a > b) swap(a, b);
    if(a == 1 && b == 10){
        cout << "Yes" << endl;
        return 0;
    }
    if(b == (a + 1)){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}