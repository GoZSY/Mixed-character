/************************************************************************
思路： 动态规划：
令D[i][j]代表A中取前i个字符，B中取前j个字符，是否和C中的前i+j个字符交错匹配。
1. 如果i==0 或者j == 0,那么退化为单独的一个字符串是否和C匹配
   因此：
   D[i][0] = A(i-1) == C(i-1);  1<=i<=A.length
D[0][j] = B(j-1) == C(j-1); 1<=j<=B.length
2.
求D[i][j],分两种情况A[i-1] == C[i+j-1]或者B[j-1] == C[i+j-1]
D[i][j] = D[i-1][j] && A[i-1] == C[i+j-1]
D[i][j] = D[i][j-1] && B[j-1] == C[i+j-1]
因此状态转移方程：
D[i][j] = D[i-1][j] && A[i-1] == C[i+j-1] || D[i][j-1] && B[j-1] == C[i+j-1] 
*****************************************************************************/
class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) 
    {
        // write code here]
        if((n+m)!=v)
            return false;
      	if(v==0)
            return true;
        vector<vector<bool> > dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;    
        for(int i = 1; i <= m; ++i)
        {
            
            dp[0][i] = B[i-1] == C[i-1];
        }   
        for(int i = 1; i <=n; ++i)
        {
            dp[i][0] = A[i-1] == C[i-1];
        }         
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
        {
            if((dp[i-1][j]==true&&A[i-1]==C[i+j-1])||(dp[i][j-1]==true&&B[j-1]==C[i+j-1]))
            {
                dp[i][j] = true;
            }
        }
        return dp[n][m];
    }
};

class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) 
    {
        // write code here]
        if((n+m)!=v)
            return false;
      	if(v==0)
            return true;
        vector<bool > dp(m+1, false);
        dp[0] = true;    
        for(int i = 1; i <= m; ++i)
        {
            dp[i] = (B[i-1] == C[i-1]);
        }   
        for(int i = 0; i < n; ++i)
            for(int j = 1; j <= m; ++j)
        {
            dp[j] = (dp[j]&&A[i]==C[i+j])||(dp[j-1]&&B[j-1]==C[i+j]);
        }
        return dp[m];
    }
};
