/*This is an classic 1-D DP solution simply based on taken nottaken approch      T.C:-O(n) S.C:-O(n)*/

class Solution {
public:
    vector<int> v;
    int solve_(int i,vector<int> &nums,int n)
    {
        if(i>=n)
        {
            return 0;
        }

        if(v[i]!=-1)
        {
            return v[i];
        }

        
        int taken=nums[i] + solve_(i+2,nums,n);
        int nottaken=0+solve_(i+1,nums,n);

        return v[i]=max(taken,nottaken);
    }


    int rob(vector<int>& nums) {
        int n=nums.size();

        v.assign(n,-1);
        return solve_(0,nums,n);

        
    }
};