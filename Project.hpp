/*
** EPITECH PROJECT, 2022
** HashCode2022
** File description:
** Project
*/

#ifndef PROJECT_HPP_
#define PROJECT_HPP_

class Project {
    public:
        Project();
        ~Project();

        std::string name;
        size_t duration;
        size_t bestBefore;
        std::map<std::string, size_t> roles;
        

    protected:
    private:
};

#endif /* !PROJECT_HPP_ */
