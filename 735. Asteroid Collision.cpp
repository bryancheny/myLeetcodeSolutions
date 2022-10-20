class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) dq.push_back(asteroids[i]);
            else {
                if (dq.empty()) {
                    res.push_back(asteroids[i]);
                    continue;
                }
                while (true) {
                    int temp = dq.back();
                    if (temp > abs(asteroids[i])) {
                        break;
                    }
                    else if (temp == abs(asteroids[i])) { 
                        dq.pop_back();
                        break;
                    }
                    else {
                        dq.pop_back();
                        if (dq.empty()) {
                            res.push_back(asteroids[i]);
                            break;
                        }
                    }
                }
            }
        }
        while (!dq.empty()) {
            int front = dq.front();
            dq.pop_front();
            res.push_back(front);
        }
        return res;
    }
};
