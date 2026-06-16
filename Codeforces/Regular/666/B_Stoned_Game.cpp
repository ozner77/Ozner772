#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll maxi=0;
        ll sumi=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            maxi=max(maxi,a);
            sumi+=a;
        }
        if(maxi>(sumi/2)){
            cout<<"T\n";
        }else if(sumi%2==0){
            cout<<"HL\n";
        }else{
            cout<<"T\n";
        }
    }
}