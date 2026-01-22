#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,w;
        cin>>n>>w;
        ll w2=2*w;
        unordered_map<ll,ll> M;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            ll xd=(i+1)%w2;
            M[xd]+=a;
        }
        ll ans=0;
        for(int i=0;i<w;i++){
            ans+=M[i];
        }
        ll r=w-1;
        ll l=2*w;
        ll xd=ans;
        while(l>1){
            xd-=M[r];
            l--;
            xd+=M[l];
            if(r==0){
                r=(2*w)-1;
            }else{
                r--;
            }
            ans=min(ans,xd);
        }
        cout<<ans<<"\n";
    }
}