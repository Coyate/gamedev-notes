#include <string>

using namespace std;

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
		if (this != &object) {
            char *newdata = nullptr;
            
            if(object.m_pData) {
                newdata = new char[strlen(object.m_pData) + 1];
			    strcpy(newdata, object.m_pData);    
            }
			
			if (m_pData)
				delete[] m_pData;

			m_pData = newdata;
		}

		return *this;
    }
};