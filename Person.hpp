/*
** EPITECH PROJECT, 2022
** HashCode2022
** File description:
** Person
*/

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <fstream>
#include <map>

class Person {
    public:
        Person();
        ~Person();
        std::string skillNextLevel;
        std::string name;
        std::map<std::string, size_t> skills;

    protected:
    private:
};

#endif /* !PERSON_HPP_ */
