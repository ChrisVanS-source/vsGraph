#pragma once

#include <string>

struct const_char_star {

    const char* m_s;

    const_char_star(const char* s) : m_s(s) {}

    inline const_char_star(const std::string& s) : const_char_star(s.data()) {}
};
