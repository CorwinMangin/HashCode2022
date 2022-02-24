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
        size_t bestBefore;
        std::map<std::string, bool> SkillNeeded;
        std::map<std::string, size_t> roles;
        std::list<Person> contributors;
 
        void AddSkillNeed(std::string nameSkill);
        void AddRole(std::string, size_t lvl);
        void AddContributor(Person &contributor);
        
    protected:
    private:
};

#endif /* !PROJECT_HPP_ */
