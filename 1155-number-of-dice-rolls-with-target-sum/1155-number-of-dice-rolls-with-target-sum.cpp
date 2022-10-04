class Solution {
  int MOD = pow(10,9) + 7;
  bool flag = true;
  vector<vector<int>> DP;
public:
    int numRollsToTarget(int n, int k, int target) {
      if (n == 0)
        return (target) ?  0 : 1;
      
      if (target <= 0)
        return 0;
      
      if (flag)
      {
        flag  = !flag;
        DP = vector<vector<int>>(n+1,vector<int>(target+1,-1));
      }
      
      if (DP[n][target] != -1)
        return DP[n][target];
      
      long long answer = 0;
      for (int i = 1; i <= k; i++)
      {
        answer += numRollsToTarget(n-1,k,target - i);
        answer = answer % MOD;
      }
      return DP[n][target] = answer;
    }
};