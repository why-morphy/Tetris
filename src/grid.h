#pragma once
#include <raylib.h>
#include <vector>
#include <iostream>

class Grid
{
private:
    int numRows, numColumns, sizeCells;
    std::vector<Color> colors;
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column);
    int grid[20][10];
};