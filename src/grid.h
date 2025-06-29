#pragma once
#include <raylib.h>
#include <vector>
#include <iostream>

class Grid
{
private:
    int numRows, numColumns, sizeCells;
    std::vector<Color> colors;
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int grid[20][10];
    int ClearFullRows();
};