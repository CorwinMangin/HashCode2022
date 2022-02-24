/*
** PausePitech, 2022
** HashCode2022
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "Person.hpp"
#include "Project.hpp"
#include <iostream>
#include <list>

class Parser {
    public:
        Parser(std::string file);
        void parseMe();
        std::list<Person> getPerson();
        std::list<Project> getProject();
        void loop();
        int checkRecurrence(std::string line);
        ~Parser();

    protected:
    private:
        std::string _file;
        size_t _project;
        size_t _person;
        std::list<Person> _PersonList;
        std::list<Project> _ProjectList;
};

#endif /* !PARSER_HPP_ */
