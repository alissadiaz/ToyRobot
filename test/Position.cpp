#include "Position.h"

#include <algorithm>
#include <iostream>

bool enableLogger = false;
void logger(const std::string& func, const std::string& text)
{
    if (enableLogger)
    {
        std::cout << func << ": " << text << std::endl;
    }
}

Position::Position() : x_(-1), y_(-1), dir_("")
{}

Position::Position(int x, int y, std::string dir)
{
    x_ = x;
    y_ = y;
    std::for_each(dir.begin(), dir.end(), [](char& d) {
        d = ::tolower(d); });
    dir_ = dir;
}

bool Position::isPositionValid()
{
    return isDirectionValid(dir_) && isXYValid(x_, y_);
}

void Position::setPosition(int x, int y, std::string dir)
{
    logger(__FUNCTION__, "start");
    std::for_each(dir.begin(), dir.end(), [](char& d) {
        d = ::tolower(d); });
    if (!isXYValid(x, y) || !isDirectionValid(dir))
    {
        std::cout << "Invalid input/s." << std::endl;
        return;
    }
    setXY(x, y);
    setDir(dir);
    logger(__FUNCTION__, "end");
}

void Position::move()
{
    logger(__FUNCTION__, "start");
    int tempX, tempY;
    tempX = x_ + directionMover[dir_].first;
    tempY = y_ + directionMover[dir_].second;
    if (!isXYValid(tempX, tempY))
    {
        std::cout << "Falling off the table. Try to change directions!" << std::endl;
        return;
    }
    x_ = tempX;
    y_ = tempY;
    logger(__FUNCTION__, "end");
}

void Position::setXY(int x, int y)
{
    logger(__FUNCTION__, "x: " + std::to_string(x) + "; y: " + std::to_string(y));
    x_ = x;
    y_ = y;
}

void Position::setDir(const std::string& dir)
{
    logger(__FUNCTION__, "dir: " + dir);
    dir_ = dir;
}

void Position::rotate(ERotation rot)
{
    logger(__FUNCTION__, "start");
    std::string newDir;
    int index = getDirectionIndex();
    if (rot == ERotation::left)
    {
        newDir = directions[(index + 4 - 1) % 4];
    }
    else
    {
        newDir = directions[(index + 4 + 1) % 4];
    }
    setDir(newDir);
    logger(__FUNCTION__, "end");

}

std::tuple<int, int, std::string> Position::getPosition()
{
    return std::make_tuple(x_, y_, dir_);
}

bool Position::isDirectionValid(const std::string& direction)
{
    return std::find(directions.begin(), directions.end(), direction) != directions.end();
}

bool Position::isXYValid(int x, int y)
{
    return x > -1 && y > -1;
}

bool Position::isRotationValid(const std::string& rot)
{
    return std::find(rotations.begin(), rotations.end(), rot) != rotations.end();
}

int Position::getDirectionIndex()
{
    auto currIndex = std::find(directions.begin(), directions.end(), dir_);
    return currIndex - directions.begin();
}