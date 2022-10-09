class Solution {
public:
    vector<int> findArray(vector<int>& A) {
      int temp = A[0];
      for (int i = 1; i < A.size(); i++)
      {
        int k = temp ^ A[i];
        A[i] = k;
        temp = temp ^ k;
      }
      return A;
    }
};