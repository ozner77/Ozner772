#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll vol=0;
    bool playing=false;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        if(a==2 && vol>0){
            vol--;
        }else if(a==1){
            vol++;
        }else if(a==3){
            playing=!playing;
        }
        if(playing && vol>=3){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}