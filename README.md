# Labo 08 - Messages

Dans ce labo, vous devez programmer un petit logiciel qui peut afficher des
emails et des toots qui sont stockés dans leur répertoire respectif.
L'affichage est fait par une classe générique qui s'appelle `Afficher`.
En plus vous devez faire une classe `Email` pour représenter les emails
et une classe `Toot` pour représenter les toots.
Le tout sera dirigé par la méthode `main` qui doit faire la chose suivante:

1. Demander à l'utilisateur s'iel veut afficher les Toots, les Emails, ou
s'iel veut quitter
2. Pour le média demandé, afficher la liste des messages disponibles.
Ou quitter si tel était le choix de l'utilisateur.
3. Demander à l'utilisateur quel message afficher au complet
4. Afficher le message
5. Retourner à 1.

Si une des classes émet une exception en lisant un fichier, `main` doit s'arrêter
et afficher un message pour l'utilisateur.

## Classe générique `Afficher`

Cette classe générique peut stocker un type d'éléments quelconque, du moment
que les éléments contiennent les méthodes suivantes:
- `string lis_sujet()`
- `string lis_date()`
- `string lis_source()`
- `string lis_pour()`
- `string lis_corps()`

La classe `Afficher` doit contenir les méthodes suivantes:

- `void ajouter_element(T el)` - ajoute un élément de type `T` à la classe
- `size_t afficher_liste()` - affiche l'index, la date et l'auteur, 
puis retourne le nombre d'éléments dans la liste
- `void afficher_element(size_t el)` - affiche toutes les informations disponibles pour
l'élément choisit

## Classe `Toot`

Le constructeur de la classe `Toot` prend un nom de fichier et interprète les
informations suivantes contenu dans le fichier: la `date`, la `source` et le `corps`.
Regardez les fichiers dans le répertoire `toots/` pour vous faire une idée comment
ces informations sont stockées.

Si un des éléments ne peut pas être lus, la classe doit émettre une exception.

## Classe `Email`

Le constructeur de la classe `Email` prend un nom de fichier et interprète les
informations suivantes contenu dans le fichier: la `date`, la `source`, le `corps`,
le `pour`, et le `sujet`.
Regardez les fichiers dans le répertoire `emails/` pour vous faire une idée comment
ces informations sont stockées.

Si un des éléments ne peut pas être lus, la classe doit émettre une exception.

# Consignes pour ce labo

- Créez la classe `Afficher` en tant que classe générique
- Utilisez les méthodes vues au cours pour les `string`
- Ajoutez des exceptions si quelque chose ne marche pas comme prévu
- Attrapez les exceptions dans les bons endroits et quittez avec une erreur compréhensible
- Utilisez les "best practices" des autres labos (fichiers séparés, commentaires, ...)

# Bonus

- lire et vérifier la date pas seulement en tant que string, mais en tant que
vraie date. Vous pouvez utiliser la méthode [get_time](https://en.cppreference.com/w/cpp/io/manip/get_time).
Si la date n'est pas correcte, émettez une exception.
- changez l'interprétation de façon que les champs peuvent apparaître dans n'importe
ordre.
- ajoutez une classe `SMS` qui peut lire les SMSs et les afficher comme les `Email` et les
`Toot`