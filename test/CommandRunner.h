#pragma once
#include <string>
#include <memory>
#include "ToyRobot.h"

class CommandRunner
{
public:
	CommandRunner();
	CommandRunner(std::shared_ptr<ToyRobot>);
	~CommandRunner() = default;
	bool run(std::string);

private:
	bool validateCommand(const std::string&);
	bool isRobotPlaced();
	void place();
	void move();
	void left();
	void right();
	void report();

	std::shared_ptr<IToyRobot> toyRobot_;

	const std::vector<std::string> commands{ "place", "move", "left", "right", "report", "exit"};

};

