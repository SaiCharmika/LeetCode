#include <stack>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        // Map to store matching brackets
        std::unordered_map<char, char> matching = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        // Stack to track open brackets
        std::stack<char> stack;

        for (char c : s) {
            if (matching.count(c)) {
                // Closing bracket: check if stack is empty or doesn't match
                if (stack.empty() || stack.top() != matching[c]) {
                    return false;
                }
                stack.pop(); // Pop the matched open bracket
            } else {
                // Open bracket: push onto stack
                stack.push(c);
            }
        }

        // If the stack is empty, all brackets were matched
        return stack.empty();
    }
};
