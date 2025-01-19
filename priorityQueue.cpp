#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &v, vector<int> &ans, int k) {
    deque<int> dq;

    for(int i =0;i<v.size();i++){
        // if the element get out of window
        if(!dq.empty() && dq.front()== i-k){
            dq.pop_front();
        }
        
    }

}

int main(){
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   vector<int> ans;
    maxSlidingWindow(v,ans,3);
   for(auto &x: ans){
    cout<<x<<" ";
   }

 
return 0;
}