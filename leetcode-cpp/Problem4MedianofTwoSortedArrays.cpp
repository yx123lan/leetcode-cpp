/**
* There are two sorted arrays nums1 and nums2 of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		nums1.insert(nums1.end(), nums2.begin(), nums2.end());
		sort(nums1.begin(), nums1.end());
		int index = nums1.size() / 2;
		if (nums1.size() % 2 == 0) {
			return (nums1[index - 1] + nums1[index]) / 2.0;
		}
		else {
			return nums1[index];
		}
	}
};