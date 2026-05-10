#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        bool ok=true;
        for(int i=1;i<n;i++){
            if(V[i]<V[i-1]){
                ok=false;
                break;
            }
        }
        if(ok){
            cout<<n<<"\n";
        }else{
            cout<<1<<"\n";
        }
    }
}