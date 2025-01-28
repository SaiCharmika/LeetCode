class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // Edge case
        
        int n1 = num1.size(), n2 = num2.size();
        vector<int> result(n1 + n2, 0); // Initialize result array
        
        // Perform multiplication
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0'); // Multiply digits
                int sum = mul + result[i + j + 1]; // Add to the existing value
                
                result[i + j + 1] = sum % 10; // Store the unit place
                result[i + j] += sum / 10;   // Carry to the next position
            }
        }
        
        // Convert result array to string
        string product = "";
        for (int num : result) {
            if (!(product.empty() && num == 0)) { // Skip leading zeros
                product += to_string(num);
            }
        }
        
        return product.empty() ? "0" : product; // Handle the edge case of all zeros
    }
};
