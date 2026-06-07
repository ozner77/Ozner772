#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V(n);
        for(int i=0;i<n;i++){
            cin>>V[i];
        }
        bool ok=true;
        sort(V.rbegin(),V.rend());
        for(int i=2;i<n;i++){
            if(V[i]!=(V[i-2]%V[i-1])){
                ok=false;
                break;
            }
        }
        if(ok){
            cout<<V[0]<<" "<<V[1]<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
}