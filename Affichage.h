//
// Created by Linus Gasser on 26.01.23.
//

#ifndef INC_08_MESSAGES_AFFICHAGE_H
#define INC_08_MESSAGES_AFFICHAGE_H

#include <string>
#include <vector>

/**
 * Index invalide de message
 */
class no_such_message: public std::runtime_error{
public:
    explicit no_such_message(): std::runtime_error(""){};
};

template<typename T>
class Affichage {
    std::vector<T> messages;

public:
    /**
     * Contrairement à l'énoncé, ce constructeur prend un "path" et
     * va parser tous les fichiers.
     * Il ne gardera que les messages qui n'ont pas lancé d'exception.
     * @param path
     */
    explicit Affichage(const std::string &path);

    /**
     * Ajoute un nouveau message à la liste.
     * @param el - nouveau message
     */
    void ajouter_element(T el);

    /**
     * Afficher la liste des messages.
     * @return nombre d'éléments de la liste.
     */
    size_t afficher_liste();

    /**
     * Afficher un élément de la liste.
     * @param el l'index de l'élément à afficher. Si l'index n'existe pas,
     * une exception est lancée.
     */
    void afficher_element(size_t el);
};

#include "Affichage.tpp"

#endif//INC_08_MESSAGES_AFFICHAGE_H
