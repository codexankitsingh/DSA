//Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

#include<bits/stdc++.h>
using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size();
    int n = nums2.size();
    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));
    int maxLen = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(nums1[i-1] == nums2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }
    return maxLen;
}
int main(){
   int n;
   cin>>n;
   vector<int> num1,num2;
   for(int i=0;i<n;i++){
    cin>>num1[i];
   }
   for(int i=0;i<n;i++){
    cin>>num2[i];
   }

 
return 0;
}