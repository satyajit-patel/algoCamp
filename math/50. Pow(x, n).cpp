namespace satya {
    double pow(double base, int power) {
        bool isNegetive = (power < 0);
        if(isNegetive) {
            power = std::abs(power);
        }

        double ans = 1;
        while(power) {
            if(power&1) {
                ans *= (base);
            }
            base *= base;
            power /= 2;
        }

        if(isNegetive) {
            return 1/ans;
        }
        return ans;
    }
}

class Solution {
public:
    double myPow(double x, int n) {
        // return std::pow(x, n);
        return satya::pow(x, n);
    }
};