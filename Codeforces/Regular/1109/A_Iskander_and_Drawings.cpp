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
        ll ans=0;
        ll len=0;
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                len++;
            }else{
                len=0;
            }
            ans=max(ans,len);
        }
        cout<<(ans+1)/2<<"\n";
    }
}