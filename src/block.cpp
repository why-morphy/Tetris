#include "block.h"

Block::Block()
{
    sizeCell = 30;
    stateRotation = 0;
    colors = GetCellColors();
    offsetRow = 0;
    offsetColumn = 0;
}

void Block::Draw() {
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles) {
        DrawRectangle(item.column * sizeCell + 1, item.row * sizeCell + 1, sizeCell - 1, sizeCell - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns) {
    offsetRow += rows;
    offsetColumn += columns;
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