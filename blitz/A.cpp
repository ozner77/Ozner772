#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll people=0;
    for(int i=0;i<n;i++){
        char a;
        ll b;
        cin>>a;
        cin>>b;
        if(a=='P'){
            people+=b;
        }else{
            if(people<b){
                b-=people;
                people=0;
                if(b>0){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }else{
                people-=b;
                cout<<"NO\n";
            }
        }
    }
}
