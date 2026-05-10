#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        if(x>y){
            cout<<"NO\n";
        }else if(x==0 && y%2==1){
            cout<<"YES\n";
            for(int i=2;i<=y;i++){
                cout<<1<<" "<<i<<"\n";
            }
        }else if(x==0 && y%2==0){
            cout<<"NO\n";
        }else if(x==y){
            cout<<"YES\n";
            for(int i=1;i<x+y;i++){
                cout<<i<<" "<<i+1<<"\n";
            }
        }else{
            cout<<"YES\n";
            if((y-x)%2==0){
                for(int i=1;i<2*x;i++){
                    cout<<i<<" "<<i+1<<"\n";
                }
                for(int i=2*x+1;i<=x+y;i++){
                    cout<<2*x-1<<" "<<i<<"\n";
                }
            }else{
                cout<<1<<" "<<2<<"\n";
                for(int i=2;i<2*x;i++){
                    cout<<i<<" "<<i+1<<"\n";
                }
                for(int i=2*x+1;i<=x+y;i++){
                    cout<<2*x<<" "<<i<<"\n";
                }
            }   
        }
    }
}