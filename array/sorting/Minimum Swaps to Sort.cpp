/*
    https://www.geeksforgeeks.org/problems/minimum-swaps/1
    Input:
    nums = {2, 8, 5, 4}
    Output:
    1
    Explanation:
    swap 8 with 4.
*/
class Solution {
public:
    int selectionSort(vector<int>& nums) {
        int swaps = 0;
        for(int i=0; i<nums.size(); i++) {
            int mini = i;
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[j] < nums[mini]) {
                    mini = j;
                }
            }
            if(mini != i) {
                std::swap(nums[i], nums[mini]);
                swaps++;
            }
        }
        return swaps;
    }

	int minSwaps(vector<int>&nums) {
	   // return selectionSort(nums); // TLE O(n^2)
	   
	   map<int, int> phone;
	   vector<int> temp = nums;
	   // O(nlogn)
	   std::sort(temp.begin(), temp.end());
	   for(int i=0; i<temp.size(); i++) {
	        phone[temp[i]] = i;
	   }
	   int swaps = 0;
	   for(int i=0; i<nums.size(); i++) {
	       // curEle is not in it's proper place then
	       // send it to my phone
	       while(phone[nums[i]] != i) {
	           std::swap(nums[i], nums[phone[nums[i]]]);
	           swaps++;
	       }
	   }
	   return swaps;
	}
};
