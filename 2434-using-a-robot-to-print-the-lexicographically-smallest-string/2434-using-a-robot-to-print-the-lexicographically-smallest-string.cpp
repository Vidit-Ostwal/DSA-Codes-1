class Solution {
  vector<int> Helper;
  string Function2(string s)
  {
    int Index = 0;
    string t = "";
    string answer = "";
    
    while (Index < s.length())
    {
      string temp = s.substr(Index,Helper[Index] - Index + 1);
      string temp_answer = "";
      int index = t.length()-1;
      
      while (t.length())
      {
        if (t[t.length()-1] <= temp[temp.length()-1])
        {
          temp_answer += t[t.length()-1];
          t.pop_back();
        }
        else
          break;
      }
      answer += temp_answer;
      Index = Helper[Index] + 1;
      t += temp;
    }
    
    reverse(t.begin(),t.end());
    answer += t;
    return answer;
  }
public:
    string robotWithString(string s) {
        
      if (!s.length())
        return s;
      
      Helper = vector<int>(s.length(),-1);
      int index = s.length()-1;
      char mini = s[s.length()-1];
      Helper[s.length()-1] = s.length()-1;
      
      for (int i = s.length()-1; i >= 0; i--)
      {
        if (mini >= s[i])
        {
          mini = s[i];
          index = i;
        }
        Helper[i] = index;
      }
      
      return Function2(s);
    }
};