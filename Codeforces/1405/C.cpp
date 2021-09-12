#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        bool can = true;
        int z = 0, o = 0;
        for(int i = 0 ; i < k; i++){
            int temp = -1;
            for(int j = i;  j < n; j+=k){
                if(s[j]!='?'){
                    if(temp!=-1 && s[j]-'0'!=temp){
                        can = false;
                        break;
                    }
                    temp = s[j]-'0';
                }
            }
            if(temp!=-1)
                (temp==0?z:o)++;
        }
        if(max(z,o)>k/2)
            can = false;
        cout<<((can)?"YES":"NO")<<endl;   
    }
}