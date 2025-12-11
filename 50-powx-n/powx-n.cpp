class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long m = n;          // use long long to avoid overflow
        if (m < 0) m = -m;        // now this is safe

        double currValue = x;
        while (m != 0) {
            if (m % 2 == 0) {
                currValue = currValue * currValue;
                m = m / 2;
            } else {
                ans = ans * currValue;
                m = m - 1;
            }
        }

        // use original n's sign to decide reciprocal
        if (n < 0) return 1.0 / ans;
        else return ans;
    }
};