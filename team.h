/*****************************************************************************
 * Name:       Tamara Brinckman
 * Email:      tbrinckman@myseneca.ca
 * Student ID: 127790244
 * Date:       2026-10-16
 *
 * I declare that this submission is the result of my own work and I only
 * copied the code that my professor provided to complete my assignments.
 * This submitted piece of work has not been shared with any other student
 * or 3rd party content provider.
 *****************************************************************************/
#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include <string>
#include "character.h"

namespace seneca
{
    class Team
    {
        std::string m_name{};
        Character** m_members{ nullptr };
        size_t m_size{ 0 };
    public:
        Team() = default;
        Team(const char* name);
        ~Team();

        Team(const Team& other);
        Team& operator=(const Team& other);
        Team(Team&& other) noexcept;
        Team& operator=(Team&& other) noexcept;

        void addMember(const Character* c);
        void removeMember(const std::string& c);
        Character* operator[](size_t idx) const;
        void showMembers() const;
    };
}

#endif
