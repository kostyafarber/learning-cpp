#include <unordered_map>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bracs = {
            {']', '['},
            {')', '('},
            {'}', '{'}
        };

        stack<char> stack;
        size_t i = 0;

        
        while (i < s.length()) {
            char brac = s[i];

            // if not a closing bracket
            if (bracs.find(brac) == bracs.end()) {
                stack.push(brac);
            }
            

            else {
                if (stack.empty()) {
                    return false;
                }

                char opening_brac = stack.top();

                if (opening_brac != bracs[brac]) {
                    return false;
                }
                
                stack.pop();
            }
            
            i++;
        }
        
        if (!stack.empty()) {
            return false;
        }

        return true;
    }
};

int main() {
    Solution solver;
    string test = "()[]{}";

    cout << solver.isValid(test);
    
}