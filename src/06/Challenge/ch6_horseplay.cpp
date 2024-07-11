// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;
    std::transform(knight.begin(), knight.end(), knight.begin(), tolower);

    // Write your code here
    int col = int(knight[0]) - 96;
    int row = knight[1] - '1' +1;  // works only for single degit
    std::string temp;

    int delta1[2] = {-1, 1};
    int delta2[2] = {-2, 2};

    for (int i: delta1){
        for (int j: delta2){
            if (col+i <= 8 && col+i >=1 && row+j <= 8 && row+j>=1){
                temp += char(col+i+96);
                temp += char(row+j + int('0'));
                moves.push_back(temp);
                temp = "";
            }
            if (col+j <= 8 && col+j >=1 && row+i <= 8 && row+i>=1){
                temp += char(col+j+96);
                temp += char(row+i + int('0'));
                moves.push_back(temp);
                temp = "";
            }
        }
    }



    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}