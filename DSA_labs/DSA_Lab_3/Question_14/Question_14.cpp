#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // For std::reverse


class KDigitsRemover {
public:
 
    KDigitsRemover(const std::string& number, int removeCount)
        : num(number), k(removeCount) {}

   
    std::string removeKdigits() {
        if (num.length() == k) {
            return "0"; // 
        }

        std::stack<char> num_stack;

        for (char digit : num) {
            while (!num_stack.empty() && num_stack.top() > digit && k > 0) {
                num_stack.pop();
                k--;
            }
            num_stack.push(digit);
        }

        while (k > 0 && !num_stack.empty()) {
            num_stack.pop();
            k--;
        }

        std::string result = "";
        while (!num_stack.empty()) {
            result.push_back(num_stack.top());
            num_stack.pop();
        }

        std::reverse(result.begin(), result.end());

       
        int num_non_zero = 0;
        while (num_non_zero < result.size() && result[num_non_zero] == '0') {
            num_non_zero++;
        }
        result = result.substr(num_non_zero);

       if(result.empty()){
        return 0;
       }
       else {
        return result;
       }
    }

private:
    std::string num; // Number as a string
    int k;           // Number of digits to remove
};
/*Logic--->>>This code works by finding the smallest number possible after removing k digits from a given number. It uses a stack to keep track of the digits, always trying to remove larger digits first to make the number smaller. After processing all the digits, if more need to be removed, it removes them from the end. Then, it removes any leading zeros from the final number. If all digits are removed, it returns "0".*/

int main() {
    std::string num;
    int k;

    // Input handling
    std::cin >> num;
    std::cin >> k;

    // Create an instance of KDigitsRemover
    KDigitsRemover remover(num, k);

    // Call the method to get the smallest number
    std::string smallestNumber = remover.removeKdigits();

    // Output the result
    std::cout << smallestNumber << std::endl;

    return 0;
}
