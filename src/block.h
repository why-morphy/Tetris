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
    void Draw();
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    int id;
    std::map<int, std::vector<Position>> cells;
};
