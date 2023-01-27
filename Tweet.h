//
// Created by Linus Gasser on 26.01.23.
//

#ifndef INC_08_MESSAGES_TWEET_H
#define INC_08_MESSAGES_TWEET_H


#include <string>
#include "Tools.h"

class Tweet {
    Fields fields;

public:
    explicit Tweet(const std::string &filename);

    static std::string lis_sujet() ;
    [[nodiscard]] std::string lis_date() const;
    [[nodiscard]] std::string lis_source() const;
    static std::string lis_pour() ;
    [[nodiscard]] std::string lis_corps() const;
};



#endif//INC_08_MESSAGES_TWEET_H
