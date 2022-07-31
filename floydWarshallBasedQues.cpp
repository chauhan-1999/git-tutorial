#include<bits/stdc++.h>
using namespace std;
//Greg and array 
//using floyd warshall algo
int main(){
         int n;cin>>n;
         long long dist[n+1][n+1];
         for(int i=1;i<=n;i++){
                  for(int j=1;j<=n;j++){
                           cin>>dist[i][j];
                  }
         }
         vector<int>del_order(n);//deleltion vertex order
         for(int i=0;i<n;i++)
         cin>>del_order[i];
         reverse(del_order.begin(),del_order.end());//adding vertex order
         vector<long long>ans;
         for(int k=0;k<n;k++){
                  int k_v=del_order[k];
                  for(int i=1;i<=n;i++){
                           for(int j=1;j<=n;j++){
                                    long long mindist=dist[i][k_v]+dist[k_v][j];
                                    dist[i][j]=min(dist[i][j],mindist);
                           }
                  }
                  long long sum=0;
                  for(int i=0;i<=k;i++){
                           for(int j=0;j<=k;j++){
                                sum+=dist[del_order[i]][del_order[j]];    
                           }
                  }
                  ans.push_back(sum);
         }
         reverse(ans.begin(),ans.end());//deletion order
         for(auto &x:ans){
                  cout<<x<<endl;
                  
         }
         return 0;
}
