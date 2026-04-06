class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0; i < n; i++) { // i represents your starting position
            int pos = i;
            int tank = gas[i];
            while (tank >= cost[pos]) { // while you have enough gas to reachmext station
                tank -= cost[pos]; // use up gas
                pos = (pos + 1) % n; // move over one
                tank += gas[pos]; // fill up at new gas station

                if (pos == i) { // should go off if you were able to wrap around
                    return i;
                }
            }
        }

        return -1;
    }
};


/*


wrap around logic

index where you land % n


gas =  [1,2,3,4]
cost = [2,2,4,1]

start at gas station i

fill up
    tank += gas[i]

if you have enough to get to next station
    if (cost <= tank) {
        you have enough gas to make it
        pos  = (pos + 1) % n
    }
    else {
        you dont
    }

how to start
    pick high station with greatest amount of gas
    because if you start with the max amount possible, so
        if you cant lap around from here, you wont be able to lap around anywher else
*/