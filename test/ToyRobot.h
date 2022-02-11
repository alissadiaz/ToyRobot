#ifndef _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#endif // !_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING


#include <algorithm>
#include <vector>
#include <map>
#include <string>

struct Position
{
    Position(int x, int y, std::string dir)
    {
        x_ = x;
        y_ = y;
        std::for_each(dir.begin(), dir.end(), [](char d) {
            d = ::tolower(d); });
        dir_ = dir;
        //std::cout << dir << std::endl;
    }
    Position(const Position& pos)
    {
        x_ = pos.x_;
        y_ = pos.y_;
        std::for_each(pos.dir_.begin(), pos.dir_.end(), [](char d) {
            d = ::tolower(d); });
        dir_ = pos.dir_;
       // std::cout << dir_ << std::endl;
    }

    int x_;
    int y_;
    std::string dir_;
};

class ToyRobot
{
public:
    ToyRobot();
    ~ToyRobot() = default;
    void runCommand(const std::string&, int x = 0, int y = 0, std::string = "");
    Position getPosition();

private:
    //Position requestPosition();
    void place(int, int, std::string);
    void move();
    void left();
    void right();
    void report();

    bool validateXYPosition(int, int);
    bool validateDirection(const std::string&);
    //bool validateCommand(const std::string&);

    Position pos_;

    const std::vector<std::string> directions{ "north", "east", "south", "west" };
    std::map<std::string, std::pair<int, int>> directionMover{
        {"north", std::make_pair(0,1)},
        {"south", std::make_pair(0,-1)},
        {"east", std::make_pair(1,0)},
        {"west", std::make_pair(-1,0)}
    };

};
