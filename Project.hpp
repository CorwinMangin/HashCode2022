/*
** EPITECH PROJECT, 2022
** HashCode2022
** File description:
** Project
*/

#ifndef PROJECT_HPP_
#define PROJECT_HPP_

#include <fstream>
#include <map>
#include <list>
#include "Person.hpp"

class Project {
    public:
        Project();
        ~Project();

        std::string name;
        size_t duration;
        size_t daysLeft;
        size_t bestBefore;
        size_t points;
        size_t nbContributors;
        std::map<std::string, bool> skillNeeded;
        std::map<std::string, size_t> roles;
        std::list<Person> contributors;
        bool isCompleted;
        bool isBeingWorkedOn;
        
        void AddSkillNeed(std::string nameSkill);
        void AddRole(std::string nameRole, size_t lvl);
        void AddContributor(Person &contributor, std::string skill);
        
    protected:
    private:
};

#endif /* !PROJECT_HPP_ */
