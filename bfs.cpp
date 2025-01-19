#include<bits/stdc++.h>
using namespace std;
void bfs(int root,vector<int> &visited,vector<vector<int> > & adj){
    queue<int> q;
    visited[root] = 1;
    q.push(root);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto temp:adj[node]){
            if(visited[temp] != 1){
                q.push(temp);
                visited[temp] = 1;
            }
        }
    }
}
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
 cout<<"hello world"<<endl;
   
   
return 0;
}