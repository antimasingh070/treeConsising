#include<iostream>
using namespace std;
#include<bits/stdc++.h>
list<int> li[1000000];
int degree[1000000];
int visited[1000000];
int used[1000000];
int ans=0;
int k;

int dfs(int start)
 {
 visited[start]=1;
  list<int>:: iterator it;
     int  childs =0;
     
  for(it=li[start].begin();it!=li[start].end();it++)
   {
       if(!visited[*it])
        {
         // cout<<" starrt "<<start<<endl;
          visited[*it]=1;
          childs+=dfs(*it);
     }
   }
  if(childs+1>=k)
  {
  // cout<<"increment "<<endl;
   ans++;
   return 0;
  }
  else return childs+1;
 }


int main()
 {
  
  

cin>>k;
 int n;
 cin>>n;
  
  
  for(int i=2;i<=n;i++)
   {
      int a;
      cin>>a;
       //cout<<" pairing "<<i<<" and "<<a<<endl;
    li[a].push_back(i);
    li[i].push_back(a);
   }
  
  dfs(1);
  cout<<ans<<endl;

 }