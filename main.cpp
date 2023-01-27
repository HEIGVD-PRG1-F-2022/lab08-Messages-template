//
// Fichier principal pour le labo 08 - Messages
//

#include <iostream>
#include <libdio/display.h>

#include "Affichage.h"
#include "Email.h"
#include "Toot.h"
#include "Tweet.h"

using namespace std;

/**
 * Affiche la liste des messages et demande d'en choisir une.
 * Supplément: Permet de retourner au menu principal.
 * @tparam T
 * @param show la classe d'affichage
 */
template<typename T>
void showMessages(Affichage<T> show) {
    while (true) {
        size_t elements = show.afficher_liste();
        cout << "Please choose a message, or 0 for main menu" << endl;
        size_t choice;
        cin >> choice;
        if (cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong entry" << endl << endl;
            continue;
        }
        if (choice > elements) {
            cout << "This element doesn't exist" << endl
                 << endl;
            continue;
        } else if (choice == 0) {
            cout << "Going back to main menu" << endl;
            return;
        }

        show.afficher_element(choice - 1);
        cout << endl;
    }
}

int main() {
    Display::init();

    cout << "Please wait while reading messages..." << endl;
    // Supplément: l' `Affichage` peut lire directement tous les fichiers d'un répertoire et
    // ne garde que les fichiers valides.
    Affichage<Email> emails("../Emails");
    Affichage<Tweet> tweets("../Tweets");
    Affichage<Toot> toots("../Toots");
    cout << "Messages read successfully" << endl;

    while (true) {
        Display::clearScreen();
        cout << "Please choose between (e)mails, (t)weets, or t(o)ots. Or use (q)uit" << endl;
        string s;
        cin >> s;
        if (s.empty()) {
            continue;
        }
        switch (char(tolower(s[0]))) {
            case 'e':
                showMessages(emails);
                break;
            case 't':
                showMessages(tweets);
                break;
            case 'o':
                showMessages(toots);
                break;
            case 'q':
                cout << "Goodbye" << endl;
                return 0;
            default:
                break;
        }
    }
}
