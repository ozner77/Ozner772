#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,originalx,x;
        cin>>n>>originalx;
        vector<pair<ll,ll>> V;
        vector<ll> C,D;
        for(int i=0;i<n;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            V.push_back({a*b-c,b});
            C.push_back(a);
            D.push_back(c);
            if(b!=1){
                originalx-=(a*(b-1));
            }
        }
        ll ans=9e18;
        for(int i=0;i<n;i++){
            x=originalx;
            x-=(C[i]-D[i]);
            if(V[i].second==1){
                ll xd=x/V[i].first;
                if(xd<=0){
                    continue;
                }
                ans=min(ans,xd+1);
            }else if(V[i].second*C[i]-C[i]>=x){
                ans=0;
            }else if(V[i].first<=0){
                continue;
            }else{
                ll jaja=V[i].second*C[i]-C[i];

                ll xd=(x-jaja)/V[i].first;
                ans=min(ans,xd+1);
                if((x-jaja)%V[i].first!=0){
                    ans++;
                }
            }
        }
        if(ans==9e18){
            cout<<-1<<"\n";
        }else{
            cout<<ans<<"\n";
        }
    }
}