#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll a;
    cin>>a;
    for(int i=1;i<n;i++){
        ll b;
        cin>>b;
        if(b>a){
            cout<<i+1;
            return 0;
        }
    }
    cout<<-1;
}