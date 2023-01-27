//
// Created by Linus Gasser on 26.01.23.
//

#include "Email.h"
#include <vector>

using namespace std;

Email::Email(const string &filename) {
    fields = get_fields(filename);
    if (!(fields.has_sujet && fields.has_corps && fields.has_date && fields.has_pour && fields.has_source)){
        throw wrong_type_error("Some fields are missing");
    } else if (fields.source.empty() || fields.date.empty() || fields.pour.empty()){
        throw wrong_type_error("Some necessary fields are empty");
    }
}

string Email::lis_sujet() const {
    return fields.sujet;
}
string Email::lis_date() const {
    return fields.date;
}
string Email::lis_source() const {
    return fields.source;
}
string Email::lis_pour() const {
    return fields.pour;
}
string Email::lis_corps() const {
    return fields.corps;
}
