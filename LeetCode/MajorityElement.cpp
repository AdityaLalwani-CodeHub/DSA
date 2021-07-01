//Second Try
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        //find the candidate
        int maj_index = 0;
        int count = 1;
        for(int i = 1 ; i < n ; i++)
        {
            if(nums[i] == nums[maj_index])
                count++;
            else
                count--;
            
            if(count == 0)
            {
                maj_index = i;
                count = 1;
            }
        }
        
        count = 0;
        //check for majority elemnt
        for(auto &i: nums)
        {
            if(i == nums[maj_index])
                count++;
        }
        if(count > n/2)
            return nums[maj_index];
        else
            return -1;
    }
};


/*
//First Try
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
};*/