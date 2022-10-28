class Solution {
public:
    int mirrorReflection(int p, int q) {
        int divisor = gcd(p,q);
        if (q/divisor % 2) {
            if (p/divisor % 2) return 1;
            return 2;
        } 
        else return 0;
    }
};
