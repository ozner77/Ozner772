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
        bool block1=true;
        long double cur=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cur++;
            }else{
                ans++;
                if(block1){
                    block1=false;
                    cur--;
                    long double xd=ceil(cur/3);
                    ans+=xd;
                }else if(cur>0){
                    cur-=2;
                    long double xd=ceil(cur/3);

                    ans+=xd;
                }
                cur=0;
            }
        }
        if(block1){
            long double xd=ceil(cur/3);
            ans+=xd;
        }else if(cur>0){
            cur--;
            long double xd=ceil(cur/3);
            ans+=xd;
        }
        cout<<ans<<"\n";
    }
}