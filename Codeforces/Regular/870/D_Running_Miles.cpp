#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V,V2;
        vector<pair<ll,ll>> pL,pR;
        vector<ll> original;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            original.push_back(a);
            V.push_back(a-(i+1));
            V2.push_back(a-(n-i-1));
        }
        pL.push_back({-1e30,-1});
        pR.push_back({-1e30,-1});
        for(int i=0;i<n;i++){
            if(V[i]>pL[i].first){
                pL.push_back({V[i],i});
            }else{
                pL.push_back(pL[i]);
            }
        }
        reverse(V.begin(),V.end());
        reverse(V2.begin(),V2.end());
        for(int i=0;i<n;i++){
            if(V[i]>pR[i].first){
                pR.push_back({V2[i],n-1-i});
            }else{
                pR.push_back(pR[i]);
            }
        }
        reverse(V.begin(),V.end());
        ll ans=-1e18;
        ll x,y,z;
        for(int i=1;i<n-1;i++){
            ll tempy=V[i];
            ll tempx=pL[i].first;
            ll tempz=pR[n-1-i].first;
            if(tempy+tempx+tempz>ans){
                ans=tempy+tempx+tempz;
                x=pL[i].second;
                y=i;
                z=pR[n-1-i].second;
            }
        }
        for(auto x:V2){
            cout<<x<<" ";
        }
        ll res=original[x]+original[y]+original[z];
        res-=(z-x);
        cout<<res<<" "<<"\n";
    }
}