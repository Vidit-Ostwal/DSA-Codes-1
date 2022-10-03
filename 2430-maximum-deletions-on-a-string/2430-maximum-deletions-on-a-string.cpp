class Solution {
  void show_vector(vector<int> vect)
  {
  for (auto &it: vect)
  {
   cout << it << " ";
  }
  cout << endl;
 }
  
  vector<int> KMP(string s)
  {
    vector<int> KMPvector(s.length(), 0);
    KMPvector[0] = 0;

    int len = 0;
    int i = 1;

    while (i < s.length())
    {
      if (s[i] == s[len])
      {
        len++;
        KMPvector[i] = len;
        i++;
      }
      else
      {
        	// the character does not match, you go to the previous one which matched, which points to the starting same prefix
        if (len != 0)
          len = KMPvector[len - 1];
        else
        {
          KMPvector[i] = 0;
          i++;
        }
      }
    }
    // show_vector(KMPvector);
    return KMPvector;
  }
  
  int Helper(string s)
  {
    cout << s << endl;
    if (s.length() == 0)
      return 0;
    
    vector<int> A = KMP(s);
    int power_index = -1;
    
    for (int i = 0; i < A.size(); i++)
      if ((i + 1) == A[i]*2)
        power_index = i;
    
    if (power_index != -1)
    {
      string temp = s.substr(A[power_index]);
        return 1 + Helper(temp);
    }
    return 1;
  }
public:
    int deleteString(string s) {
      return Helper(s);
    }
};