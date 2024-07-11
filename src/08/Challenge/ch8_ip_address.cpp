// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){

    // Write your code here
    std::vector<std::string> addresses;
    int s = 0;
    int e = -1;

    do{
        e = ip.find('.', e+1);
        addresses.push_back(ip.substr(s, e-s));
        s = e+1;
    }while(e != std::string::npos);

    if (addresses.size()!=4) return false;
    for (std::string i: addresses){
        for (char j:i)if(!isdigit(j))return false;
        int num = stoi(i);
        if (!(num>=0 && num<=255))return false;
    }
    return true;

}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
