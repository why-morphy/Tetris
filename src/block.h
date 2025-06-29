#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
private:
    int sizeCell, stateRotation, offsetRow, offsetColumn;
    std::vector<Color> colors;
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    void Rotate();
    void UndoRotation();
    std::vector<Position> GetCellPositions();
    int id;
    std::map<int, std::vector<Position>> cells;
};
