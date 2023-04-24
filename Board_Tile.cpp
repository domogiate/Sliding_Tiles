#include "Board_Tile.h"
#include <cmath>

// Constructor initializing the board configuration and movesFromStart
BoardTile::BoardTile(const std::string &initialConfig)
    : config(initialConfig), movesFromStart("") {}

// Generates and returns all possible board configurations that can be reached
// in a single move from the current state
std::vector<BoardTile> BoardTile::nextConfigs() const {
  std::vector<BoardTile> nextBoards;
  int zeroPos = config.find('0');
  int row = zeroPos / 3;
  int col = zeroPos % 3;

  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  char move[] = {'U', 'R', 'D', 'L'};

  for (int i = 0; i < 4; ++i) {
    int newRow = row + dx[i];
    int newCol = col + dy[i];

    if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3) {
      BoardTile newBoard(config);
      newBoard.config[newRow * 3 + newCol] = '0';
      newBoard.config[zeroPos] = config[newRow * 3 + newCol];
      newBoard.movesFromStart = movesFromStart + move[i];
      nextBoards.push_back(newBoard);
    }
  }

  return nextBoards;
}

// Returns the number of moves made so far to reach the current state
int BoardTile::numMoves() const { return movesFromStart.length(); }

// Calculates and returns the sum of the Manhattan distances of all tiles from
// their correct positions in the goal configuration
int BoardTile::manhattanDistance(const BoardTile &goalConfig) const {
  int md = 0;
  for (int i = 0; i < 9; ++i) {
    if (config[i] == '0')
      continue;
    int goalPos = goalConfig.config.find(config[i]);
    md += std::abs(i / 3 - goalPos / 3) + std::abs(i % 3 - goalPos % 3);
  }
  return md;
}
