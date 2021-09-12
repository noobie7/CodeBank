/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
 */
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
    test(){
        int n; cin>>n;
        int k; cin>>k;
        vector<int> a(n); 
        get(a);
        bool cant = false;
        int cnt = 0;
        while(a[n-1] && !cant ){
            //pra(a);
            cnt++;
            int last = a.front();
            a[0] = 0;
            int change = 0;
            for(int i = 1 ; i < n; i++){
                int prev = a[i];
                if(last != a[i]){
                    if(change<k-1){
                        change++;
                        last = a[i];
                        a[i] = 0;
                    }
                    else{
                        if(last==0){
                            cant = true;
                        }
                        a[i]-= last;
                    }
                }
                else{
                    a[i]-=last;
                }
            }
        }
        if(cant){
            cout<<-1<<endl;
        }
        else{
            cout<<cnt<<endl;
        }
    }
    return 0;
}