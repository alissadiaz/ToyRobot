#include <iostream>
#include <algorithm>
#include "CommandRunner.h"

CommandRunner::CommandRunner()
{
	toyRobot_ = std::make_shared<ToyRobot>();
}

CommandRunner::CommandRunner(std::shared_ptr<ToyRobot> toyRobot) : toyRobot_(toyRobot)
{}

//add regex handling
bool CommandRunner::run(std::string command)
{
	std::for_each(command.begin(), command.end(), [](char& c) {
		c = ::tolower(c); });
	if (!validateCommand(command))
	{
		std::cout << "Invalid Command. Try again." << std::endl;
		return true;
	}

	if (command == "place")
		place();
	else if (command == "move")
		move();
	else if (command == "left")
		left();
	else if (command == "right")
		right();
	else if (command == "report")
		report();
	else
		return false;
	return true;
}

bool CommandRunner::validateCommand(const std::string& command)
{
	return std::find(commands.begin(), commands.end(), command) != commands.end();
}

void CommandRunner::place()
{
	int x, y;
	std::string dir, filler;
	std::cin >> x;
	std::cin >> filler;
	std::cin >> y;
	std::cin >> filler;
	std::cin >> dir;
	toyRobot_->place(x, y, dir);
}

void CommandRunner::move()
{
	if (!isRobotPlaced())
	{
		std::cout << "Place robot first." << std::endl;
		return;
	}
	toyRobot_->move();
}

void CommandRunner::left()
{
	if (!isRobotPlaced())
	{
		std::cout << "Place robot first." << std::endl;
		return;
	}
	toyRobot_->rotate(ERotation::left);
}

void CommandRunner::right()
{
	if (!isRobotPlaced())
	{
		std::cout << "Place robot first." << std::endl;
		return;
	}
	toyRobot_->rotate(ERotation::right);
}

void CommandRunner::report()
{
	if (!isRobotPlaced())
	{
		std::cout << "Place robot first." << std::endl;
		return;
	}
	int x, y;
	std::string dir;
	std::tie(x, y, dir) = toyRobot_->report();
	std::cout << x << ", " << y << ", " << dir << std::endl;
}

bool CommandRunner::isRobotPlaced()
{
	return toyRobot_->isPlaced();
}