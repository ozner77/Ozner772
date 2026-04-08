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
        if(n==1){
            cout<<1<<"\n";
            continue;
        }
        if(s.size()%2==0){
            map<ll,ll> par,impar;
            for(int i=0;i<n;i+=2){
                impar[s[i]-'a']++;
            }
            for(int i=1;i<n;i+=2){
                par[s[i]-'a']++;
            }
            ll maxipar=0,maxiimpar=0;
            for(auto x:par){
                maxipar=max(maxipar,x.second);
            }
            for(auto x:impar){
                maxiimpar=max(maxiimpar,x.second);
            }
            ll ans=0;
            ans+=(n/2-maxipar);
            ans+=(n/2-maxiimpar);
            cout<<ans<<"\n";
            continue;
        }
        vector<vector<ll>> pp(n,vector<ll>(26,0)),pi(n,vector<ll>(26,0)),sp(n,vector<ll>(26,0)),si(n,vector<ll>(26,0));
        pi[0][s[0]-'a']=1;
        sp[n-1][s[n-1]-'a']=1;
        for(int i=1;i<n-1;i++){
            if(i%2==0){
                pi[i][s[i]-'a']=1;
                sp[n-1-i][s[n-1-i]-'a']=1;
            }else{
                pp[i][s[i]-'a']=1;
                si[n-1-i][s[n-1-i]-'a']=1;
            }
            for(int j=0;j<26;j++){
                pi[i][j]+=pi[i-1][j];
                pp[i][j]+=pp[i-1][j];
                sp[n-1-i][j]+=sp[n-1-i+1][j];
                si[n-1-i][j]+=si[n-1-i+1][j];
            }
        }
        pi[n-1][s[n-1]-'a']=1;
        sp[0][s[0]-'a']=1;
        for(int i=0;i<26;i++){
            pi[n-1][i]+=pi[n-2][i];
            sp[0][i]+=sp[1][i];
            pp[n-1][i]+=pp[n-2][i];
            si[0][i]+=si[1][i];
        }
        ll ans=1e18;
        for(int i=1;i<n-1;i++){
            ll tempar=0;
            ll tempimpar=0;
            for(int j=0;j<26;j++){
                tempimpar=max(tempimpar,pi[i-1][j]+si[i+1][j]);
                tempar=max(tempar,pp[i-1][j]+sp[i+1][j]);
            }
            ll temp = (n/2 - tempar) + (n/2 - tempimpar);
            ans=min(ans,temp);
        }
        ll tempar=0;
        ll tempimpar=0;
        for(int j=0;j<26;j++){
            tempimpar=max(tempimpar,si[1][j]);
            tempar=max(tempar,sp[1][j]);
        }
        ll temp = (n/2 - tempar) + (n/2 - tempimpar);
        ans=min(ans,temp);
        tempar=0;
        tempimpar=0;
        for(int j=0;j<26;j++){
            tempimpar=max(tempimpar,pi[n-2][j]);
            tempar=max(tempar,pp[n-2][j]);
        }
        temp = (n/2 - tempar) + (n/2 - tempimpar);
        ans=min(ans,temp);

        cout<<ans+1<<"\n";
    }
}