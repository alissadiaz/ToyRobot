#include <iostream>
#include "CommandRunner.h"

int main()
{
    std::shared_ptr<ToyRobot> toyRobot = std::make_shared<ToyRobot>();
    std::shared_ptr<CommandRunner> commandRunner = std::make_shared<CommandRunner>(toyRobot);

    std::string command = "";
    do
    {
        std::cout << "Enter command: ";
        std::cin >> command;

    } while (commandRunner->run(command));
    
    std::cout << "Exiting" << std::endl;
    return 1;
}
