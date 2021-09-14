#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
const int mod=998244353,N=2e5+9;
int f[N],iv[N];
int pw(int a,int t=mod-2){
	int x=1;
	while(t){
		if(t&1)x=x*a%mod;
		a=a*a%mod,t>>=1;
	}
	return x;
}
int C(int n,int r){
	if(r==0)return 1;
	return f[n]*iv[r]%mod*iv[n-r]%mod;
}
int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    f[0]=1,iv[0]=1;
    for(int i=1;i<N;i++){
    	f[i]=i*f[i-1]%mod;
    	iv[i]=pw(f[i]);
    }
    int n,m,k,sum=0;
    cin >> n >> m >> k;
    for(int i=0;i<=k;i++){
    	sum=(sum+m*pw(m-1,n-1-i)%mod*C(n-1,i)%mod)%mod;
    }
    cout << sum;
}