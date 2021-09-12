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
    test(){
        ll x,y; cin>>x>>y;
        swap(x,y);
        vector<ll> cost(6);
        get(cost);
        vector<ll> up(3);
        up[0] = cost.back();
        up[1] = cost.front();
        up[2] = cost[1];
        vector<ll> down(3);
        down[0] = cost[2];
        down[1] = cost[3];
        down[2] = cost[4];

        if(x>=0 && y>=0){
            cout<<min( y*up[0] + x*up[2], min(x,y)*up[1] + (x-min(x,y))*up[2] + (y-min(x,y))*up[0] )<<endl;
            continue;
        }
        if(x>=0){
            y*=-1LL;
            if(up[2] +down[1] > down[0])
                cout<<y*down[0] + x*up[2]<<endl;
            else
                cout<< x*up[2] + y*(up[2] + down[1])<<endl;
            continue;
        }
        if(y>=0){
            x*=-1LL;
            if(down[2] + up[1] > up[0])
                cout<<(y*up[0] + x*down[2] )<<endl;
            else 
                cout<< x*down[2] + y*(down[2] + up[1])<<endl;

            continue;
        }
        x *=-1LL;
        y *=-1LL;
        cout<<min(y*down[0] + x*down[2], min(x,y)*down[1] + (x-min(x,y))*down[2] + (y-min(y,x))*down[0])<<endl;
        
    }
    return 0;
}