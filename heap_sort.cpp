#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &v,int n,int ind){
    int largest = ind;
    int left = 2*ind;
    int right = 2*ind + 1;
    if(left<= n && v[left]> v[largest]){
        largest = left;
    }
    if(right <=n && v[right]>v[largest]){
        largest = right;
    }
    if(v[largest]> v[ind]){
        swap(v[ind],v[largest]);
        heapify(v,n,largest);
    }
    return;
}
void heapsort(vector<int> &v,int n){
  int size = n;

  while(size>1){
      // step 1 : swap the top element
      swap(v[1],v[size]);
      // step 2: heapify the elements;
      heapify(v,size-1,1);
      size--;
  }
}
int main(){
   vector<int> v;
   v= {-1,55, 54,53,50,52};
   heapsort(v,5);
   for(int i=1;i<=v.size();i++){
        cout<<v[i]<<endl;
   }
 
return 0;
}