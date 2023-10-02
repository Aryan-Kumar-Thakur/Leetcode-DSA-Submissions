class Solution
{
    public:
        string removeDuplicateLetters(string s)
        {
            stack<int> st;
            map<char, int> mp;
            map<char, bool> present;
            for (auto it: s)
            {
                mp[it]++;
            }
            for (auto it: s)
            {
                if ((st.empty() || it > st.top()) && !present[it])
                {
                    st.push(it);
                    present[it] = true;
                    mp[it]--;
                }
                else if (st.top() > it && !present[it])
                {
                    while (!st.empty() && st.top() > it && mp[st.top()] > 0)
                    {
                        present[st.top()] = false;
                        st.pop();
                    }
                    st.push(it);
                    present[it] = true;
                    mp[it]--;
                }
                else
                {
                    mp[it]--;
                }
            }
            string ans = "";
            while (!st.empty())
            {
                ans += st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};