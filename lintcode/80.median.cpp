class Solution {
public:
    // std::nth_element, partition
    // Time : O(N), Space : O(1)
    int median(vector<int> &nums) {
		auto iter = nums.begin() + ((nums.size() - 1) >> 1);
		nth_element(nums.begin(), iter, nums.end());
		return *iter;
    }

    //  std::sort
    // Time : O(logN), Space : O(1)
    int median(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		return nums[(nums.size() - 1) / 2];
    }
};

class Solution {
public:
    // Manual partition
    // Time : O(N), Space : O(1)
	int partition(vector<int> &v, int l, int r) {
		int head = l;
		int pivot = v[l];
		while (l < r) {
		    while (l < r && v[r] > pivot) --r;
			while (l < r && v[l] <= pivot) ++l;
			swap(v[l], v[r]);
		}
		swap(v[head], v[l]);
		return l;
	}

	int median(vector<int> &nums) {
		int p = 0;
		int l = 0, r = nums.size() - 1;
		int t = r >> 1;
		while (p != t) {
			p = partition(nums, l, r);
			if (p < t)
				l = p + 1;
			else
				r = p - 1;
		}
		return nums[p];
	}
};