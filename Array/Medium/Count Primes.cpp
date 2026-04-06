// Approach 1 : I used basic prime finding method for the first approach 
class Solution {
private:
    bool isPrime(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
public:
    int countPrimes(int n) {
        int result=0;
        for(int i=2;i<n;i++){
            if(isPrime(i)){
                result++;
            }
        }
        return result;
    }
};
//Apporach 2 : I used sieves of Eratosthenes method to solve the problem ,in this we solve the prime check under o(nlog(logN)) which signicficantly reduces the time 
// complexity , first we do a pre computation where we check where the number is already a multiple or not ,if not then we check out all its multiple from the array and repeat the steps
class Solution {
public:
    int countPrimes(int n) {
        vector<int> nums(n,1);
        int count=0;
        for(long long i=2;i<=sqrt(n);i++){
            if(nums[i]==1){
                for(long long j=i*i;j<n;j+=i){
                    nums[j]=0;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(nums[i]==1) count++;
        }
        return count;        
    }
};

