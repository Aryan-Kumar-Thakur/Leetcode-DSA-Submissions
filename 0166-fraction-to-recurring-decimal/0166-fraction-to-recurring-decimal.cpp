class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
      if (numerator == 0)
            return "0";

        string ans;
        if ((numerator > 0) ^ (denominator > 0))
            ans += "-";
        // cout << "ans : " << ans << endl;

        long n = labs(numerator);
        long d = labs(denominator);
        long r = n % d;
        ans += to_string(n / d);
        // cout << "ans : " << ans << endl;

        if (r == 0)
            return ans;

        ans += ".";
        // cout << "ans : " << ans << endl;
        unordered_map<long, int> m;
        while (r)
        {
            // cout << "rem : " << r << endl;
            if (m.find(r) != m.end())
            {
                ans.insert(m[r], "(");
                ans += ")";
                // cout << "ans : " << ans << endl;
                break;
            }

            m[r] = ans.size();
            // cout << "m[r] : " << m[r] << endl;
            r = r * 10;
            ans += to_string(r / d);
            // cout << "ans : " << ans << endl;
            r = r % d;
        }
        return ans;
    }
};