/*
** PausePitech, 2022
** HashCode2022
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(std::string file)
{
    this->_file = file;
}

int Parser::checkRecurrence(std::string line)
{
    int ret = 0;
    for (size_t i = 0; i < line.size(); i++) {
        if (line.at(i) == ' ')
            ret += 1;
    }
    return ret;
}

void Parser::parseMe()
{
    bool person = false;
    int nbSkill;
    Person newPerson;
    Project newProject;
    std::string line;
    std::string name;
    std::ifstream openFile;
    bool project = false;
    bool insideProject = false;

    openFile.open(this->_file, std::ifstream::in);
    if (openFile.fail())
        std::cerr << "Wrong file";
    else {
        
        std::getline(openFile, line, ' ');
        this->_person = atoi(line.c_str());
        std::getline(openFile, line);
        this->_project = atoi(line.c_str());

        while (openFile.good()) {
            std::getline(openFile, line);
            if (nbSkill == 0 && person != false) {
                person = false;
                this->_PersonList.push_back(newPerson);
            }
            if (nbSkill == 0 && insideProject != false) {
                insideProject = false;
                this->_ProjectList.push_back(newProject);
            }
            if (!(checkRecurrence(line) > 2) && project == false) {
                if (person == false) {
                    newPerson = Person();
                    name = line.substr(0, line.find(' '));
                    line.erase(0, line.find(' '));
                    newPerson.name = name;
                    nbSkill = atoi(line.c_str());
                    person = true;
                }
                else if (person == true) {
                    name = line.substr(0, line.find(' '));
                    line.erase(0, line.find(' '));
                    newPerson.AddSkill(name, atoi(line.c_str()));
                    nbSkill -= 1;
                }
            } else {
                project = true;
                if (insideProject == false) {
                    newProject = Project();
                    name = line.substr(0, line.find(' '));
                    line.erase(0, line.find(' ') + 1);
                    newProject.name = name;
                    newProject.duration = atoi((line.substr(0, line.find(' '))).c_str());
                    newProject.daysLeft = atoi((line.substr(0, line.find(' '))).c_str());
                    line.erase(0, line.find(' ') + 1);
                    newProject.points = atoi((line.substr(0, line.find(' '))).c_str());
                    line.erase(0, line.find(' ') + 1);
                    newProject.bestBefore = atoi((line.substr(0, line.find(' '))).c_str());
                    line.erase(0, line.find(' ') + 1);
                    newProject.nbContributors = atoi((line.substr(0, line.find(' '))).c_str());
                    nbSkill = atoi((line.substr(0, line.find(' '))).c_str());
                    std::cout << "nbskill: " << nbSkill << "\n";
                    insideProject = true;
                }
                else if (insideProject == true) {
                    nbSkill -= 1;
                    name = line.substr(0, line.find(' '));
                    line.erase(0, line.find(' '));
                    newProject.setSkillLevel(name, atoi(line.c_str()));
                    newProject.AddSkillNeed(name);
                }
            }
        }
    }
    // for (auto v : _PersonList) {
    //     std::cout << v.name << " ";
    //     std::cout << "C++" << v.skills["C++"] << " ";
    //     std::cout << "HTML" << v.skills["HTML"] << " ";
    //     std::cout << "CSS" << v.skills["CSS"] << " ";
    //     std::cout << "Python" << v.skills["Python"] << "\n";
    // }
    // for (auto v : _ProjectList) {
    //     std::cout << v.name << "\n";
    //     std::cout << "C++" << v.skillLevel["C++"] << " ";
    //     std::cout << "HTML" << v.skillLevel["HTML"] << " ";
    //     std::cout << "CSS" << v.skillLevel["CSS"] << " ";
    //     std::cout << "Python" << v.skillLevel["Python"] << "\n";
    // }
    openFile.close();
}

std::list<Person> Parser::getPerson()
{
    return this->_PersonList;
}

std::list<Project> Parser::getProject()
{
    return this->_ProjectList;
}

Parser::~Parser()
{
}
