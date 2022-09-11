class Solution {

public:
    int partitionString(string s) {
      
      int index = 0;
      int count = 0;
      while (index < s.length())
      {
        vector<int> temp(26,0);
        
        while (index < s.length())
        {
          temp[s[index]-'a']++;
          
          if (temp[s[index] - 'a'] == 2)
            break;
          
          index++;
        }
        count++;
      }
      return count;
    }
};