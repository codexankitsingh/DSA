class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        int m = mat.size();
        int n = mat[0].size();
        int size = m*n;
        vector<pair<int,int>> v(size+1,{-1,-1});
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp = mat[i][j];
                v[temp].first = i+1;
                v[temp].second = j+1;
            }
        }
        for(int i=0;i<arr.size();i++){
            int temp = arr[i];
           // cout<<temp<<endl;
            int r,c;
            r = v[temp].first;
            c = v[temp].second;
            row[r]++;
            col[c]++;
            cout<<row[r]<<" "<<col[c]<<endl;
            if(row[r] == n || col[c] == m){
                return i;
            }
            
        }
        return 0;
    }
};