#include <iostream>
#include <string>
#include <algorithm>

std::string addBinary(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i>= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        
        carry = sum >> 1;
        result += (sum & 1) + '0';
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string a, b;
    std::cout << "Enter first binary number: ";
    std::cin >> a;
    std::cout << "Enter second binary number: ";
    std::cin >>b;

    std::string result = addBinary(a, b);
    std::cout << "Sum: " << result << std::endl;

    return 0;
}
// Enter first binary number: 1101
// Enter second binary number: 1011
// Sum: 11000