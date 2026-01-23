#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b;
    cin>>a>>b;
    ll MOD=1e9;
    vector<ll> V;
    if(b>a){
        cout<<1;
        return 0;
    }
    for(int i=0;i<b;i++){
        V.push_back(1);
    }
    V.push_back(b);
    ll suma=b;
    ll l=0;
    for(ll i=b+1;i<=a;i++){
        suma=(suma%MOD+V.back()%MOD)%MOD;
        suma=(suma%MOD-V[l]%MOD+MOD)%MOD;
        V.push_back(suma%MOD);
        l++;
    }

    cout<<suma%MOD;
}