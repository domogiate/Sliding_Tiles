#include "Board_Tile.h"
#include "Sliding_Solver.h"
#include <iostream>
#include <string>
#include <unordered_set>

// Function to check if a given board configuration is valid
bool isValidConfiguration(const std::string &config) {
  if (config.length() != 9) {
    return false;
  }
  std::unordered_set<char> charSet;
  for (char c : config) {
    if (c < '0' || c > '8') {
      return false;
    }
    if (charSet.find(c) != charSet.end()) {
      return false;
    }
    charSet.insert(c);
  }
  return true;
}

// Main function to run the solver
int main() {
  std::string startConfig, goalConfig;

  // Get a valid start configuration from the user
  do {
    std::cout << "Enter the start Board: ";
    std::cin >> startConfig;
    if (!isValidConfiguration(startConfig)) {
      std::cout << "Invalid start configuration. Please enter exactly 9 "
                   "distinct digits from 0 to 8."
                << std::endl;
    }
  } while (!isValidConfiguration(startConfig));

  // Get a valid goal configuration from the user
  do {
    std::cout << "Enter the goal Board: ";
    std::cin >> goalConfig;
    if (!isValidConfiguration(goalConfig)) {
      std::cout << "Invalid goal configuration. Please enter exactly 9 "
"distinct digits from 0 to 8."
<< std::endl;
}
} while (!isValidConfiguration(goalConfig));

// Create a solver instance and solve the puzzle
SlidingSolver solver(startConfig, goalConfig);
std::string solution = solver.solvePuzzle();

// Output the solution if found, or indicate that no solution was found
if (solution.empty()) {
std::cout << "No solution found." << std::endl;
} else {
std::cout << "Number of Moves: " << solution.length() << std::endl;
std::cout << "Solution: " << solution << std::endl;
}

return 0;
}
