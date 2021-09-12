#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> a(n);
        for(ll &i : a)
            cin>>i;
        reverse(a.begin(),a.end());
        for(int i : a)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}