#include "block.h"

Block::Block()
{
    sizeCell = 30;
    stateRotation = 0;
    colors = GetCellColors();
    offsetRow = 0;
    offsetColumn = 0;
}

void Block::Draw(int offsetX, int offsetY) {
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles) {
        DrawRectangle(item.column * sizeCell + offsetX, item.row * sizeCell + offsetY, sizeCell - 1, sizeCell - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns) {
    offsetRow += rows;
    offsetColumn += columns;
}

void Block::Rotate()
{
    stateRotation++;
    if (stateRotation == (int)cells.size())
    {
        stateRotation = 0;
    }
}

void Block::UndoRotation()
{
    stateRotation--;
    if (stateRotation == -1)
    {
        stateRotation = cells.size() - 1;
    }
}

std::vector<Position> Block::GetCellPositions() {
    std::vector<Position> tiles = cells[stateRotation];
    std::vector<Position> movedTiles;
    for (Position item : tiles) {
        Position newPos = Position(item.row + offsetRow, item.column + offsetColumn);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}