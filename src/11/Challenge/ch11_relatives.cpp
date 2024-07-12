// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::fstream file ("names.csv", std::ios::in);
    std::vector<std::string> first_names;
    std::vector<std::string> last_names;
    std::string line;
    std::string temp;
    std::string first;
    std::string last;
    // Read the CSV file.
    if(file.is_open()){

        // Write your code here
        std::getline(file, line);
        std::stringstream ss(line);
        while(std::getline(ss, temp, ',')){
            std::stringstream  name(temp);
            std::getline(name, first, ' ');
            std::getline(name, last);
            first_names.push_back(first);
            last_names.push_back(last);
        }
    
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here
    for (int i=0; i<first_names.size()-1; i++){
        // std::cout << first_names[i] << '\n';
        // std::cout << last_names[i] << '\n';
        for (int j=i+1; j<first_names.size(); j++){
            if (last_names[i] == last_names[j]){
                std::cout << first_names[i] << ' ' << last_names[i] << " and " << first_names[j] << ' ' << last_names[j] << "may be realatives";
                return 0;
               
            }
        }
    }

    std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 