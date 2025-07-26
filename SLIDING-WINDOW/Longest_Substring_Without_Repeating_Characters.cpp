/*Brute Force Solution  T.C -O(n^2) S.C-O(n)*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();

        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> m;
            for(int j=i;j<n;j++)
            {
                if(m.find(s[j])!=m.end())
                {
                    break;
                }

                m[s[j]]++;
                ans=max(ans,j-i+1);

            }
        }

        return ans;
        
    }
};




/* SLIDING WINDOW APPROACH   T.C-O(n) S.c O(n)*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();

        unordered_map<int,int> m;
        int i=0;
        int j=0;
        int ans=0;

        while(j<n)
        {
            m[s[j]]++;

            while(m[s[j]]>1)
            {
                m[s[i]]--;
                i++;
            }


            ans=max(ans,j-i+1);
            j++;

        }
        

        return ans;
        
    }
};