#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll y,x;
        cin>>y>>x;
        ll z=max(x,y);
        if(z%2==1){
            swap(x,y);
        }
        if(x>y){
            cout<<(z-1)*(z-1)+y<<"\n";
        }else{
            cout<<z*z-x+1<<"\n";
        }
    }
}