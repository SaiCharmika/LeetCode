class Solution {
public:
    string intToRoman(int num) {
        // Define Roman numeral values and their corresponding symbols
        vector<pair<int, string>> romanSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string result = ""; // Resulting Roman numeral
        
        // Iterate through the Roman numeral values
        for (auto& [value, symbol] : romanSymbols) {
            while (num >= value) {   // While the current value can be subtracted
                result += symbol;   // Append the corresponding Roman numeral symbol
                num -= value;       // Subtract the value from the number
            }
        }
        
        return result;
    }
};
