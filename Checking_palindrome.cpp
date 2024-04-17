class Solution {
public:
    bool isPalindrome(int x) {
        // Convert integer to string
        std::string str = std::to_string(x);
        
        // Check if the string is a palindrome
        int i = 0, j = str.length() - 1;
        while (i < j) {
            // Compare characters from both ends of the string
            if (str[i] != str[j]) {
                // If characters don't match, it's not a palindrome
                return false;
            }
            // Move to the next characters
            i++;
            j--;
        }
        
        // If all characters match, it's a palindrome
        return true;
    }
};
