#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int maxn = 1e5+1;
 
int bit[maxn];
 
ll fun(ll n){
    ll ret=1;
    ll cnt=0;
    if(n%2==0){
        while(n%2==0){
            cnt++;
            n/=2;
        }
    }
    ret*=(cnt+1);
    for(ll i=3;i<=sqrt(n);i+=2){
        if(n%i==0){
            cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            ret*=(cnt+1);
        }
    }
    if(n!=1){
        ret*=2;
    }
    return ret;
}
 
void update(ll idx,ll val){
    while(idx<=1e5){
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
}
 
int query(int idx){
    ll ret=0;
    while(idx>0){
        ret+=bit[idx];
        idx-=(idx&(-idx));
    }
    return ret;
}
 
ll binary(ll l,ll r,ll k){
    ll ans;
    while(l<=r){
        ll m = (l+r)/2;
        ll temp = query(m);
        if(temp < k){
            l=m+1;
        }
        else{
            ans=m;
            r=m-1;
        }
    }
    update(ans,-1); 
    return fun(ans);
}
 
int main(){
 
    
    int t;
 
    cin>>t;
    memset(bit,0,sizeof(bit));
    while(t--){
        int ty,p;
        cin>>ty>>p;
        if(ty==1){
            // ll ge=fun(p);
          
            update(p,1);
        }
        else{
            cout<<binary(1,1e5,p)<<endl;
        }
    }
    
    return 0;
}
