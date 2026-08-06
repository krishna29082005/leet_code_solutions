class Solution {
public:
    double p(double x , int N){
        if(N == 0) return 1;
        double half = p(x , N/2);

        if(N % 2 == 0){
            return half*half;
        }
        else{
            return half*half*x;
        }
    }
    double myPow(double x, int n) {
       long long N = n;
       if(N < 0){
        x = 1/x;
        N = -N;
       }
       return p(x , N);
    }
};