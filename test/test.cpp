// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ToyRobot.h"

const std::vector<std::string> commands{ "place", "move", "left", "right", "report", "exit" };

bool validateCommand(const std::string& command)
{
    return std::find(commands.begin(), commands.end(), command) != commands.end();
}

Position requestPosition()
{
    int x, y;
    std::string dir, filler;
    std::cin >> x;
    std::cin >> filler;
    std::cin >> y;
    std::cin >> filler;
    std::cin >> dir;
    return Position(x, y, dir);
}

void requestInitialCommand(std::shared_ptr<ToyRobot> toyRobot)
{
    std::string initialCommand = "";
    auto currPos = toyRobot->getPosition();
    while (initialCommand != "place," || currPos.x_ < 0 || currPos.y_ < 0)
    {
        std::cout << "Enter initial command: " << std::endl;
        std::cin >> initialCommand;
        if (initialCommand != "place,")
        {
            std::cout << "Please try again." << std::endl;
            continue;
        }
        auto reqPos = requestPosition();
        toyRobot->runCommand(initialCommand, reqPos.x_, reqPos.y_, reqPos.dir_);
        currPos = toyRobot->getPosition();
        if (currPos.x_ < 0 || currPos.y_ < 0)
        {
            std::cout << "Invalid starting point." << std::endl;
        }
    };
}

void requestNextCommand(std::shared_ptr<ToyRobot> toyRobot)
{
    std::string command = "";
    while (command != "exit")
    {
        std::cout << "Enter next command: ";
        std::cin >> command;
        std::for_each(command.begin(), command.end(), [](char& c) {
            c = ::tolower(c); });
        if (!validateCommand(command))
        {
            std::cout << "Invalid command. Try again." << std::endl;
            continue;
        }
        if (command == "place,")
        {
            auto reqPos = requestPosition();
            toyRobot->runCommand(command, reqPos.x_, reqPos.y_, reqPos.dir_);
            continue;
        }
        toyRobot->runCommand(command);
    }
}

int main()
{
    std::shared_ptr<ToyRobot> toyRobot = std::make_shared<ToyRobot>();
    requestInitialCommand(toyRobot);
    requestNextCommand(toyRobot);
    std::cout << "Exiting" << std::endl;
    return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
