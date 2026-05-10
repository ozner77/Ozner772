#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> P,I;
        vector<ll> X;
        ll suma=0;
        ll maxii=-1e18;
        ll maxip=-1e18;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            suma+=x;
            if(i%2==0){
                if(x>=0){
                    I.push_back(x);
                }
                maxii=max(maxii,x);
            }else{
                maxip=max(maxip,x);
                if(x>=0){
                    P.push_back(x);
                }
            }
        }
        sort(P.rbegin(),P.rend());
        sort(I.rbegin(),I.rend());
        ll par=0,impar=0;
        for(int i=0;i<m;i++){
            ll x;
            cin>>x;
            if(x%2==0){
                par++;
            }else{
                impar++;
            }
            X.push_back(x);
        }
        ll ans=0;
        for(int i=0;i<impar;i++){
            if(i<I.size()){
                ans+=I[i];
            }
        }
        for(int i=0;i<par;i++){
            if(i<P.size()){
                ans+=P[i];
            }
        }
        if(I.size()==0 && impar>0){
            ans+=maxii;
        }
        if(P.size()==0 && par>0){
            ans+=maxip;
        }
        cout<<suma-ans<<"\n";
    }
}