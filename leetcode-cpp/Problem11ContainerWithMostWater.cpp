/*
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*/
class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int maxArea = 0;
		while (left < right) {
			int area = 0;
			if (height[left] < height[right]) {
				area = height[left] * (right - left);
				left++;
			}
			else {
				area = height[right] * (right - left);
				right--;
			}
			if (area > maxArea) {
				maxArea = area;
			}
		}
		return maxArea;
	}
};