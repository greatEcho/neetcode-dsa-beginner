#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

int main(void)
{
    std::string s {"{{[]}"};
    std::stack<char> stk;
    std::unordered_map<char, char> pairs_brackets = 
    {
        {'}', '{'},
        {']', '['},
        {')', '('}
    };

    for (char i: s) {
        // we have closing bracket
        if (pairs_brackets.contains(i)) {
            if (stk.size() > 0) {
                if (pairs_brackets[i] == stk.top() )
                    stk.pop();
                else
                    return 1;
            }
            else {
                return 1;
            }
        }
        // we have opening bracket
        else {
            stk.push(i);
        }
    }

        return stk.size() == 0 ? 0 : 1;
}
