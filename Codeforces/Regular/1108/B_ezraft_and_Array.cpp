#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1){
            cout<<1;
        }else if(n==2){
            cout<<-1;
        }else{
            cout<<1<<" "<<2<<" ";
            ll con=3;
            for(int i=3;i<=n;i++){
                cout<<con<<" ";
                con*=2;
            }
        }
        cout<<"\n";
    }
}