class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> ans;
      vector<int> result;
      int n1=nums1.size();
      int n2=nums2.size();
      sort(nums2.begin(),nums2.end());
      for(int i=0;i<n1;i++){
        int low = 0;
        int high = n2-1;
        int mid = (low+high)/2;
        while(low<=high){
          mid = low+(high-low)/2;
          if(nums2[mid]==nums1[i]){
            ans.insert(nums1[i]);
            break;
          }
          if(nums2[mid]<nums1[i]){
            low=mid+1;
          }
          else{
            high=mid-1;
          }
        }
      }  
    for(int x:ans){
       result.push_back(x);
    }
    return result;
    }
};