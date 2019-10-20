#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


struct p{
    ll x;
   ll y;
    ll z;
};

bool compare(pair<double,pair<ll,ll>> a,pair<double,pair<ll,ll>> b){
    return a.first <= b.first;
}

double mydistance(p a, p b){
    return double(sqrt(double(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2))));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll *p = new ll[n+1];
   for(ll i=0;i<n+1;i++) {
       p[i]=0;
   } 
    vector<pair<struct p , ll>> v;  
    for(int i=0;i<n;i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        v.push_back({{a,b,c},i+1});
    }    
    
    vector<pair<double,pair<ll,ll>>> v2;
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++) {
            v2.push_back({mydistance(v[i-1].first,v[j-1].first),{i,j}});
        }
    }

    sort(v2.begin(),v2.end(),compare);

    for(ll i=0;i<v2.size();i++){
        if(vis[v2[i].second.first]|| p[v2[i].second.second]) continue;
        cout<<v2[i].second.first<<" "<<v2[i].second.second<<endl;
        p[v2[i].second.first] = 1;
        p[v2[i].second.second] = 1;
    }
    return 0;
}
