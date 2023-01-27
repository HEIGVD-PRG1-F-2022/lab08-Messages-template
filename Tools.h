//
// Created by Linus Gasser on 26.01.23.
//

#ifndef INC_08_MESSAGES_TOOLS_H
#define INC_08_MESSAGES_TOOLS_H

#include <string>
#include <vector>
#include <exception>

/**
 * Erreur dans le parsing du fichier
 */
class file_parse_error: public std::runtime_error{
public:
    explicit file_parse_error(const std::string& what_arg): std::runtime_error(what_arg){};
};

/**
 * Erreur dans le type de fichier
 */
class wrong_type_error: public std::runtime_error{
public:
    explicit wrong_type_error(const std::string& what_arg): std::runtime_error(what_arg){};
};

/**
 * Ce champ n'existe pas dans le type de message
 */
class no_such_field: public std::runtime_error{
public:
    explicit no_such_field(): std::runtime_error(""){};
};

/**
 * Stocke les champs lus dans le fichier, et indique lesquels étaient présents.
 * Ceci permet aux différentes implémentations de vérifier quels champs étaient présents.
 */
struct Fields {
    std::string sujet, date, source, pour, corps;
    bool has_sujet = false, has_date = false, has_source = false, has_pour = false, has_corps = false;
};

/**
 * Lis un fichier et retourne un 'Fields'
 * @param filename à lire
 * @return un `Fields` rempli selon le fichier
 * Cette méthode lance une exception si:
 * - le fichier n'existe pas
 * - un champ est en double
 * - un champ avec un nom inconnu est détecté
 * - une ligne du corps est détécté en-dehors du "body:"
 */
Fields get_fields(const std::string &filename);

/**
 * Copié depuis `librobots`. Permet de séparer un string en plusieurs morceaux.
 * En plus on peut donner le nombre maximum de morceaux qu'on veut recevoir.
 * @param s à séparer
 * @param sep utilisé pour séparer `s`
 * @param max_sep limite supérieur de nombre de strings dans le vector de retour
 * @return un vecteur avec les différentes parties du string, sans la séparation
 */
std::vector<std::string> split(const std::string &s, const std::string &sep, size_t max_sep);

#endif//INC_08_MESSAGES_TOOLS_H
