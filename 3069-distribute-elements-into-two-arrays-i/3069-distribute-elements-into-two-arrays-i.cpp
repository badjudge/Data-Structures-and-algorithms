class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        
        // 1. Base case: push the first two elements using correct 0-indexing
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        // 2. Distribute the remaining elements starting from index 2
        for(int i = 2; i < nums.size(); i++){
            if(arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        
        // 3. Clear nums and overwrite it sequentially to preserve order
        nums.clear();
        nums.insert(nums.end(), arr1.begin(), arr1.end());
        nums.insert(nums.end(), arr2.begin(), arr2.end());
        
        return nums;
    }
};
