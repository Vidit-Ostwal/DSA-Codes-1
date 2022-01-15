// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int top_down_solution(string text1, string text2)
  {
    vector<vector<int>> dp(text1.length()+1,vector<int> (text2.length()+1,-1));
    for (int i = 0; i <= text1.length();i++)
    {
      for (int j = 0; j <= text2.length(); j++)
      {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        
        else
          dp[i][j] = (text1[i-1] == text2[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i-1][j],dp[i][j-1]);
      }
    }
    return dp[text1.length()][text2.length()];
  }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return m + n - top_down_solution(X,Y);
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends