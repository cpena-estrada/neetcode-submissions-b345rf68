class TimeMap {
private:
    using item = pair<int, string>; // <timestamp, value>
    unordered_map<string, vector<item>> storage; 
public:
    TimeMap() { }

    void set(string key, string value, int timestamp) {
        storage[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (storage.count(key)) { // if key exists (set was called on it prior)
            //vector<item>
            const auto& item_list = storage[key]; // avoid copying

            int left = 0;
            int right = item_list.size() - 1;

            string ans = "";
            while (left <= right) {
                int mid = (left + right) / 2;

                const auto& [curr_timestamp, value] = item_list[mid];
                
                if (curr_timestamp <= timestamp) {
                    ans = value; // extract value
                    left = mid + 1; // go right to look for a more recent one
                } else {
                    right = mid - 1;
                }
            }
            return ans;
        }
        return "";
    }
};

/*
// with a vector (linear search or binary search as timestamps are increasing )
<key, [ <value, timestamp> , <v,t>, <v,t>] > (list of pairs)
            
get:

if key exists, 
    return the most recent value if time is <= given timestamp in func parameter
else 
    return ""

binary search:
    size of the vector is your range
    left = 0;
    right = storage[key].size() - 1; 


// popping and saving is costly. 
<key, <value, timestamp> (a max_heap of pairs organized timestamp)

*/