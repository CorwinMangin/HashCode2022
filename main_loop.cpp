// PausePitech

#include "Project.hpp"
#include "Person.hpp"
#include <list>

using std::string;

//return true if every projects are filled with peoples 
bool areAllProjectsFilled(std::list<Project> projects)
{
    for (std::list<Project>::iterator it = projects.begin(); it != projects.end(); it++) {
        if (it->isCompleted == false && it->isBeingWorkedOn == false)
            return true;
    }
    return false;
}

Project *findShortestDeadLine(std::list<Project> projects)
{
    Project *res;

    for (std::list<Project>::iterator it = projects.begin(); it != projects.end(); it++)
        if (it->isCompleted == false && it->isBeingWorkedOn == false)
            res = &*it;
    for (std::list<Project>::iterator it = projects.begin(); it != projects.end(); it++)
        if (res->bestBefore < it->bestBefore)
            res = &*it;
    return (res);
}

void freePersons(std::list<Person> workers, std::list<Project> projects)
{
    for (std::list<Project>::iterator it_a = projects.begin(); it_a != projects.end(); it_a++) {
        if (it_a->daysLeft == 0) {
            it_a->isCompleted == true;
            it_a->isBeingWorkedOn == false;
            for (std::list<Person>::iterator it_b = it_a->contributors.begin(); it_b != it_a->contributors.end(); it_b++)
                it_b->isFree = true;
        }
    }
}

void fillContributors(Project *currentProject, std::list<Person> workers)
{
    for (std::map<string, bool>::iterator it = currentProject->skillNeeded.begin(); it != currentProject->skillNeeded.end(); it++)
    }
}

void startProject(Project *currentProject)
{

}

void mainLoop(std::list<Person> workers, std::list<Project> projects)
{
    size_t days = 0;

    while (/* loop condition */) {
        Project *currentProject = findShortestDeadLine(projects);

        freePersons(workers, projects);
        fillContributors(currentProject, workers);
        days++;
    }
}