#include <iostream>
#include <fstream>
#include <string>

// Node structure for the linked list
struct Node
{
    std::string data;
    Node *next;
};

// Linked Queue class
class LinkedQueue
{
private:
    Node *front;
    Node *rear;

public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(const std::string &value)
    {
        Node *newNode = new Node{value, nullptr};

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    std::string dequeue()
    {
        if (isEmpty())
        {
            std::cerr << "Error: Queue is empty." << std::endl;
            exit(EXIT_FAILURE);
        }

        std::string value = front->data;
        Node *temp = front;

        if (front == rear)
        {
            front = rear = nullptr;
        }
        else
        {
            front = front->next;
        }

        delete temp;
        return value;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }
};

// Function to print the Sudoku grid
void printSudoku(LinkedQueue **grid)
{
    for (int i = 0; i < 9; ++i)
    {
        Node *current = grid[i]->isEmpty() ? nullptr : grid[i]->dequeue(); // Dequeue each node
        for (int j = 0; j < 9; ++j)
        {
            if (current != nullptr && stoi(current->data) == j + 1)
            {
                std::cout << current->data << " ";
                delete current;
                current = grid[i]->isEmpty() ? nullptr : grid[i]->dequeue();
            }
            else
            {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

// Function to check if a number can be placed in a specific position
bool isSafe(LinkedQueue **grid, int row, int col, int num)
{
    // Check if 'num' is not present in the current row and column
    for (int x = 0; x < 9; ++x)
    {
        if (!grid[row]->isEmpty() && stoi(grid[row]->dequeue()) == num)
        {
            return false;
        }

        if (!grid[x]->isEmpty() && stoi(grid[x]->dequeue()) == num)
        {
            return false;
        }
    }

    // Check if 'num' is not present in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (!grid[i + startRow * 3 + j]->isEmpty() && stoi(grid[i + startRow * 3 + j]->dequeue()) == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(LinkedQueue **grid, int row, int col)
{
    // Find an unassigned location
    bool found = false;
    for (; row < 9; ++row)
    {
        for (; col < 9; ++col)
        {
            if (grid[row]->isEmpty())
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            break;
        }
        col = 0; // Reset column index for the next row
    }

    // If there is no unassigned location, the puzzle is solved
    if (!found)
    {
        return true;
    }

    // Try placing digits 1 to 9 in the current location
    for (int num = 1; num <= 9; ++num)
    {
        if (isSafe(grid, row, col, num))
        {
            // Place the number in the current location
            grid[row]->enqueue(std::to_string(num));

            // Recursively try to solve the rest of the puzzle
            if (solveSudoku(grid, row, col + 1))
            {
                return true;
            }

            // If placing the number doesn't lead to a solution, backtrack
            grid[row]->dequeue();
        }
    }

    // No solution found for the current configuration
    return false;
}

int main()
{
    // Initialize the Sudoku grid as a 2D array of linked queues
    LinkedQueue **sudokuGrid = new LinkedQueue *[9];
    for (int i = 0; i < 9; ++i)
    {
        sudokuGrid[i] = new LinkedQueue();
    }

    // Read the unsolved Sudoku puzzle from a file
    std::ifstream inputFile("unsolved_sudoku.txt");
    if (!inputFile)
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }

    // Input the unsolved Sudoku puzzle into the linked queues
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            std::string cellValue;
            inputFile >> cellValue;
            if (cellValue != "0")
            {
                sudokuGrid[i]->enqueue(cellValue);
            }
        }
    }

    // Close the input file
    inputFile.close();

    // Print the unsolved Sudoku puzzle
    std::cout << "Unsolved Sudoku Puzzle:" << std::endl;
    printSudoku(sudokuGrid);
    std::cout << std::endl;

    // Solve the Sudoku puzzle
    if (solveSudoku(sudokuGrid, 0, 0))
    {
        // Print the solved Sudoku puzzle
        std::cout << "Solved Sudoku Puzzle:" << std::endl;
        printSudoku(sudokuGrid);
    }
    else
    {
        std::cout << "No solution exists." << std::endl;
    }

    // Clean up memory
    for (int i = 0; i < 9; ++i)
    {
        delete sudokuGrid[i];
    }
    delete[] sudokuGrid;

    return 0;
}
