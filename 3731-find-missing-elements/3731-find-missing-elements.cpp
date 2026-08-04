class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int size = nums[nums.size()-1];
        int start = nums[0];
        int x = 0;
        for(int i=start;  i<=size; i++){
            if(!(i==nums[x])){
                ans.push_back(i);
            }else{
                x++;
            }
        }

        return ans;
    }
};