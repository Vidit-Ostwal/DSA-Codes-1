class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
      vector<int>A(pref.size());
      A[0] = pref[0];
      int temp = A[0];
      for (int i = 1; i < pref.size(); i++)
      {
        int k = temp ^ pref[i];
        A[i] = k;
        temp = temp ^ k;
      }
      
      
      return A;
    }
};