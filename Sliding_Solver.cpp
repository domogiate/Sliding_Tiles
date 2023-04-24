#include "Sliding_Solver.h"
#include <queue>
#include <unordered_set>

// Constructor initializing the start and goal configurations
SlidingSolver::SlidingSolver(const std::string &start, const std::string &goal)
    : startConfig(start), goalConfig(goal) {}

// Implements the A* search algorithm and returns the sequence of moves needed
// to solve the puzzle
std::string SlidingSolver::solvePuzzle() {
  auto cmp = [&](const BoardTile &a, const BoardTile &b) {
    return a.numMoves() + a.manhattanDistance(goalConfig) >
           b.numMoves() + b.manhattanDistance(goalConfig);
  };

  std::priority_queue<BoardTile, std::vector<BoardTile>, decltype(cmp)>tileQueue(cmp);
  std::unordered_set<std::string> visited;

  tileQueue.push(startConfig);
  visited.insert(startConfig.config);

  while (!tileQueue.empty()) {
    BoardTile current = tileQueue.top();
    tileQueue.pop();

    // If the current configuration is the goal configuration, return the
    // moves from the start to this point
    if (current.config == goalConfig.config) {
      return current.movesFromStart;
    }

    // Iterate through the next possible configurations from the current state
    for (const BoardTile &next : current.nextConfigs()) {
      // If the configuration has not been visited yet, add it to the visited
      // set and the priority queue
      if (visited.find(next.config) == visited.end()) {
        visited.insert(next.config);
        tileQueue.push(next);
      }
    }
  }

  // If no solution is found, return an empty string
  return "No solution found";
}
