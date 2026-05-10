#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,f,a,b;
        cin>>n>>f>>a>>b;
        vector<ll> V;
        V.push_back(0);
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            V.push_back(x);
        }
        bool ok=true;
        for(int i=1;i<=n;i++){
            ll costo=min((V[i]-V[i-1])*a,b);
            if(f-costo>0){
                f-=costo;
            }else{
                ok=false;
                break;
            }
        }
        if(ok){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}