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
#include <iostream>
#include "team.h"

namespace seneca
{
    Team::Team(const char* name) : m_name(name) {}

    Team::~Team()
    {
        for (size_t i = 0; i < m_size; ++i)
            delete m_members[i];
        delete[] m_members;
    }

    Team::Team(const Team& other)
        : m_name(other.m_name), m_size(other.m_size)
    {
        if (m_size > 0)
        {
            m_members = new Character*[m_size];
            for (size_t i = 0; i < m_size; ++i)
                m_members[i] = other.m_members[i]->clone();
        }
    }

    Team& Team::operator=(const Team& other)
    {
        if (this != &other)
        {
            for (size_t i = 0; i < m_size; ++i)
                delete m_members[i];
            delete[] m_members;
            m_members = nullptr;
            m_name = other.m_name;
            m_size = other.m_size;
            if (m_size > 0)
            {
                m_members = new Character*[m_size];
                for (size_t i = 0; i < m_size; ++i)
                    m_members[i] = other.m_members[i]->clone();
            }
        }
        return *this;
    }

    Team::Team(Team&& other) noexcept
        : m_name(std::move(other.m_name)),
          m_members(other.m_members),
          m_size(other.m_size)
    {
        other.m_members = nullptr;
        other.m_size = 0;
    }

    Team& Team::operator=(Team&& other) noexcept
    {
        if (this != &other)
        {
            for (size_t i = 0; i < m_size; ++i)
                delete m_members[i];
            delete[] m_members;
            m_name = std::move(other.m_name);
            m_members = other.m_members;
            m_size = other.m_size;
            other.m_members = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    void Team::addMember(const Character* c)
    {
        for (size_t i = 0; i < m_size; ++i)
        {
            if (m_members[i]->getName() == c->getName())
                return;
        }
        Character** newArr = new Character*[m_size + 1];
        for (size_t i = 0; i < m_size; ++i)
            newArr[i] = m_members[i];
        newArr[m_size] = c->clone();
        delete[] m_members;
        m_members = newArr;
        ++m_size;
    }

    void Team::removeMember(const std::string& c)
    {
        for (size_t i = 0; i < m_size; ++i)
        {
            if (m_members[i]->getName() == c)
            {
                delete m_members[i];
                for (size_t j = i; j < m_size - 1; ++j)
                    m_members[j] = m_members[j + 1];
                --m_size;
                return;
            }
        }
    }

    Character* Team::operator[](size_t idx) const
    {
        if (idx < m_size)
            return m_members[idx];
        return nullptr;
    }

    void Team::showMembers() const
    {
        if (m_name.empty())
        {
            std::cout << "No team." << std::endl;
        }
        else
        {
            std::cout << "[Team] " << m_name << std::endl;
            for (size_t i = 0; i < m_size; ++i)
                std::cout << "    " << i + 1 << ": " << *m_members[i] << std::endl;
        }
    }
}
