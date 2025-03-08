class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string token, result;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue; // Skip empty and current dir
            if (token == "..") {
                if (!st.empty()) st.pop(); // Go up one directory
            } else {
                st.push(token); // Push valid directory name
            }
        }

        // Build the simplified path
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result; // Return "/" if stack is empty
    }
};
