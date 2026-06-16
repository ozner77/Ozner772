#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,d;
    cin>>n>>d;
    ll pos=0;
    string s;
    cin>>s;
    ll ans=0;
    while(pos!=n-1){
        ll jump=pos;
        for(int i=pos+1;i<=pos+d;i++){
            if(i<n){
                if(s[i]=='1'){
                    jump=i;
                }
            }
        }
        if(jump==pos){
            cout<<-1<<"\n";
            return 0;
        }else{
            pos=jump;
            ans++;
        }
    }
    cout<<ans;
}