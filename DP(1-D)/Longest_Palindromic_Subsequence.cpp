/*https://leetcode.com/problems/longest-palindromic-substring*/


/*Brute Force Solution   T.C:-o(n^3)*/

class Solution {
public:
    bool check_(string &s)
    {
        int n=s.length();

        int i=0;
        int j=n-1;

        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }


    string longestPalindrome(string s) {
        int n=s.length();
        int maxi=INT_MIN;
        string ans;

        for(int i=0;i<n;i++)
        {
            string temp;
            for(int j=i;j<n;j++)
            {
                temp.push_back(s[j]);
                if(check_(temp))
                {
                    int x=temp.length();
                    if(x>maxi)
                    {
                        ans=temp;
                        maxi=x;
                    }
                }

            }
        }


        return ans;


    }
};

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/


 /*DP solution(Top Down Memoization) T.C:-O(n^2) S.C:-O(n^2)*/

class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string &s,int l,int r)
    {
        if(l>=r)
        {
            return true;
        }

        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }

        if(s[l]==s[r])
        {
            return dp[l][r]=solve(s,l+1,r-1);
        }

        return dp[l][r]=false;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        dp.assign(n+1,vector<int>(n+1,-1));
        string ans="";
        int maxlen=0;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(solve(s,i,j))
                {
                    if((j-i+1)>maxlen)
                    {
                        ans=s.substr(i,j-i+1);
                        maxlen=j-i+1;
                    }

                }
                
            }
        }



        return ans;

        
    }
};


/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/*TWO POINTERS APPROACH (Expand from mid   T.C:-o(n^2) S.C:-o(1))*/

class Solution {
public:

    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0)
        {
            return "";
        }
        string ans="";
        int maxi=0;

        for(int i=0;i<n;i++)
        {
            int l=i;
            int r=i;

            while(l>=0 && r<n && s[l]==s[r])
            {
                if((r-l+1)>maxi)
                {
                    ans=s.substr(l,r-l+1);
                    maxi=r-l+1;
                }
                l--;
                r++;
            }


            l=i;
            r=i+1;

            while(l>=0 && r<n && s[l]==s[r])
            {
                if((r-l+1)>maxi)
                {
                    ans=s.substr(l,r-l+1);
                    maxi=r-l+1;
                }
                l--;
                r++;
            }
        }

        return ans;


    }
};



