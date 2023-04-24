#ifndef SLIDINGSOLVER_H
#define SLIDINGSOLVER_H

#include "Board_Tile.h"
#include <string>

// Class to solve the puzzle problem using the A* search algorithm
class SlidingSolver {
  BoardTile startConfig; // Starting configuration of the board
  BoardTile goalConfig;  // Goal configuration of the


public:
  // Constructor initializing the start and goal configurations
  SlidingSolver(const std::string &start, const std::string &goal);

  // Implements the A* search algorithm and returns the sequence of moves needed
  // to solve the puzzle
  std::string solvePuzzle();
};

#endif /* SLIDINGSOLVER_H */
