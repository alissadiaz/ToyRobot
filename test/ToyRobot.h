#include "Position.h"
#include <memory>

class IToyRobot
{
public:
    virtual ~IToyRobot() = default;
    virtual bool isPlaced() = 0;
    virtual std::tuple<int, int, std::string> report() = 0;
    virtual void move() = 0;
    virtual void rotate(const ERotation) = 0;
    virtual void place(int, int, const std::string&) = 0;
};

class ToyRobot : public IToyRobot
{
public:
    ToyRobot();

    bool isPlaced();
    std::tuple<int, int, std::string> report();
    void move();
    void rotate(const ERotation);
    void place(int, int, const std::string&);

private:
    std::shared_ptr<IPosition> pos_;
};
