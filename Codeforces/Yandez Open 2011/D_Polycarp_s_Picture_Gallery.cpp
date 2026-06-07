#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> V;
    priority_queue<pair<ll,ll>> Q;
    for(int i=0;i<m;i++){
        ll a;
        cin>>a;
        V.push_back(a);
        Q.push({a,i+1});
    }
    ll anterior=-1;
    vector<ll> ans;
    ll primero;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(Q.empty()){
            cout<<-1;
            return 0;
        }
        ll color=Q.top().second;
        ll cantidad=Q.top().first;
        if(i==0){
            primero=color;
        }
        if(color==primero && i==n-1){
            Q.pop();
            if(Q.empty()){ 
                if(color!=ans[ans.size()-2] && color!=ans[ans.size()-1]){
                    swap(color,ans[ans.size()-1]);
                    ans.push_back(color);
                    break;
                }
                cout<<-1;
                return 0;
            }else{
                color=Q.top().second; 
                cantidad=Q.top().first;
            }
        }
        if(color!=anterior){
            ans.push_back(color);
            Q.pop();
            if(cantidad-1>0){
                Q.push({cantidad-1,color});
            }
            anterior=color;
        }else{
            if(Q.size()==1){
                cout<<-1;
                return 0;
            }else{
                pair<ll,ll> temp=Q.top();
                Q.pop();
                color=Q.top().second;
                cantidad=Q.top().first;
                ans.push_back(color);
                Q.pop();
                if(cantidad-1>0){
                    Q.push({cantidad-1,color});
                }
                Q.push(temp);
                anterior=color;
            }
        }
    }
    for(ll x: ans){
        cout<<x<<" ";
    }
}