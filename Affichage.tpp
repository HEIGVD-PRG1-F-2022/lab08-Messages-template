#include "Tools.h"
#include <filesystem>
#include <functional>
#include <string>

template<typename T>
Affichage<T>::Affichage(const std::string &path) {
    for (const auto &entry: std::filesystem::directory_iterator(path)) {
        try {
            ajouter_element(T(entry.path()));
        } catch (std::runtime_error &e) {
            std::cerr << "Error while reading " << entry.path() << ": " << e.what() << std::endl;
        }
    }
}

template<typename T>
void Affichage<T>::ajouter_element(T el) {
    messages.push_back(el);
}

template<typename T>
size_t Affichage<T>::afficher_liste() {
    for (size_t pos = 1; auto const &msg: messages) {
        try {
            std::string date(msg.lis_date()), source(msg.lis_source());
            std::cout << pos << " : " << date << " - " << source << std::endl;
        } catch (const no_such_field &e) {
            std::cout << pos << " : invalid entry" << std::endl;
        }
        ++pos;
    }
    return messages.size();
}

/**
 * Supplément: utilisation de std::function pour simplifier `afficher_element`.
 * Pas vu au cours: il faut utiliser une lambda, sinon on ne peut pas passer l'appel
 * à une méthode d'une classe.
 * @param label
 * @param print
 */
void print_field(const std::string &label, const std::function<std::string()> &print) {
    try {
        std::string field = print();
        std::cout << label << ": " << field << std::endl;
    } catch (no_such_field &) {
    }
}

template<typename T>
void Affichage<T>::afficher_element(size_t el) {
    if (el >= messages.size()) {
        throw no_such_message();
    }
    T msg = messages.at(el);

    print_field("Source", [msg]() { return msg.lis_source(); });
    print_field("Pour", [msg]() { return msg.lis_pour(); });
    print_field("Date", [msg]() { return msg.lis_date(); });
    print_field("Sujet", [msg]() { return msg.lis_sujet(); });
    print_field("Corps", [msg]() { return "\n" + msg.lis_corps(); });
}
