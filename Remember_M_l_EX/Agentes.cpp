// NOTE: Do *NOT* write to stdout/stderr
#include "agentes.h"
#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long
using namespace std;
vector<int> encode(vector<string> agents) {
    vector<int> ids(agents.size());
    string uno="0";
    string dos="00";
    for(int i=0;i<agents.size();i++){
        string ans=to_string(i);
        if(i<10){
            ans=dos+ans;
        }else if(i<100){
            ans=uno+ans;
        }
        ans+=to_string(((ans[0]-'0')+(ans[1]-'0')) % 10);
        ans+=to_string(((ans[0]-'0')+(ans[2]-'0')) % 10);
        ans+=to_string(((ans[2]-'0')+(ans[1]-'0')) % 10);
        int xd=stoll(ans);
        ids[i]=xd;
    }
    return ids;
}
ll respuest(ll a,ll b,ll c){
    return a*100+b*10+c;
}
string decode(vector<string> agents, int id) {
    string xd=to_string(id);
    ll diff=6-xd.size();
    string hola="";
    for(int i=0;i<diff;i++){
        hola+='0';
    }
    xd=hola+xd;
    ll n1=(xd[0]-'0');
    ll n2=(xd[1]-'0');
    ll n3=(xd[2]-'0');
    ll n4=(xd[3]-'0');
    ll n5=(xd[4]-'0');
    ll n6=(xd[5]-'0');
    if((n1+n2)%10 != n4){
        if((n1+n3)%10 != n5){
            n1 = (n4 - n2 + 10) % 10;
            return agents[respuest(n1,n2,n3)];
        }
    }
    if((n2+n3)%10 != n6){
        if((n2+n1)%10 != n4){
            n2 = (n4 - n1 + 10) % 10;
            return agents[respuest(n1,n2,n3)];
        }
    }
    if((n1+n3)%10 != n5){
        if((n3+n2)%10 != n6){
            n3 = (n5 - n1 + 10) % 10;
            return agents[respuest(n1,n2,n3)];
        }
    }
    return agents[respuest(n1,n2,n3)];
}