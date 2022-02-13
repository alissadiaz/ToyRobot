#pragma once
#include <string>
#include <vector>
#include <map>
#include <tuple>

enum class ERotation
{
    right,
    left
};

class IPosition
{
public:
    virtual ~IPosition() = default;
    virtual void setPosition(int, int, std::string) = 0;
    virtual void move() = 0;
    virtual void rotate(const ERotation) = 0;
    virtual std::tuple<int, int, std::string> getPosition() = 0;
    virtual bool isPositionValid() = 0;
};

class Position : public IPosition
{
public:
    Position();
    Position(int, int, std::string);

    void setPosition(int, int, std::string);
    void move();
    void rotate(const ERotation);
    std::tuple<int, int, std::string> getPosition();
    bool isPositionValid();

private:
    bool isDirectionValid(const std::string&);
    bool isXYValid(int, int);

    void setXY(int, int);
    void setDir(const std::string&);

    bool isRotationValid(const std::string&);
    int getDirectionIndex();

    int x_;
    int y_;
    std::string dir_;

    const std::vector<std::string> directions{ "north", "east", "south", "west" };
    const std::vector<std::string> rotations{ "left", "right" };

    std::map<std::string, std::pair<int, int>> directionMover{
        {"north", std::make_pair(0,1)},
        {"south", std::make_pair(0,-1)},
        {"east", std::make_pair(1,0)},
        {"west", std::make_pair(-1,0)}
    };
};

