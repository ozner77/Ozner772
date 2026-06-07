#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll q;
    cin>>q;
    ll ans=0;

    vector<bool> delante(n,true);
    for(ll i=0;i<q;i++){
        ll a;
        cin>>a;
        if(a>0){
            if(!delante[a-1]){
                ans++;
                delante.assign(n,true);
                
            }
            delante[a-1]=false;
        }else{
            delante[-a-1]=true;
        }
    }
    cout<<ans<<"\n";
}