#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll con1=0;
        ll con2=0;
        ll con3=0;
        for(auto x:s){
            if(x=='0'){
                con2++;
            }
        }
        ll ans=1e18;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(con3>0){
                    ans=min(ans,con1+con2);
                }else{
                    ans=con2;
                    break;
                }
            }
            if(s[i]=='0'){
                con2--;
                con3++;
            }else{
                con1++;
            }
        }
        ans=min(ans,con1+con2);
        cout<<ans<<"\n";
    }
}