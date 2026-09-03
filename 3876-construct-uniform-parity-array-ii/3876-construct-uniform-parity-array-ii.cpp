class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();

        int minEven = INT_MAX, minOdd = INT_MAX;

        for(int x : nums){
            if(x % 2 == 0) minEven = min(minEven, x);
            else minOdd = min(minOdd, x);
        }

        // Try making all EVEN
        bool makeEven = true;
        for(int x : nums){
            if(x % 2 == 0) continue;

            // odd ko even banana hai → need smaller odd
            if(minOdd == INT_MAX || minOdd >= x){
                makeEven = false;
                break;
            }
        }

        // Try making all ODD
        bool makeOdd = true;
        for(int x : nums){
            if(x % 2 == 1) continue;

            // even ko odd banana hai → need smaller odd
            if(minOdd == INT_MAX || minOdd >= x){
                makeOdd = false;
                break;
            }
        }

        return makeEven || makeOdd;
    }
};