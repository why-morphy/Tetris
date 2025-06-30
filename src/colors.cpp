#include "colors.h"

const Color darkPurple = {34, 22, 43, 255};
const Color green = {47, 230, 23, 255};
const Color red = {186, 59, 70, 255};
const Color orange = {237, 155, 64, 255};
const Color yellow = {248, 198, 48, 255};
const Color purple = {249, 179, 209, 255};
const Color cyan = {21, 204, 209, 255};
const Color blue = {8, 72, 135, 255};
const Color lightPurple = {114, 78, 145, 255};
const Color darkBlue = {44, 44, 127, 255};

std::vector<Color> GetCellColors() {
    return {darkPurple, green, red, orange, yellow, purple, cyan, blue};
}