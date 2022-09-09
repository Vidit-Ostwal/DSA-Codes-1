class Solution
{
  int Helper(vector<vector<int>> A)
  {
    queue<int> q;
    int count = 0;
    // map<int,int> map1;
    int maxi = -1;
    
    for (int i = A.size()-1; i >= 0 ; i--)
    {
      int attack = A[i][0];
      int defense = A[i][1];
      
      if (maxi > defense)
      {
        count++;
      }
      
      q.push(defense);
      if (i > 0 && A[i-1][0] != attack)
      {
        while (!q.empty())
        {
          // map1[q.front()]++;
          maxi  = max(maxi,q.front());
          q.pop();
        }
      }
    }
    return count;
  }
  
  
    public:
        int numberOfWeakCharacters(vector<vector < int>> &properties)
        {

            sort(properties.begin(), properties.end());

            return Helper(properties);
            map<int, map<int, int>> map1;
            int count = 0;

            for (int i = properties.size() - 1; i >= 0; i--)
            {
                int attack = properties[i][0];
                int defense = properties[i][1];

                auto it = map1.upper_bound(attack);

                while (it != map1.end())
                {
                    bool flag = false;
                    map<int, int> temp = it->second;

                    auto it1 = temp.upper_bound(defense);

                    if (it1 != temp.end())
                    {
                        count++;
                        it1++;
                        break;
                    }

                    it++;
                }
                map1[attack][defense]++;
            }
            return count;
        }
};