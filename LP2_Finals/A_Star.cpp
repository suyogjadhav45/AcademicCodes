#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// Define the game state representation
using GameState = vector<vector<int>>;

// Define a pair of integers for coordinates
using Coord = pair<int, int>;

// Helper function to calculate the Manhattan distance between two coordinates
int manhattanDistance(Coord p1, Coord p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

// Function to print a game state
void printGameState(const GameState &state)
{
    for (const auto &row : state)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// A* search algorithm
vector<GameState> aStarSearch(GameState start, GameState goal)
{
    // Define possible movements (up, down, left, right)
    vector<Coord> movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Create a priority queue to store the open set
    priority_queue<pair<int, GameState>, vector<pair<int, GameState>>, greater<pair<int, GameState>>> openSet;

    // Create a map to store the G and F scores for each game state
    map<GameState, int> gScores;

    // Create a map to store the predecessors of each game state
    map<GameState, GameState> predecessors;

    // Set the G score of the start state to zero
    gScores[start] = 0;

    // Add the start state to the open set
    openSet.push({manhattanDistance({0, 0}, {2, 2}), start});

    while (!openSet.empty())
    {
        GameState current = openSet.top().second;
        openSet.pop();

        // Check if the current state is the goal state
        if (current == goal)
        {
            // Reconstruct the path from the goal to the start
            vector<GameState> path;
            while (current != start)
            {
                path.push_back(current);
                current = predecessors[current];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        // Explore the neighboring states
        Coord emptyCell;
        for (int i = 0; i < current.size(); ++i)
        {
            for (int j = 0; j < current[i].size(); ++j)
            {
                if (current[i][j] == 0)
                {
                    emptyCell = {i, j};
                    break;
                }
            }
        }

        for (auto movement : movements)
        {
            int newRow = emptyCell.first + movement.first;
            int newCol = emptyCell.second + movement.second;

            if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3)
            {
                GameState neighbor = current;
                swap(neighbor[emptyCell.first][emptyCell.second], neighbor[newRow][newCol]);

                // Calculate the tentative G score for the neighbor
                int gScore = gScores[current] + 1;

                // Check if the neighbor has not been evaluated or if the new G score is lower than the previous one
                if (gScores.find(neighbor) == gScores.end() || gScore < gScores[neighbor])
                {
                    // Update the G score for the neighbor
                    gScores[neighbor] = gScore;

                    // Update the predecessor of the neighbor
                    predecessors[neighbor] = current;

                    // Add the neighbor to the open set
                    int fScore = gScore + manhattanDistance({newRow, newCol}, {2, 2});
                    openSet.push({fScore, neighbor});
                }
            }
        }
        // printPriorityQueue(openSet);
    }

    // No path found
    return {};
}

int main()
{
    // Define the start and goal states
    GameState start = {{2, 8, 3}, {1, 6, 4}, {7, 0, 5}};
    GameState goal = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};

    // Perform A* search
    vector<GameState> path = aStarSearch(start, goal);

    // Print the path from the start to the goal
    cout << "Path:" << endl;
    if (path.size() == 0)
    {
        cout << "No PATH FOUND" << endl;
    }
    for (const auto &state : path)
    {
        printGameState(state);
    }

    return 0;
}