#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll k;
    cin>>k;
    vector<vector<ll>> V;
    for(int i=0;i<k;i++){
        ll n;
        cin>>n;
        vector<ll> L;
        for(int j=0;j<n;j++){
            ll a;
            cin>>a;
            L.push_back(a);
        }
        V.push_back(L);
    }
    vector<pair<ll,ll>> L;
    ll color=1;
    ll palos=0;
    for(auto &x:V){
        sort(x.begin(),x.end());
        for(auto y:x){
            palos++;
            L.push_back({y,color});
        }
        color++;
    }
    sort(L.begin(),L.end());
    reverse(L.begin(),L.end());
    pair<ll,ll> l1,l2,l3;
    ll ind=0;
    while(palos>=3){
        l1=L[ind];
        l2=L[ind+1];

        while(l1.second==l2.second){
            if(palos<3){
                cout<<"NIE\n";
                return 0;
            }
            ind++;
            l1=L[ind];
            l2=L[ind+1];
            palos--;
        }
        if(L[ind+2].first+l2.first<l1.first){
            ind++;
            palos--;
            continue;
        }
        ll xd=abs(l1.first-l2.first);
        ll coloro=1;
        for(auto &x:V){
            if(coloro!=l1.second && coloro!=l2.second){
                auto maxii=lower_bound(x.begin(),x.end(),l2.first);
                auto it=upper_bound(x.begin(),x.end(),xd);
                if(it!=x.end()){
                    if(maxii!=x.begin()){
                        maxii--;
                        if(*it<=*maxii){
                            cout<<l1.second<<" "<<l1.first<<" "<<l2.second<<" "<<l2.first<<" "<<coloro<<" "<<*it;
                            return 0;
                        }
                    }
                }
            }
            coloro++;
        }
        ind++;
        palos--;
    }
    cout<<"NIE";
}