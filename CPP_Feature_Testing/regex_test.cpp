// regex_test.cpp

// C++ program to demonstrate working of regex_match() 
#include <iostream> 
#include <regex> 
  
int main() 
{ 
    std::string a = "GeeksForGeeks"; 
  
    std::regex b("(Geek)(.*)"); // Geeks followed by any character 
  
    if ( std::regex_match(a, b) ) 
        std::cout << "String 'a' matches regular expression 'b' \n"; 
  
    if ( std::regex_match(a.begin(), a.end(), b) ) 
        std::cout << "String 'a' matches with regular expression "
                "'b' in the range from 0 to string end\n"; 
  
    return 0; 
} 