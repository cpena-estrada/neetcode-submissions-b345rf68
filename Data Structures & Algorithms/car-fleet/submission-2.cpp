class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int, int>> pos_speed;
        stack<double> s; 
        // int fleet = 0; use the size of stack as fleet count

        // base case: 1 car or no cars
        if (size == 1) {
            return 1;
        }
        else if (size < 1) {
            return 0;
        }

        for (int i = 0; i< size; ++i) {
            pos_speed.push_back(make_pair(position[i], speed[i]));
        }

        //sort by decreasing position 
        sort(pos_speed.begin(), pos_speed.end(), [](const auto& a, const auto& b){
            return a > b;
        });
        
        // push initial time/car to the stack
        double init_time = static_cast<double>((target - pos_speed[0].first)) / pos_speed[0].second;
        s.push(init_time);

        for (int i = 1; i < size; i++) {
            double time = static_cast<double>((target - pos_speed[i].first)) / pos_speed[i].second;
            if (time <= s.top()) { // if car ahead is as fast or slowe than current car
                //joins fleet because it cant pass. fleet/stack size remains
            }
            else if (time > s.top()) {
                s.push(time);
            }
        }
        return s.size(); // aka number of fleets
    }
};


/* 

time = displacement / velocity

sorted in decreasing position 

t:
p:
s:


        // for (const auto& pair : pos_speed) {
        //     cout << pair.first << " " << pair.second << "\n";
        // }

*/