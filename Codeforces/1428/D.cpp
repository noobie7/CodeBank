/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
 */
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
    int n; cin>>n;
    vector<int> a(n); 
    get(a);
    vector<int> anr, anc;
    vector<int> fbdr(n), fbdc(n);
    for(int i = 0; i < n; i++) if(!a[i]) fbdc[i] = 1;
    int x = 1;
    int y = 1;
    bool can = true;
    for(int i = 0; i < n; i++){

        if(a[i]==0) continue;
        if(a[i]==1){
            if(anc.size() && anr.back() == y && anc.back() == x) {
                fbdr[y-1] = 1;
                fbdr[y-1] = 1;
                y++;
                x++;
                while(y <= n && fbdr[y-1]) y++;
                while(x <= n && fbdc[x-1]) x++;
                continue;
            }
            anc.push_back(x);
            anr.push_back(y);
            fbdr[y-1] = 1;
            y++;
            x++;
            while(y <= n && fbdr[y-1]) y++;
            while(x <= n && fbdc[x-1]) x++;
        }
        if(a[i]==2){
            if(anc.size() && anr.back() == y && anc.back() == x) {
                x++;
                while(x <= n && fbdc[x-1]) x++;
                anc.push_back(x);
                anr.push_back(y);
                if(x>n){can = false; break;}
                fbdc[x-1] = 1;
                fbdr[y-1] = 1;
                x++;
                y++;
                while(x<=n && fbdc[x-1]) x++;
                while(y<=n && fbdr[y-1]) y++;
                continue;
            }
            anc.push_back(x);
            anr.push_back(y);
            if(x>n){can = false; break;}
            fbdc[x-1] = 1;
            x++;
            while(x <= n && fbdc[x-1]) x++;
            anc.push_back(x);
            anr.push_back(y);
            fbdc[x-1] =1; 
            fbdr[y-1] =1;
            x++;
            y++;
            while(x <= n && fbdc[x-1]) x++;
            while(y <= n && fbdr[y-1]) y++;
        }
        if(a[i]==3){
            if(anc.size() && anr.back()==y && anc.back()==x){
                fbdc[x-1] =1;
                x++;
                while(x<=n && fbdc[x-1]) x++;
                if(x>n){can = false; break;}
                anc.push_back(x);
                anr.push_back(y);
                y++;
                while(y <=n && fbdr[y-1]) y++;
                if(y>n){can = false; break;}
                anc.push_back(x);
                anr.push_back(y);
                fbdc[x-1] = 1;
                continue;
            }
            anc.push_back(x);
            anr.push_back(y);
            if(x>n || y>n){can = false; break;}
            fbdc[x-1] = 1;
            fbdc[x-1] =1;
            x++;
            while(x<=n && fbdc[x-1]) x++;
            if(x>n){can = false; break;}
            anc.push_back(x);
            anr.push_back(y);
            y++;
            while(y <=n && fbdr[y-1]) y++;
            if(y>n){can = false; break;}
            anc.push_back(x);
            anr.push_back(y);
            fbdc[x-1] = 1;
        }
    }    
    vector<int> bcc(n+1), bcr(n+1);
    for(auto i : anc){ if(i > n) can = false; bcc[i]++; }
    for(auto i : anr){ if(i > n) can = false; bcr[i]++; }
    for(auto i : bcc){ if(i > 2) can = false;}
    for(auto i : bcr){ if(i > 2) can = false;}


    if(1){
        
        cout<<(int)anc.size()<<endl;
        for(int i = 0; i < (int)anc.size(); i++){
            cout<<anr[i]<<" "<<anc[i]<<endl;
        }
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}