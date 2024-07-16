#define ll long long
class Solution {
    bool solve(string s1,string s2){
        long long m=s1.size();
        long long n=s2.size();
        
        long long p = 31;
        long long pow = 1;
        long long mod = 1e9+7;
        long long targetHashVal = 0;
        
        // targetHashVal - calculate hash value of pattern
        for(long long i=0;i<n;i++){
            targetHashVal = (targetHashVal + (s2[i]-'a'+1)*pow)%mod;
            pow = (pow*p)%mod;
        }
        
        // Rabin-Karp algo :
        // prefix hash array
        vector<long long>pha(m);
        // power array : so that my time is not wasting in calculating big powers
        vector<long long>pa(m);
        
        pha[0] = s1[0]-'a'+1;
        pa[0] = 1;
        pow = p;
        
        for(long long i=1;i<m;i++){
            pha[i] = (pha[i-1] + (s1[i]-'a'+1)*pow)%mod;
            pa[i] = pow;
            pow = (pow*p)%mod;
        }
        
        //Now Start sliding window
        // initialize variables for the starting and ending points of window
        long long sp = 0, ep = n-1;
        
        while(ep < m)
        {
            long long win = pha[ep];
            if(sp>0)
                win = (win - pha[sp-1]+mod)%mod; // agar value negative hoti hai toh usme bas mod add kardo
            
            if(win == (targetHashVal*pa[sp])%mod){
                return 1;
            }
            sp++,ep++;
        }
        return 0;
    }
public:
    int repeatedStringMatch(string a, string b) {
        ll n=a.size();
        ll m=b.size();
        ll cnt=1;
        string temp=a;
        while(n<m){
            a+=temp;
            n=a.size();
            cnt++;
        }
        if(a==b){ 
            return cnt;
        }
        if(solve(a,b)){
            return cnt;
        }
        a+=temp;
        if(solve(a,b)){
            return cnt+1;
        }
        return -1;
    }
};