# ToyRobot

Hi!
I've used Visual Studio to write the code. So compilation and tests are running via IDE.
I created a separate project for the unit tests which is in https://github.com/alissadiaz/ToyRobotTest, ToyRobotTest/test.cpp

Not the perfect solution yet, and needs more work with input handling and validation, like being space and comma separated for place commands.

I've sent a separate gdrive link containing the generated executable file by VS via email. 

Example input/output:
  Enter initial command:
  place, 1, 2, north
  Enter next command: move
  Enter next command: move
  Enter next command: report
  1, 4, north
  Enter next command: left
  Enter next command: report
  1, 4, west
  Enter next command: left
  Enter next command: left
  Enter next command: report
  1, 4, east
  Enter next command: place, 2, 3, north
  Enter next command: report
  2, 3, north
  
  
