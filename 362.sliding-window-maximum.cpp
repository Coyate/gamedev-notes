class Solution {
public:

    // monotone deque, O(n), O(n)
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
    	int q[nums.size()];
    	vector<int> t;
    	int head = 0, tail = 0;
    	for (int i = 0; i < nums.size(); ++i) {
    		while (tail != head && nums[i] > nums[q[tail - 1]])
    			--tail;
    		if (tail != head && i - q[head] >= k)
    			++head;
    		q[tail++] = i;
    		if (i >= k - 1)
    			t.push_back(nums[q[head]]);
    	}
    	return t;
    }
    
    // stl monotone deque, O(n), O(k) 
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
    	deque<int> q;
    	vector<int> r;
    	for (int i = 0; i < nums.size(); ++i) {	
            if (!q.empty() && i - q.front() >= k)
                q.pop_front();
            while (!q.empty() && nums[i] > nums[q.back()])
                q.pop_back();
            q.push_back(i);
    		if (i >= k - 1)
    			r.push_back(nums[q.front()]);
    	}
    	return r;
    }

    // stl priority_queue, O(nlog(k)), O(k)
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
    	priority_queue<pair<int, int>> q;
    	vector<int> r;
    	for (int i = 0; i < nums.size(); ++i) {
    		q.push({ nums[i], i });
    		while (!q.empty() && q.top().second <= i - k)
    			q.pop();
    		if (i >= k - 1)
    			r.push_back(q.top().first);
    	}
    	return r;
    }
    
    // stl multiset, O(nlog(k)), O(k)
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
    	multiset<int, greater<int>> s;
    	vector<int> r;
    	for (int i = 0; i < nums.size(); ++i) {
    		s.insert(nums[i]);
    		if (i >= k)
    			s.erase(s.find(nums[i - k]));
    		if (i >= k - 1)
    			r.push_back(*s.begin());
    	}
    	return r;
    }
};