#include "ToyRobot.h"
#include <iostream>

ToyRobot::ToyRobot()
{
	pos_ = std::make_shared<Position>(-1, -1, "");
}

bool ToyRobot::isPlaced()
{
	return pos_->isPositionValid();
}

std::tuple<int, int, std::string> ToyRobot::report()
{
	return pos_->getPosition();
}

void ToyRobot::move()
{
	pos_->move();
}

void ToyRobot::rotate(const ERotation rot)
{
	pos_->rotate(rot);
}

void ToyRobot::place(int x, int y, const std::string& dir)
{
	pos_->setPosition(x, y, dir);
}