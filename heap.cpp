#include<bits/stdc++.h>
using namespace std;
// implementation of heaps using arr/vector DS
class heap{
    public:
    int size ;
    vector<int> h;

    heap(){
        h.push_back(-1);
        size =0;
    }
    // class function for inserting an element in max_heap
    void insert(int val){
        h.push_back(val);
        size++;
        int ind = size;
        while(ind>1){
            int parent = ind/2;
            if(h[ind]>h[parent]){
                swap(h[ind],h[parent]);
                ind = parent;
            }else return;
        }
    }
    // class function to delete root element form max_heap
    void deletion(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
            return; 
        }else{
            swap(h[1],h[size]);
            size--;
            int i=1;
            while(i<=size){
                int left_child_ind = i*2;
                int right_child_ind = i*2 + 1;

                if(left_child_ind<=size){
                    int max_child_ind = left_child_ind;
                    if(right_child_ind <= size && h[right_child_ind]> h[left_child_ind]){
                        max_child_ind = right_child_ind;
                    }
                    if(h[i]<h[max_child_ind]){
                        swap(h[i],h[max_child_ind]);
                        i = max_child_ind;
                    }else return;
                }else return;
               
            }

        }
        return;
    }

    void print(){
    for(int i=1;i<=size;i++){
        cout<<h[i]<<" ";
    }cout<<endl;
    return;}

};
    // heapify 
    void heapify(vector<int> &h,int size,int ind){
        int largest = ind;
        int left = ind*2;
        int right = ind*2 + 1;
        if(left<=size && h[left]>h[largest]){
            largest = left;
        }
        if(right<=size && h[right]>h[largest]){
            largest = right;
        }
        if(largest != ind){
            swap(h[ind],h[largest]);
            heapify(h,size,largest);
        }
        return;
    }



int main(){
    int n;
    cin>>n;
    vector<int> v(n+1,-1);
    // heap h;
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    //     h.insert(v[i]);
    // }
    // h.print();
    // h.deletion();
    // h.print();

    for(int i=1;i<n+1;i++){
        cin>>v[i];
    }
    for(int i=n/2;i>0;i--){
        heapify(v,n,i);
    }
    for(auto &x: v){
        cout<<x<<" ";
    }
 
return 0;
}