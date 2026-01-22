#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m,h;
        cin>>n>>m>>h;
        vector<ll> V(n);
        vector<ll> original(n);
        vector<ll> crashes(n,1);
        ll crash=0;
        for(int i=0;i<n;i++){
            cin>>V[i];
            original[i]=V[i];
        }
        for(int i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            a--;
            if(crash>=crashes[a]){
                crashes[a]=crash+1;
                V[a]=original[a];
            }
            V[a]+=b;
            if(V[a]>h){
                crash++;
                V[a]=original[a];
                crashes[a]=crash+1;
            }
        }
        for(int i=0;i<n;i++){
            if(crash>=crashes[i]){
                V[i]=original[i];
            }
        }
        for(auto x:V){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}