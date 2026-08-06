class Solution {
public:
    int getDigitMultiply(int num) {
        int multiplier = 1;

        while (multiplier > 0 && num > 0) {
            multiplier *= num % 10;
            num /= 10;
        }

        return multiplier;
    }

    int smallestNumber(int n, int t) {
        for (int num = n; num <= 100; num++) {
            if (getDigitMultiply(num) % t == 0)
                return num;
        }

        return n;
    }
};