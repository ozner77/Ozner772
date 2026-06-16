#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string news="";
        ll ans=0;
        ll last=1e9;
        ll last2=-1;
        for(auto x:s){
            if(x=='4'){
                ans++;
            }else{
                news+=x;
            }
        }
        for(int i=0;i<news.size();i++){
            if(news[i]=='3' || news[i]=='1'){
                last=i;
                break;
            }
        }
        for(int i=news.size()-1;i>=0;i--){
            if(news[i]=='2'){
                last2=i;
                break;
            }
        }
        ll ansi1=0;
        ll ansi2=0;
        for(int i=last+1;i<news.size();i++){
            if(news[i]=='2'){
                ansi1++;
            }
        }
        for(int i=last2-1;i>=0;i--){
            if(news[i]=='1' || news[i]=='3'){
                ansi2++;
            }
        }
        ans=ans+min(ansi1,ansi2);
        cout<<ans<<"\n";
    }
}