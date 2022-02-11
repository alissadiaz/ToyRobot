#include "ToyRobot.h"
#include <iostream>

bool enableLogger = false;
void logger(const std::string& func, const std::string& text)
{
    if (enableLogger)
    {
        std::cout << func << ": " << text << std::endl;
    }
}

ToyRobot::ToyRobot() : pos_(-1, -1, "")
{
}

void ToyRobot::runCommand(const std::string& command, int x, int y, std::string dir)
{
    logger(__FUNCTION__, "start");
    if (command == "place,")
        place(x, y, dir);
    else if (command == "move")
        move();
    else if (command == "left")
        left();
    else if (command == "right")
        right();
    else if (command == "report")
        report();
    else
        return;
    logger(__FUNCTION__, "end");
}

Position ToyRobot::getPosition()
{
    return pos_;
}

//privates
void ToyRobot::place(int x, int y, std::string dir)
{
    logger(__FUNCTION__, "start");
    std::for_each(dir.begin(), dir.end(), [](char& d) {
        d = ::tolower(d); });
    if (!validateXYPosition(x, y) || !validateDirection(dir))
    {
        std::cout << "Try again, invalid position" << std::endl;
        return;
    }
    pos_.x_ = x;
    pos_.y_ = y;
    pos_.dir_ = dir;
    logger(__FUNCTION__, "end");
}

void ToyRobot::move()
{
    logger(__FUNCTION__, "start");
    int tempX, tempY;
    tempX = pos_.x_ + directionMover[pos_.dir_].first;
    tempY = pos_.y_ + directionMover[pos_.dir_].second;
    if (!validateXYPosition(tempX, tempY))
    {
        std::cout << "Falling off the table. Try to change directions!" << std::endl;
        return;
    }
    pos_.x_ = tempX;
    pos_.y_ = tempY;
    logger(__FUNCTION__, "end");
}

void ToyRobot::left()
{
    logger(__FUNCTION__, "start");
    if (pos_.dir_ == "north")
        pos_.dir_ = "west";
    else if (pos_.dir_ == "west")
        pos_.dir_ = "south";
    else if (pos_.dir_ == "south")
        pos_.dir_ = "east";
    else if (pos_.dir_ == "east")
        pos_.dir_ = "north";
    logger(__FUNCTION__, "end");
}

void ToyRobot::right()
{
    logger(__FUNCTION__, "start");
    if (pos_.dir_ == "north")
        pos_.dir_ = "east";
    else if (pos_.dir_ == "east")
        pos_.dir_ = "south";
    else if (pos_.dir_ == "south")
        pos_.dir_ = "west";
    else if (pos_.dir_ == "west")
        pos_.dir_ = "north";
    logger(__FUNCTION__, "end");
}

void ToyRobot::report()
{
    logger(__FUNCTION__, "start");
    std::cout << pos_.x_ << ", " << pos_.y_ << ", " << pos_.dir_ << std::endl;
    logger(__FUNCTION__, "end");
}

bool ToyRobot::validateDirection(const std::string& direction)
{
    return std::find(directions.begin(), directions.end(), direction) != directions.end();
}

bool ToyRobot::validateXYPosition(int x, int y)
{
    return x > -1 && y > -1;
}
