class Solution {
public:
    bool isValid(string s) {
        string str = s;  // Create a copy of the input string
        stack<char> st;   // Create a stack to store opening parentheses

        // Iterate through each character in the string
        for(int i = 0; i < str.length(); i++){
            char ch = str[i];  // Get the current character
            
            // If the character is an opening parenthesis, push it onto the stack
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            } else {  // If the character is a closing parenthesis
                // Check if the stack is not empty
                if(!st.empty()){
                    // Check if the closing parenthesis matches the top of the stack
                    if(ch == ')' && st.top() == '('){
                        st.pop();  // If match, pop the opening parenthesis from the stack
                    } else if(ch == ']' && st.top() == '['){
                        st.pop();  // If match, pop the opening square bracket from the stack
                    } else if(ch == '}' && st.top() == '{'){
                        st.pop();  // If match, pop the opening curly brace from the stack
                    } else {
                        return false;  // If not a match, return false
                    }
                } else {
                    return false;  // If the stack is empty and encounter a closing parenthesis, return false
                }
            }
        }

        // After iterating through the string, if the stack is empty, return true, otherwise return false
        if(st.empty()){
            return true;
        } else {
            return false;
        }
    }
};
