class Solution {
  int count_set_bit(int num)
  {
    int count = 0;
    while (num)
    {
      if (num & 1)
        count++;
      num = num >> 1;
    }
    return count;
  }
  
  int vector_to_int(vector<int>& A)
  {
    string temp = "";
    for (int i = 0; i < A.size(); i++)
    {
      if (A[i])
        temp += "1";
      else
        temp += "0";
    }
    // cout << temp << endl;
    return stoi(temp,0,2);
  }
public:
    int minimizeXor(int num1, int num2) {
        
      int count1 = count_set_bit(num1);
      int count2 = count_set_bit(num2);
      int temp = num1;
      
      if (count1 == count2)
        return num1;
      
      else if (count1 > count2)
      {
        cout << "Case1" << endl;
        int diff = count1 - count2;
        vector<int> Bit(32,0);
        int index = 31;
        
        while (num1)
        {
          if (num1 & 1)
            Bit[index] = 1;
          index--;
          num1 = num1 >> 1;
        }
        
        for (int i = 0; i < 32; i++)
        {
          if (Bit[i] && count2)
          {
            Bit[i] = 0;
            count2--;
          }
        }
        return vector_to_int(Bit) ^ temp;
      }
      else
      {
         cout << "Case2" << endl;
        cout << count1 << "   " << count2 << endl;
        vector<int> Bit(32,0);
        vector<bool> flag(32,false);
        int index = 31;
        
        while (num1)
        {
          if (num1 & 1)
          {
            Bit[index] = 0;
            count2--;
            flag[index] = true;
          }
          index--;
          num1 = num1 >> 1;
        }
        
        for (int i = 31; i >= 0 ; i--)
        {
          if (!flag[i] && count2)
          {
            Bit[i] = 1;
            flag[i] = true;
            count2--;
          }
        }
        return vector_to_int(Bit) ^ temp;
      }
      
      return -1;
        
    }
};