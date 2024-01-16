class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        const long divisorLcm = std::lcm(static_cast<long>(divisor1), divisor2);
        long l = 0;
        long r = INT_MAX;

        while (l < r) {
            const long m = (l + r) / 2;

            // count of numbers not divisible by divisor1 and divisor2
            const long cnt1 = m - m / divisor1;
            const long cnt2 = m - m / divisor2;

            // total count of numbers not divisible by the least common multiple of divisor1 and divisor2
            const long totalCnt = m - m / divisorLcm;

            if (cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 && totalCnt >= uniqueCnt1 + uniqueCnt2) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
