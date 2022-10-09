class FoodRatings {
  unordered_map<string,map<int,map<string,int>,greater<int>>> map1;
  unordered_map<string,string> map2;
  unordered_map<string,int> map3;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
      
      for (int i = 0; i < foods.size(); i++)
      {
        map1[cuisines[i]][ratings[i]][foods[i]]++;
        map2[foods[i]] = cuisines[i];
        map3[foods[i]] = ratings[i];
      }
    }
    
    void changeRating(string food, int newRating) {
        string cui = map2[food];
      int prev_rat = map3[food];
       map3[food] = newRating;
      
      map1[cui][prev_rat].erase(food);
      
      if (map1[cui][prev_rat].size() == 0)
        map1[cui].erase(prev_rat);
      
     
      map1[cui][newRating][food]++;
    }
    
    string highestRated(string cuisine) {
      return map1[cuisine].begin() -> second.begin()->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */