#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<string> a(n);
        for(string &s: a)
            cin>>s;
        bool got = false;
        string ans = a.front();
        
        for(int i = 0; i < m && !got; i++){
            char save = ans[i];
            for(char c = 'a'; c<='z'; c++){
                ans[i] = c;
                bool flag = true;
                for(int j = 0; j < n; j++){
                    int cnt =0;
                    
                    for(int k =0 ; k < m; k++){
                        cnt+= (ans[k]!= a[j][k]);
                    }
                    if(cnt>1){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                cout<<ans<<endl;
                got = true;
                break;
                }
            }
            
            ans[i] = save;
        }
        if(!got){
            cout<<-1<<endl;
        }
    }
}