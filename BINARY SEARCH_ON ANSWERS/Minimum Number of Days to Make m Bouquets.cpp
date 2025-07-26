class Solution {
public:
    bool solve_(vector<int> &bloomDay,int m,int k,int mid)
    {
        int n=bloomDay.size();
        int count=0;
        int ans=0;
        int i=0;

        while(i<n)
        {
            if(bloomDay[i]<=mid)
            {
                count++;
                
            }

            else
            {
                ans+=count/k;
                count=0;
            }

            i++;
            
        }


        if(ans>=m)
        {
            return true;
        }

        return false;

    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        int min_=*min_element(bloomDay.begin(),bloomDay.end());
        int max_=*max_element(bloomDay.begin(),bloomDay.end());

        long long int x=(long long int)m*k;

        if(n<x)
        {
            return -1;
        }

        int i=min_;
        int j=max_;

        int mid=i+(j-i)/2;

        while(i<j)
        {
            if(solve_(bloomDay,m,k,mid))
            {
                j=mid;
            }
            else
            {
                i=mid+1;
            }


            mid=i+(j-i)/2;
        }


        return j;
        
    }
};