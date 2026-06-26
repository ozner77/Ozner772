#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define ll long long
int main(){
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll posx=x1;
    ll posy=y1;
    map<char,ll> M,M2;
    M['U']=1;
    M['D']=-1;
    M2['L']=-1;
    M2['R']=1;
    ll init=abs(x2-x1)+abs(y2-y1);
    for(int i=0;i<n;i++){
        posx+=M2[s[i]];
        posy+=M[s[i]];
    }
        ll avanzarx=posx-x1;
        ll avanzary=posy-y1;
        ll l=1;
        ll r=1e18;
        while(l<r){
            ll mid=(l+r)/2;
            ll ciclos = mid / n;
            ll xd = mid % n;
            ll posix = x1 + avanzarx * ciclos; 
            ll posiy = y1 + avanzary * ciclos;
            for(int i = 0; i < xd; i++){
                posix += M2[s[i]];
                posiy += M[s[i]];
            }
            ll diff = abs(x2 - posix) + abs(y2 - posiy);
            if(mid >= diff){ 
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(l==1e18){
            cout<<-1;
        }else{
            cout<<l;
        }
    }