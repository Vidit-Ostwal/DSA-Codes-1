class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
      long long count  = 0;
      int st = 0;
      int ed = 0;
      map<int,int> mini_map;
      map<int,int,greater<int>> maxi_map;
      
      while (ed < nums.size())
      {
        mini_map[nums[ed]] = ed;
        maxi_map[nums[ed]] = ed;
          
        while (ed < nums.size())
        {
          mini_map[nums[ed]] = ed;
          maxi_map[nums[ed]] = ed;
          
          if (mini_map.begin() -> first == minK && maxi_map.begin() -> first == maxK)
          {
            int mini = min(mini_map.begin() -> second,maxi_map.begin() -> second);
            count += (mini - st + 1);
          }
          if (mini_map.begin() -> first < minK || maxi_map.begin() -> first > maxK)
          {
            break;
          }
          ed++;
        }
        ed++;
        st = ed;
        mini_map.clear();
        maxi_map.clear();
        
      }
      return count;
    }
};