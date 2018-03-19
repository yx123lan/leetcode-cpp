class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int size = nums.size();
		int closest = nums[0] + nums[1] + nums[size - 1];
		for (int i = 0; i<size - 2; i++) {
			int one = nums[i];
			if (i > 0 && nums[i - 1] == one) {
				continue;
			}
			int left = i + 1;
			int right = size - 1;
			while (left < right) {
				int sum = one + nums[left] + nums[right];
				if (sum > target) {
					right--;
				}
				else {
					left++;
				}
				if (std::abs(target - sum) < std::abs(target - closest)) {
					closest = sum;
				}
			}
		}
		return closest;
	}
};