class Solution {
public:
	// inc method
	// 50ms, why the inc method is slower than mod method
    vector<string> fizzBuzz(int n) {
        vector<string> r;
        int m3 = 0, m5 = 0;
        for(int i = 1; i <= n; ++i) {
            ++m3, ++m5;
            if(m3 >= 3) m3 = 0;
            if(m5 >= 5) m5 = 0;
            if(!m5 && !m3)
                r.push_back("fizz buzz");
            else if(!m5)
                r.push_back("buzz");
            else if(!m3)
                r.push_back("fizz");
            else
                r.push_back(to_string(i));
        }
        return r;
    }

	// mod method
	// 8ms
	vector<string> fizzBuzz(int n) {
		vector<string> r;
		for (int i = 1; i <= n; ++i) {
			if(i % 15 == 0)
			    r.push_back("fizz buzz");
			else if (i % 3 == 0)
				r.push_back("fizz");
			else if (i % 5 == 0)
				r.push_back("buzz");
			else
				r.push_back(to_string(i));
		}
		return r;
	}

	// one line mod method
	// 50ms
    vector<string> fizzBuzz(int n) {
		vector<string> r;
		for (int i = 1; i <= n; ++i)
            r.push_back(i % 3 == 0? (i % 5 == 0? "fizz buzz" : "fizz") : (i % 5 == 0? "buzz": to_string(i)));
		return r;
    }
};

