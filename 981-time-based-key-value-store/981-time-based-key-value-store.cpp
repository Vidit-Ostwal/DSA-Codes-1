class TimeMap {
    unordered_map<string, map<int, string>> ump;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int time) {
        // Storing values with key and time to value
        ump[key][time] = value;
    }
    
    string get(string key, int time) {
        
        //Check if key-value found at exact timestamp
        if(ump.find(key) == ump.end()) return "";
        
        // if not found check on timestamp just before
        auto it = ump[key].upper_bound(time);
        if( it != ump[key].begin()){
            it--;
            return it->second;
        }
        else return "";
        
    }
};