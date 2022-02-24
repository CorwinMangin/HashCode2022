/*
** EPITECH PROJECT, 2022
** HashCode2022
** File description:
** Person
*/

#include "Person.hpp"

Person::Person()
{
}

Person::~Person()
{
}

void Person::AddSkill(std::string skill, size_t size)
{
    this->skills[skill] = size;
}