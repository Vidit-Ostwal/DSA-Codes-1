class Solution {
  int MOD = pow(10,9) + 7;
  int solve(vector<vector<int>> &grid, int K)
{
    long long N = grid.size();
    long long M = grid[0].size();

    vector<vector<vector<long long>>> dp(N,vector<vector<long long>>(M,vector<long long>(K,0)));

    for (long long i = 0; i < N; i++)
    {
        for (long long j = 0; j < M; j++)
        {
            long long element = grid[i][j]%K;
            if (i == 0  && j == 0)
            {
               dp[i][j][element]++;
               dp[i][j][element] = dp[i][j][element] % MOD;
            }
            else if (i == 0)
            {
                for (long long k = 0; k < K; k++)
                {
                    long long new_element = (element + k) % K;
                    dp[i][j][new_element] += dp[i][j-1][k] % MOD;
                    dp[i][j][element] = dp[i][j][element] % MOD;
                }
            }
            else if (j == 0)
            {
                for (long long k = 0; k < K; k++)
                {
                    long long new_element = (element + k) %K;
                    dp[i][j][new_element] += dp[i-1][j][k] % MOD;
                    dp[i][j][element] = dp[i][j][element] % MOD;
                }
            }
            else
            {
                for (long long k = 0; k < K; k++)
                {
                    long long new_element = (element + k) %K;
                    dp[i][j][new_element] += (dp[i-1][j][k] % MOD + dp[i][j-1][k] % MOD);
                    dp[i][j][element] = dp[i][j][element] % MOD;
                }
            }
        }
    }
    return dp[N-1][M-1][0] % MOD;
}
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        return solve(grid,k);
    }
};