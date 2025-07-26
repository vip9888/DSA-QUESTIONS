
/*SLIDING WINDOW APPROACH   T.C-O(n) S.C-O(n)*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();

        unordered_map<int,int> m;

        int i=0;
        int j=0;
        int ans=0;
        int maxi=INT_MIN;

        while(j<n)
        {
            m[s[j]]++;

            maxi=max(maxi,m[s[j]]);

            while((j-i+1)-maxi>k)
            {
                m[s[i]]--;
                i++;
            }

            ans=max(j-i+1,ans);

            j++;
        }

        return ans;


          
        
    }
};