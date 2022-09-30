class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for (int i = 0; i < n; i++ ) {
            switch((i+1)%15) {
                case 0:
                    ans[i] = "FizzBuzz";
                    break;
                case 3:
                case 6:
                case 9:
                case 12:
                    ans[i] = "Fizz";
                    break;
                case 5:
                case 10:
                    ans[i] = "Buzz";
                    break;
                default: 
                    ans[i] = to_string(i+1);
            }
        }
        return ans;
    }
};
