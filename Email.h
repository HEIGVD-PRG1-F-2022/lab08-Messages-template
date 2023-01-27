//
// Created by Linus Gasser on 26.01.23.
//

#ifndef INC_08_MESSAGES_EMAIL_H
#define INC_08_MESSAGES_EMAIL_H

#include <string>
#include "Tools.h"

class Email {
    Fields fields;

public:
    explicit Email(const std::string &filename);

    [[nodiscard]] std::string lis_sujet() const;
    [[nodiscard]] std::string lis_date() const;
    [[nodiscard]] std::string lis_source() const;
    [[nodiscard]] std::string lis_pour() const;
    [[nodiscard]] std::string lis_corps() const;
};


#endif//INC_08_MESSAGES_EMAIL_H
