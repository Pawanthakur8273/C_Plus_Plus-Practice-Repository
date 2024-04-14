#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main() {

    string str;
    stack<char> st;

    cout << "Enter a String" << endl;
    getline(cin, str);

    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        st.push(ch);
    }

    for(int i = 0; i < str.size(); i++){
        str[i] = st.top();
        st.pop();
    }

    cout << str << endl;
    
    

   return 0;
}
