//
// Created by Linus Gasser on 26.01.23.
//

#include "Tweet.h"

using namespace std;

Tweet::Tweet(const string &filename) {
    fields = get_fields(filename);
    if (!(fields.has_corps && fields.has_date && fields.has_source)) {
        throw wrong_type_error("Some fields are missing");
    } else if ((fields.has_sujet || fields.has_pour)) {
        throw wrong_type_error("Supplementary fields found");
    } else if (fields.date.empty() || fields.source.empty()) {
        throw wrong_type_error("Some necessary fields are empty");
    }
}

string Tweet::lis_date() const {
    return fields.date;
}
string Tweet::lis_source() const {
    return fields.source;
}
string Tweet::lis_corps() const {
    return fields.corps;
}

string Tweet::lis_sujet() {
    throw no_such_field();
}
string Tweet::lis_pour() {
    throw no_such_field();
}
