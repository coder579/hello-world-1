#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;

    int inp[n],oup[n];

   for(int i=0;i<n;i++) cin>>inp[i];
   for(int i=0;i<n;i++) cin>>oup[i]; 

   int vis[n+1];
   for(int i=0;i<=n;i++) vis[i]=0;
    
   int ans=0,c1=0,c2=0;
   while(true){
       if(c1==n || c2==n) break;

       if(inp[c1]==oup[c2]){
          c1++;c2++; 
          vis[oup[c2]]=1;
       }
      else if(vis[inp[c1]]){
          c1++;
      } 
       else {
          if(vis[oup[c2]]==0){
              ans++;
          } 
         vis[oup[c2]]=1; 
          c2++;
       }
   }
    cout<<ans; 
    return 0;
}
