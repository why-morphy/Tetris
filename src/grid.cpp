#include "grid.h"
#include "colors.h"

Grid::Grid() {
    numRows = 20;
    numColumns = 10;
    sizeCells = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize() {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numColumns; column++) {
            grid[row][column] = 0;
        }
    }
}

void Grid::Print() {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numColumns; column++) {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw() {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numColumns; column++) {
            int cellValue = grid[row][column];
            DrawRectangle(column * sizeCells + 1, row * sizeCells + 1, sizeCells - 1, sizeCells - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numColumns)
    {
        return false;
    }
    return true;
}
