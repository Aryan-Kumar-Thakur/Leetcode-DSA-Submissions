class Solution
{
    public:
        string longestPalindrome(string s)
        {
            int ini = 0, len = INT_MIN;
            int n = s.size();
            int lo,hi;
            for (int i = 0; i < n; i++)
            {
             lo=i-1;
             hi=i+1;
            while(lo>=0 && s[i]==s[lo]){
                lo--;
            }
            while(hi<n && s[i]==s[hi]){
                hi++;
            }
            while(lo>=0 && hi<n && s[lo]==s[hi]){
                lo--;
                hi++;
            }
            if(hi-lo-1 > len){
                len=hi-lo-1;
                ini=lo+1;
            }
        }
            //     l = i - 1;
            //     r = i + 1;
            //     while (l >= 0 && s[i] == s[l])
            //     {
            //         l--;
            //     }
            //     while (r < n && s[r] == s[i])
            //     {
            //         r++;
            //     }
            //     while (l >= 0 && r < n && s[l] == s[r])
            //     {
            //         l++;
            //         r++;
            //     }
            //     if ((r - l - 1) > len)
            //     {
            //         len = (r - l - 1);
            //         ini = l + 1;
            //     }

            return s.substr(ini,len);
        }
};