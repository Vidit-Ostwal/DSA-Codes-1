class Solution {
public:
    string breakPalindrome(string palindrome) {
      
      int length = palindrome.length();
      int mid_index = (length % 2) ? length/2-1 : length/2;
    
      if (length == 1)
        return "";
      
    for (int i = 0; i <= mid_index ; i++)
    {
      if (palindrome[i] != 'a')
      {
        palindrome[i] = 'a';
        return palindrome;
      }
    }
    palindrome[length-1] = 'b';
      return palindrome;
  }
};