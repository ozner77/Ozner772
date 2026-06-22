#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vector<vector<ll>> ans(n,vector<ll>(26));
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                ll con=0;
                char car=j+97;
                ll l=0;
                for(int k=0;k<n;k++){
                    if(s[k]!=car){
                        con++;
                    }
                    while(l<=k && con>(i+1)){
                        if(s[l]!=car){
                            con--;
                        }
                        l++;
                    }
                    ans[i][j]=max(ans[i][j],k-l+1);
                }
            }
        }
        ll q;
        cin>>q;
        for(int i=0;i<q;i++){
            ll a;
            char b;
            cin>>a>>b;
            ll val=b;
            val-=97;
            cout<<ans[a-1][val]<<"\n";
        }
}