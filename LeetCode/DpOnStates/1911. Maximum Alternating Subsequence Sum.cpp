both dp are alternating ending with different parity 
alternating me seq can end with + or - 
but always have max at i

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        //subseq sum chaiye wo bi alteranating
        //           +     - 
        vector<long long> A(n), B(n);
        A[0] = nums[0];
        B[0] = 0;

        for (int i = 1; i < n; i++) {
            if (A[i - 1] > B[i - 1] + nums[i]) {
                A[i] = A[i - 1];
            } else {
                A[i] = B[i - 1] + nums[i];
            }

            if (B[i - 1] > A[i - 1] - nums[i]) {
                B[i] = B[i - 1];
            } else {
                B[i] = A[i - 1] - nums[i];
            }
            
        }
        return max(B[n - 1], A[n - 1]);

    }
};

or even better will be to do
for every i
A[i] = max(A[i], wo condn);
B[i] = max(B[i], wo condn);


yaniki
int n = nums.size();
vector<long long> A(n), B(n); 
A[0] = nums[0];
B[0] = 0;

for (int i = 1; i < n; i++) {
    A[i] = max(A[i - 1], B[i - 1] + nums[i]);
    B[i] = max(B[i - 1], A[i - 1] - nums[i]);
}
return max(B[n - 1], A[n - 1]);
