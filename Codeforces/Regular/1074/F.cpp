#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,p;
        cin>>n>>p;
        vector<vector<ll>> levels(n+1);
        ll xd=1;
        for(int i=0;i<n;i++){
            xd*=2;
        }
        for(int i=0;i<xd;i++){
            ll a;
            cin>>a;
            levels[0].push_back(a);
        }
        ll level=1;
        while(true){
            if(levels[level-1].size()==1){
                break;
            }
            for(int i=0;i<levels[level-1].size();i+=2){
                levels[level].push_back(levels[level-1][i]^ levels[level-1][i+1]);
            }
            level++;
        }
        for(int i=0;i<p;i++){
            level=0;
            ll a,b;
            cin>>a>>b;
            ll ans=0;
            ll cur=b;
            ll curpos=a;
            ll PUM=1;
            while(true){
                if(levels[level].size()==1){
                    break;
                }
                if(curpos%2==0){
                    if(cur>levels[level][curpos-2]){
                        cur=cur^levels[level][curpos-2];
                    }else{
                        cur=cur^levels[level][curpos-2];
                        ans+=PUM;
                    }
                    curpos/=2;
                }else{
                    if(cur>=levels[level][curpos]){
                        cur=cur^levels[level][curpos];
                    }else{
                        cur=cur^levels[level][curpos];
                        ans+=PUM;
                    }
                    curpos++;
                    curpos/=2;
                }
                level++;
                PUM*=2;
            }
            cout<<ans<<"\n";
        }
    }
}
//^ 