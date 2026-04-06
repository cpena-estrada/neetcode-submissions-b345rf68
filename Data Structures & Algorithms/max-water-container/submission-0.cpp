class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        for(int i=0; i< heights.size(); i++){
            for(int j=0; j<heights.size(); j++){
                int base = abs(j-i);
                int height = min(heights[i], heights[j]);
                int curr_area = base * height;

                area = max(area, curr_area);
            }
        }
        return area;
    }
};


//height = smaller bar (can do an if-else or maybe use min() )
//base = right bar index - left bar index
//area = base * height