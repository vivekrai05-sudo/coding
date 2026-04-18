class Solution {
public:
    int mirrorDistance(int n) {
        int x = n, rev = 0;

        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return abs(n - rev);
    }
};