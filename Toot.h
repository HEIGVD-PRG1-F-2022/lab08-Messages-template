//
// Created by Linus Gasser on 26.01.23.
//

#ifndef INC_08_MESSAGES_TOOT_H
#define INC_08_MESSAGES_TOOT_H


#include <string>
#include "Tools.h"

class Toot {
    Fields fields;

public:
    explicit Toot(const std::string &filename);

    static std::string lis_sujet() ;
    [[nodiscard]] std::string lis_date() const;
    [[nodiscard]] std::string lis_source() const;
    static std::string lis_pour() ;
    [[nodiscard]] std::string lis_corps() const;
};



#endif//INC_08_MESSAGES_TOOT_H
