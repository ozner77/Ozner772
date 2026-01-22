#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long comb(int n, int k) {
    if(k>n){
        return 0;
    }
    if (k==0 || k==n){
        return 1;
    }
    long long res=1;
    for (int i=1;i<=k;i++) {
        res=res*(n-i+1)/i;
    }
    return res;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll limit=0;
        ll xd=n;
        while(xd!=1){
            limit++;
            xd/=2;
        }
        ll ans=n;
        ans--;
        if(k>=limit+1 && limit!=0){
            ans--;
        }
        for(int i=1;i<limit;i++){
            ll na=k-(i+1);
            if(na>i){
                na=i;
            }

            for(int j=0;j<=na;j++){
                ans-=comb(i,j);

            }
        }
        cout<<ans<<"\n";
    }
}