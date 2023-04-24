#ifndef BOARDTILE_H
#define BOARDTILE_H

#include <string>
#include <vector>

// Class representing a state of the puzzle board
class BoardTile {
public:
  std::string config;         // Current configuration of the board
  std::string movesFromStart; // Moves made from the starting configuration to
                              // reach this state

  // Constructor initializing the board configuration and movesFromStart
  BoardTile(const std::string &initialConfig);

  // Generates and returns all possible board configurations that can be reached
  // in a single move from the current state
  std::vector<BoardTile> nextConfigs() const;

  // Returns the number of moves made so far to reach the current state
  int numMoves() const;

  // Calculates and returns the sum of the Manhattan distances of all tiles from
  // their correct positions in the goal configuration
  int manhattanDistance(const BoardTile &goalConfig) const;
};

#endif /* BOARDTILE_H */
