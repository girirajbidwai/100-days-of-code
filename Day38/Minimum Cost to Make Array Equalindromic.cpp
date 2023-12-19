class Solution {
public:
    // Function to check if a number is a palindrome
    bool check(int t) {
        // Convert the number to a string
        string temp = to_string(t);
        int i = 0, j = temp.size() - 1;

        // Check for palindrome property
        while (i < j) {
            if (temp[i] != temp[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    // Function to find the minimum cost to make all elements in 'nums' equal
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the input array
        int n = nums.size();
        int first = nums[n / 2]; // Middle element if the array length is odd
        int second = nums[n / 2]; // Middle element if the array length is odd
        long long ans = 1e18; // Set initial answer to a large value

        // Adjust 'second' if the array length is even
        if (n % 2 == 0) {
            second = nums[(n + 1) / 2];
        }
        
        int temp = -1;

        // Searching for the smallest palindrome value in the range [first, second]
        for (int q = first; q <= second; ++q) {
            if (check(q)) {
                temp = q;
                break;
            }
        }

        // If a palindrome is found within the range, calculate the total cost
        if (temp != -1) {
            long long fo = 0;
            for (int i = 0; i < n; ++i) {
                fo += abs(nums[i] - temp);
            }
            ans = min(ans, fo);
        }
        
        temp = -1;

        // Searching for the smallest palindrome value in the range [first, 0]
        for (int q = first; q >= 0; --q) {
            if (check(q)) {
                temp = q;
                break;
            }
        }

        // If a palindrome is found within the range, calculate the total cost
        if (temp != -1) {
            long long fo = 0;
            for (int i = 0; i < n; ++i) {
                fo += abs(nums[i] - temp);
            }
            ans = min(ans, fo);
        }

        temp = -1;

        // Searching for the smallest palindrome value in the range [second, INT_MAX]
        for (int q = second; q < INT_MAX; ++q) {
            if (check(q)) {
                temp = q;
                break;
            }
        }

        // If a palindrome is found within the range, calculate the total cost
        if (temp != -1) {
            long long fo = 0;
            for (int i = 0; i < n; ++i) {
                fo += abs(nums[i] - temp);
            }
            ans = min(ans, fo);
        }
        
        // Return the minimum cost
        return ans;
    }
};
