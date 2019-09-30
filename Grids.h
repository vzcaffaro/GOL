#include <iostream>
#include <string>

class Grids{

    public:
    Grids();
    ~Grids();

    int** makeGrid(int rows, int columns, double density); //makes a 2d array, populates it, returns pointer to it
    void printGrid(int** myGrid, int rows, int columns); //prints grid out to terminal
    void streamGrid(int** myGrid, int rows, int columns, std::string file_name); //stream grid to file
    bool simulate(int** myGrid, int rows, int columns, int mode); //clones grid, simulates next generation, returns false if grid is the same after simulation as it was before
    bool checkEmpty(int** myGrid, int rows, int columns); //checks if grid is empty, returns false if it is


};
