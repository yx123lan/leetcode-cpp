class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int size = nums.size();
		vector<vector<int>> arrayList;
		for (int i = 0; i<size - 2; i++) {
			int one = nums[i];
			if (i > 0 && nums[i - 1] == one) {
				continue;
			}
			int left = i + 1;
			int right = size - 1;
			while (left < right) {
				if (one + nums[left] + nums[right] < 0) {
					left++;
				}
				else if (one + nums[left] + nums[right] == 0) {
					vector<int> array(3);
					array[0] = one;
					array[1] = nums[left];
					array[2] = nums[right];
					arrayList.push_back(array);
					do {
						left++;
					} while (left < right && nums[left - 1] == nums[left]);
				}
				else {
					right--;
				}
			}
		}
		return arrayList;
	}
};