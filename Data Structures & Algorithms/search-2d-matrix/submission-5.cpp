class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        /*for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }*/

        int rows = matrix.size();     //m.  3
        int cols = matrix[0].size();  //n.  4

        //perform binary search on the rows, to find what row the target could be in
        int top = 0; // "top" row aka first index
        int bottom = matrix.size()-1; // matrix.size row aka last index
        //check the first and last column of the mid_row, as it would indicate
        //if the traget is below (closer to top) or above (closer to bottom)
        int mid_row = 0;
        while(top <= bottom){
            mid_row = (top + bottom)/2;

            //2nd index indicates begginign of row, or ending of row
            if(target < matrix[mid_row][0]){
                bottom = mid_row-1;
            }else if(target > matrix[mid_row][cols-1]){
                top = mid_row + 1;
            }else{
                break;
            }
        }

        //perform binary search on the row you landed on (mid_row)

        int left = 0;
        int right = matrix[mid_row].size()-1;

        while(left<=right){
            int mid = (left+right)/2;

            if(matrix[mid_row][mid] == target){
                return true;
            }
            if(matrix[mid_row][mid] > target){
                right = mid-1;
            }
            if(matrix[mid_row][mid] < target){
                left = mid+1;
            }
        }
        
        return false;
    }
};
