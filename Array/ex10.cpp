// pow(x,n)
// leetcode 50
// url: https://leetcode.com/problems/powx-n/
class Solution {
public:
    double myPow(double x, int n) {
        long no=n;
        double ans=1.0;
        if(n<0){
            no=-1*no;
        }
        while(no){
            if(no%2!=0){
                ans*=x;
                no--;
            }
            else{
                x=x*x;
                no/=2;
            }
        }
        if(n<0){
            return (1.0)/ans;
        }
        return ans;
    }
};