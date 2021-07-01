//Majority element - First Try
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> count;
        int maxCount = 0,maxKey = -1;
        for(auto i : nums)
        {
            count[i]++;
            if(count[i] > maxCount)
            {
                maxCount = count[i];
                maxKey = i;
            }
        }
                
        int n = nums.size();
        
        if(maxCount > floor(n/2))
            return maxKey;
        
        return -1;
    }
};