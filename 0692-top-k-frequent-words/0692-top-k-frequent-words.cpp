class Solution {
  static bool comparator(pair<int,string> A1, pair<int,string> A2)
  {
    if (A1.first == A2.first)
      return A1.second.compare(A2.second) < 0;
    else
      return A1.first > A2.first;
  }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
      unordered_map<string,int> Helper_map;
      vector<pair<int,string>> vect;
      
      for (int i = 0; i < words.size(); i++)
        Helper_map[words[i]]++;
      
      auto it = Helper_map.begin();
      
      while (it != Helper_map.end())
      {
        vect.push_back(make_pair(it -> second, it -> first));
        it++;
      }
      
      sort(vect.begin(),vect.end(),comparator);
      vector<string> Ans;
      
      for (int i = 0; i < k; i++)
        Ans.push_back(vect[i].second);
      
      return Ans;
      
      
    }
};