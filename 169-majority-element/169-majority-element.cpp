class Solution {
public:
    int majorityElement(vector<int>& nums) {
	int cnt = 1;
	int maxNum = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		if (maxNum == nums[i]) {
			cnt++;
		}
		else{
			cnt--;
		}

		if (cnt == 0) {
			maxNum = nums[i];
			cnt = 1;
		}
	}

	cnt = 0;
	for (auto it:nums) {
		if (it == maxNum)
			cnt++;
	}

	if (cnt > (nums.size() / 2))
		return maxNum;

	return -1;
}
};