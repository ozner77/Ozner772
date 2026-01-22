#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> V;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back({a,i});
        }
        sort(V.begin(),V.end());
        vector<ll> L(n);
        for(int i=0;i<n;i++){
            if(i%2==0){
                L[V[i].second]=1;
            }else{
                L[V[i].second]=2;
            }
        }
        bool ok=true;
        for(int i=1;i<n;i++){
            if(L[i]==L[i-1]){
                ok=false;
            }
        }
        if(ok){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<"\n";
    }
}