#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll actu=1;
        vector<ll> V;
        for(int i=0;i<n;i++){
            V.push_back(actu);
            actu+=2;
        }
        for(auto x:V){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}