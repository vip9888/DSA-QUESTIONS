class Solution {
public:
    int solve_(int i,vector<int> &nums,int n,vector<int> &v)
    {
        if(i>=n)
        {
            return 0;
        }

        if(v[i]!=-1)
        {
            return v[i];
        }

        
        int taken=nums[i] + solve_(i+2,nums,n,v);
        int nottaken=0+solve_(i+1,nums,n,v);

        return v[i]=max(taken,nottaken);
    }


    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
        {
            return nums[0];
        }

        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);

        vector<int> v1(n-1);
        vector<int> v2(n-1);

        for(int i=1;i<n;i++)
        {
            v1[i-1]=nums[i];
        }

        for(int j=0;j<n-1;j++)
        {
            v2[j]=nums[j];
        }

        return max(solve_(0,v1,v1.size(),dp1),solve_(0,v2,v2.size(),dp2));
        
    }
};