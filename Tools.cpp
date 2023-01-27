//
// Created by Linus Gasser on 26.01.23.
//

#include "Tools.h"
#include <fstream>

using namespace std;

// From librobots
vector<string> split(const string &s, const string &sep, size_t max_sep) {
    vector<string> ret;
    size_t last = 0;
    size_t next = 0;
    while ((next = s.find(sep, last)) != string::npos &&
           (ret.size() + 1 < max_sep || max_sep == 0)) {
        ret.push_back(s.substr(last, next - last));
        last = next + 1;
    }
    ret.push_back(s.substr(last));
    return ret;
}

// Vérifie si la ligne correspond au champ donné.
bool parse_line(bool &has, string &field, const string &label_search, const vector<string>& fields) {
    if (fields.at(0) == label_search) {
        if (has) {
            throw file_parse_error("Got " + fields.at(0) + " twice");
        }
        has = true;
        field = fields.at(1).substr();
    }
    return fields.at(0) == label_search;
}

Fields get_fields(const string &filename) {
    ifstream file(filename);
    if (!file.good()) {
        throw file_parse_error("File doesn't exist");
    }
    string str;
    bool read_body = false;
    Fields f;
    while (getline(file, str)) {
        auto fields = split(str, ":", 2);
        if (fields.size() > 1) {
            if (!(parse_line(f.has_sujet, f.sujet, "subject", fields) ||
                  parse_line(f.has_date, f.date, "date", fields) ||
                  parse_line(f.has_source, f.source, "from", fields) ||
                  parse_line(f.has_pour, f.pour, "to", fields))) {
                if (fields.at(0) == "body") {
                    if (f.has_corps) {
                        throw file_parse_error("Got two bodies");
                    }
                    f.has_corps = true;
                    read_body = true;
                } else {
                    if (read_body) {
                        f.corps += fields.at(0) + ":" + fields.at(1) + "\n";
                    } else {
                        throw file_parse_error("Unknown label name: " + fields.at(0));
                    }
                }
            }
        } else if (read_body) {
            f.corps += str + "\n";
        } else {
            throw file_parse_error("Found no-body line in non-body part");
        }
    }
    return f;
}
