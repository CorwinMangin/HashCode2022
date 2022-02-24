#include "Parser.hpp"
#include <fstream>

void startProject(Project *currentProject)
{
    std::ofstream openFile;
    currentProject->isBeingWorkedOn = true;
    openFile.open("Delivery.txt");
    openFile << '\n';
    openFile << currentProject->name << '\n';
    for (auto v : currentProject->contributors)
        openFile << v.name << ' ';
}