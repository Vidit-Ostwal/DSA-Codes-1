class Solution {
  vector<vector<vector<long long>>> DP;
  long long Recursive_Solution(vector<int>& A, int index, int curr_maxi, int part)
  {
    if (part < 0)
      return INT_MAX;
    
    if (index == A.size())
    {
      if (part || curr_maxi == INT_MIN)
        return INT_MAX;
      else
        return curr_maxi;
    }
    
    int temp = (curr_maxi == INT_MIN) ? 1001 : curr_maxi;
    
    if (DP[index][part][temp] != -1)
      return DP[index][part][temp];
    
    curr_maxi = max(curr_maxi,A[index]);
    return DP[index][part][temp] = min(Recursive_Solution(A, index+1, curr_maxi,part), curr_maxi + Recursive_Solution(A, index+1,INT_MIN,part-1)); 
  }
public:
    int minDifficulty(vector<int>& A, int d) {
      DP = vector<vector<vector<long long>>> (A.size(),vector<vector<long long>>(11,vector<long long>(1002,-1)));
      if (d > A.size())
          return -1;
      
      return Recursive_Solution(A,0,INT_MIN,d-1);
    }
};