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
#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H

#include <string>
#include "character.h"

namespace seneca
{
    class Guild
    {
        std::string m_name{};
        Character** m_members{ nullptr };
        size_t m_size{ 0 };
    public:
        Guild() = default;
        Guild(const char* name);
        ~Guild();

        Guild(const Guild& other);
        Guild& operator=(const Guild& other);
        Guild(Guild&& other) noexcept;
        Guild& operator=(Guild&& other) noexcept;

        void addMember(Character* c);
        void removeMember(const std::string& c);
        Character* operator[](size_t idx) const;
        void showMembers() const;
    };
}

#endif
