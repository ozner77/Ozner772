#include <bits/stdc++.h>
using namespace std;
#define ll long long
string binary(ll x){
    string ans="";
    while(x>1){
        ans+=to_string(x%2);
        x/=2;
    }
    ans+=to_string(x);
    reverse(ans.begin(),ans.end());
    return ans;
}
ll ODIO(ll k){
    ll ans=1;
    for(int i=0;i<k;i++){
        ans*=2;
    }
    return ans;
}
int main(){
    ll q;
    cin>>q;
    vector<vector<ll>> adj(40,vector<ll>(40));
    for(int i=0;i<q;i++){
        char c;
        cin>>c;
        ll a;
        cin>>a;
        ll prev=0;
        for(int i=1;i<20;i++){
            ll node=i*2;
            adj[prev][node]+=1e15;
            prev=node;
        }
        if(c=='+'){
            string xd=binary(a);
            ll diff=20-xd.size();
            string uwunt="";
            for(int i=0;i<diff;i++){
                uwunt+='0';
            }
            xd=uwunt+xd;
            ll prev=xd[0]-'0';
            for(int i=1;i<20;i++){
                ll node=i*2;
                if(xd[i]=='1'){
                    node++;
                }
                if(prev%2==1 || node%2==1){
                    adj[prev][node]++;
                }
                prev=node;
            }
        }else if(c=='-'){
            string xd=binary(a);
            ll diff=20-xd.size();
            string uwunt="";
            for(int i=0;i<diff;i++){
                uwunt+='0';
            }
            xd=uwunt+xd;
            ll prev=xd[0]-'0';
            for(int i=1;i<20;i++){
                ll node=i*2;
                if(xd[i]=='1'){
                    node++;
                }
                if(prev%2==1 || node%2==1){
                    adj[prev][node]--;
                }
                prev=node;
            }
        }else{
            string xd=binary(a);
            ll diff=20-xd.size();
            string uwunt="";
            for(int i=0;i<diff;i++){
                uwunt+='0';
            }
            xd=uwunt+xd;
            ll prev=xd[0]-'0';
            string besti;
            besti+=xd[0];
            for(int i=1;i<20;i++){
                ll node=i*2;
                if(xd[i]=='1'){
                    node++;
                }
                if(prev%2==1 || node%2==1){
                    if(adj[prev][node]>0){
                        besti+=to_string(node%2);
                    }else{
                        besti+=to_string((node+1)%2);
                    }
                }else{
                    besti+='0';
                }
            }
            ll valor=0;
            for(int i=19;i>=0;i--){
                ll jeje=besti[19-i]-'0';
                valor+=ODIO(i)*jeje;
            }
            ll respuesta=valor^a;
            cout<<respuesta<<"\n";
        }
    }
}
