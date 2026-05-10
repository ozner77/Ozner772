#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        n*=3;
        ll l=1;
        ll r=n;
        for(int i=0;i<n/3;i++){
            cout<<l<<" "<<r-1<<" "<<r<<" ";
            l++;
            r-=2;
        }
        cout<<"\n";
    }
}