
/*******************************************************************************
 *
    Divide Two Integers

    description(leetcode:
                https://leetcode.com/problems/divide-two-integers/
                )

    Divide two integers without using multiplication, division and mod operator.
    If it is overflow, return MAX_INT.

    notes:
    similar to sqrt(x), pay attention to overflow problems

*******************************************************************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) { return INT_MAX; }
        if (dividend == 0 || ( std::abs((long)divisor) > std::abs((long)dividend) ) ) { return 0; }
        if (dividend == INT_MIN && divisor == -1) { return INT_MAX; }

        int sign_multiplier = (divisor > 0 ^ dividend > 0 ? -1 : 1);
        long long dividend_ = std::abs((long)dividend);
        long long divisor_ = std::abs((long)divisor);

        long long small = 1, big = dividend_; // now we can be sure that solution now must exist in this range
        while (small + 1 < big) {
            long long mid = (small + big) / 2;
            long long multi = mid * divisor_;
            if (multi == dividend_) { return mid * sign_multiplier; }
            (multi > INT_MAX || multi > dividend_ ? big : small) = mid;
        }

        return (big * divisor_ <= dividend_ ? big : small) * sign_multiplier;
    }
};

