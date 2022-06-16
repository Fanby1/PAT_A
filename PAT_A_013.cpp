
#include<iostream>
#include<algorithm>
using namespace std;
bool vis[1001];
int G[1001][1001];
int n;
void dfs(int node){
  vis[node]=true;
  for(int i=1;i<=n;i++){
     if(vis[i]==false&&G[node][i]==1){
     dfs(i);
  }
}
 
}
int main(){
  int m,k;
  scanf("%d%d%d", &n, &m, &k);
  int u,v;
  for(int i=0;i<m;i++){
    scanf("%d%d", &u, &v);
    G[u][v]=G[v][u]=1;
  }
  for(int i=0;i<k;i++){
    fill(vis,vis+1001,false);
    int a;
    scanf("%d",&a);
    vis[a]=true;
    int cnt=0;
    for(int j=1;j<=n;j++){
      if(vis[j]==false){
        dfs(j);
        cnt++;
      }
    }
     printf("%d\n",cnt-1);
  }
  return 0;
}
