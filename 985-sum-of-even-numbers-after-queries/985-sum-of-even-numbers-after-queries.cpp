class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      
      int sum = 0;
      vector<int> A;
      
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (!(nums[i] % 2))
        {
          sum += nums[i];
        }
      }
      
      for (int i = 0; i < queries.size(); i++)
      {
        int val = queries[i][0];
        int index = queries[i][1];
        
        int prev_val = nums[index];
        int new_val = nums[index] + val;
        nums[index] = new_val;
        if (!(prev_val % 2))
        {
          sum -= prev_val;
        }
        if (!(new_val % 2))
        {
          sum += new_val;
        }
        A.push_back(sum);
      }
      return A;
    }
};