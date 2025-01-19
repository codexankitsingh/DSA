#include<bits/stdc++.h>
using namespace std;
int main(){
   priority_queue<int> p;
   vector<int> v = {1,3,-1,-3,5,3,6,7};
   for(int i=0;i<v.size();i++){
        p.push(v[i]);
   }
   while(! p.empty()){
    cout<<p.top()<<" ";
    p.pop();
   }
 
return 0;
}