#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int Postfix(const std::string& expression) {

    //Created Stack
    std::stack<int> st;

    for (char ch : expression) {
        if (ch == ' ') {
            continue;
        }

        if (std::isdigit(ch)) {
            st.push(ch - '0'); 
        } 
        
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {

    std::string expression = "2 3 1 * + 9 -";
    std::cout << "Postfix Result: " << Postfix(expression) << std::endl;
    return 0;

}
