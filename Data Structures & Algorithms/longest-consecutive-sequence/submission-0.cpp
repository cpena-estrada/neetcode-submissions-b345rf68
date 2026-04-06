class Solution {
public:

    /*place eveyrhting into a set for O(1) lookups and too keep it O(n) with a single for loop
    int count;
    iterate over nums
    temp = nums[i]
    temp_count = 0;
    if( nums[temp-1] is in the set){
        //then do nothing because if ther is a number small than temp, then temp cant be the beg of a seq
      }else{
        we conider this the start of a sequence (as all other nums in set are bigger than temp (possible sequence))
        so we begin to loop over the rest of the array
        if we find a num thats exaclty 1 greater
            temp++
            temp_count++
            (   so if we start with 2 and find 3, we increment temp_count and make 2 = 3)
    }

    have a check to check for the largest sequence at the end of every for loop
    if(temp_count > count){
        //count = temp_count
    }*/
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end()); //better instead of for looping and inserting
        int count = 0;

        for(int i=0;i<nums.size(); i++){
           int temp_count = 1; //1? 
           int curr_num = nums[i];
           
           if(set.find(curr_num-1) != set.end()){
            //do nohing. num smaller found, .: not a possible sequence
           }else{
            //possible sequence, as NO smaller number was found
            while(set.find(curr_num+1) != set.end()){
                temp_count++;
                curr_num++; //making num 1 bigger to begin lookig for one next bigger
            }
           }

           if(temp_count > count){
            count = temp_count;
           }
        }
        return count;
    }
};
