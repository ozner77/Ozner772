#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a=0,b=0;
    for(int i=0;i<9;i++){
        ll x;
        cin>>x;
        a+=x;
    }
    for(int i=0;i<8;i++){
        ll y;
        cin>>y;
        b+=y;
    }
    cout<<(a-b+1);
}