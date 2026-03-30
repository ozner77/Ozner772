#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        if(a%k==0){
            cout<<a/k<<" ";
        }
    }
}