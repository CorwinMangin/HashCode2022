/*
** EPITECH PROJECT, 2022
** HashCode2022
** File description:
** Project
*/

#include "Project.hpp"

Project::Project()
{
}

Project::~Project()
{
}

void Project::AddSkillNeed(std::string nameSkill)
{
    this->skillNeeded[nameSkill] = false;
}

void Project::setSkillLevel(std::string skillName, size_t level)
{
    this->skillLevel[skillName] = level;
}

void Project::AddContributor(Person &contributor, std::string skill)
{
    contributor.isFree = false;
    size_t skillAsk = this->skillLevel[skill];
    size_t skillNbr = contributor.skills[skill];
    if (skillAsk <= skillNbr)
        contributor.skills[skill] += 1;
    this->skillNeeded[skill] = true;
    this->contributors.push_back(contributor);
}

