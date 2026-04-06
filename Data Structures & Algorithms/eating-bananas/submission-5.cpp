// if k works, ALL larger k works (binary search)
// anything bigger than k works, so go down (monotonicity)

class Solution {
public:

    bool can_eat_all(int k, int h, vector<int>& piles) { // with rate k ,can you eat all nanas within h hours?
        int total_hours_needed = 0;
        for (const auto& pile : piles) {
            total_hours_needed += (pile + k - 1) / k;
        }

        if (total_hours_needed <= h) {
            return true;
        } else {
            return false;
        }
        
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int k_max = *max_element(piles.begin(), piles.end()); // optinal k rates from 1...k_max

        // your range
        int left = 1;
        int right = k_max;
        int k = k_max; // if no smaller value is found and k inst updated, return k_max as itll always work

        while (left <= right) {
            int mid = (left + right) / 2; // mid is the current k rate

            if (can_eat_all(mid, h, piles)) { // if this rate works, look for a smaller rate
                k = mid;
                right = mid - 1;
            } else { // rate is too small, look for a bigger rate
                left = mid + 1;
            }
        }
        return k;
    }
};

/*

    notice that the max eating rate possible is max element of piles
    because h >= piles.size(), you can for sure eat all bananas in at least at least h hours

    since any rate >= k_max gurantees eating all nana within h hours, search for a smaller k

        - do so by starting from k = 1 and incrementing k if you can eat all nanas in <= h hours

        - or start at k_max and bianry search for a smaller or greater rate accordingly\

    calculating number of hours needed to finish all nanas with rate k
        - think of each pile[i] as a length
        - with rate k, it takes exactly pile[i] / k hours to eat all the nanas at pile[i]
        - but we are delaing with whole hours, so round up with ceil() or piles[i] + k - 1/ k
    


with own defined ceiling (nicer):
       int n = piles.size(); // h >= n (given)
        if (n < 1) { return 0; }

        /* 
        notice the max rate of k
            k has to be == to the the max element in the piles arr
            any rate > can finish all piles within h hours
            so look below
        

        int k_max = *max_element(piles.begin(), piles.end());

        // try all k up to k_max (start with k=1 (1 nana per hour))
        int k = 1;
        while (true) {
            int total_hours_needed = 0; // for rate k
            for (const auto& p : piles) {
                total_hours_needed += (p + k - 1) / k; //ceil(p/k)
            }
            if (total_hours_needed <= h) { return k; }
            k++;
        } 
        return k_max; // failsafe

with ceil():

        int k_max = *max_element(piles.begin(), piles.end());

        int k = 1;

        while (true) {
            int total_hours_needed = 0;
            for (const auto& bananas : piles) {
                total_hours_needed += ceil(double(bananas) / k);
            }
            if (total_hours_needed <= h) { return k; }
            k++;
        }

        return k_max;


binary search with a range vector (range vector too big it kills the program)

        long long total_hours_needed = 0;
        for (const auto& pile : piles) {
            total_hours_needed += (pile + k - 1) / k;
            // short circuit here instead of if else
        }

        if (total_hours_needed <= h) { 
            return true;
        } else {
            return false;
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int k_max = *max_element(piles.begin(), piles.end());

        // your range of optinal k rates are from 1...k_max
        vector<int> range(k_max);

        for (int i = 0; i < range.size(); i++) {
            range[i] = i+1;
        }

        int left = 0;
        int right = range.size() - 1;
        long long k = 0;
        while (left <= right) {
            int mid = (left + right) / 2; // index mid is current k rate

            if (can_eat_all(range[mid], h, piles)) { // if this rate works, look for a smaller rate
                k = range[mid];
                right = mid - 1;
            } else { // rate is too small, look for a bigger rate
                left = mid + 1;
            }
        }
        return k;
    }

ceiling explained:

think: Chunking view: You’re covering a length p with segments of length k. 

p / k = # of segments k needed to cover p 

    2/2 = 0
    1/2 = .5 -> .5



arr piles of banans
h number of hours avail 

you can eat k bananas per hour
 less than k bananas in a pile, you can finish them
 but you cannot eat from another pile in the same hour

return min k to eat all nanas

in one hour, you eat k banaas from that pile only

    for a single pile p
        eat k, so p - k remain

        after t hours, youd have eaten t*k bananas
            need smallest t so that t*k >= p

        Chunking view: You’re covering a length p with segments of length k. 
        How many segments? The number of k-sized chunks to cover p is ⌈p/k⌉.



idea (too brute force, and wrong):


        vector of candidates (wed get the min element)
            for k times
            fresh array equal to piles

            j = 0
            while j < h and
                eat k bananas (fresh[j] -= k)
                if (fresh[j] <= 0) { j++; }
            }

            if min element  < 0
                append k as candidates
            else
                break

            decrement k
*/