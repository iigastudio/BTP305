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
#include "guild.h"

namespace seneca
{
    Guild::Guild(const char* name) : m_name(name) {}

    Guild::~Guild()
    {
        delete[] m_members;
    }

    Guild::Guild(const Guild& other)
        : m_name(other.m_name), m_size(other.m_size)
    {
        if (m_size > 0)
        {
            m_members = new Character*[m_size];
            for (size_t i = 0; i < m_size; ++i)
                m_members[i] = other.m_members[i];
        }
    }

    Guild& Guild::operator=(const Guild& other)
    {
        if (this != &other)
        {
            delete[] m_members;
            m_members = nullptr;
            m_name = other.m_name;
            m_size = other.m_size;
            if (m_size > 0)
            {
                m_members = new Character*[m_size];
                for (size_t i = 0; i < m_size; ++i)
                    m_members[i] = other.m_members[i];
            }
        }
        return *this;
    }

    Guild::Guild(Guild&& other) noexcept
        : m_name(std::move(other.m_name)),
          m_members(other.m_members),
          m_size(other.m_size)
    {
        other.m_members = nullptr;
        other.m_size = 0;
    }

    Guild& Guild::operator=(Guild&& other) noexcept
    {
        if (this != &other)
        {
            delete[] m_members;
            m_name = std::move(other.m_name);
            m_members = other.m_members;
            m_size = other.m_size;
            other.m_members = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    void Guild::addMember(Character* c)
    {
        for (size_t i = 0; i < m_size; ++i)
        {
            if (m_members[i] == c)
                return;
        }
        Character** newArr = new Character*[m_size + 1];
        for (size_t i = 0; i < m_size; ++i)
            newArr[i] = m_members[i];
        newArr[m_size] = c;
        delete[] m_members;
        m_members = newArr;
        ++m_size;
        c->setHealthMax(c->getHealthMax() + 300);
    }

    void Guild::removeMember(const std::string& c)
    {
        for (size_t i = 0; i < m_size; ++i)
        {
            if (m_members[i]->getName() == c)
            {
                m_members[i]->setHealthMax(m_members[i]->getHealthMax() - 300);
                for (size_t j = i; j < m_size - 1; ++j)
                    m_members[j] = m_members[j + 1];
                --m_size;
                return;
            }
        }
    }

    Character* Guild::operator[](size_t idx) const
    {
        if (idx < m_size)
            return m_members[idx];
        return nullptr;
    }

    void Guild::showMembers() const
    {
        if (m_name.empty())
        {
            std::cout << "No guild." << std::endl;
        }
        else
        {
            std::cout << "[Guild] " << m_name << std::endl;
            for (size_t i = 0; i < m_size; ++i)
                std::cout << "    " << i + 1 << ": " << *m_members[i] << std::endl;
        }
    }
}
