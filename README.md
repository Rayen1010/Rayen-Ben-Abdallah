Description du travail :
Structures de données :
Voyageur : Contient des informations sur un voyageur telles que le nom, le prénom et l'âge.
Bus : Représente les détails d'un bus comme son numéro, sa destination, sa capacité totale et le nombre de places disponibles.
Reservation : Stocke les informations sur une réservation, notamment le numéro de réservation, le numéro du bus et les détails du voyageur associé à cette réservation.
Fonctions :
creer_voyageur() : Alloue dynamiquement de la mémoire pour créer un nouveau voyageur avec les détails spécifiés (nom, prénom, âge).
creer_reservation() : Alloue dynamiquement de la mémoire pour créer une nouvelle réservation avec les détails spécifiés (numéro de réservation, numéro de bus, nom et prénom du voyageur).
afficher_details_bus() : Affiche les détails d'un bus spécifique passé en argument.
afficher_modifier_reservation() : Affiche les détails d'une réservation et permet à l'utilisateur de les modifier si nécessaire.
Logique du programme :
Initialisation des données : Création de voyageurs, déclaration de bus avec leurs détails et création de réservations associées à des voyageurs sur des bus spécifiques.
Affichage des détails : Affiche les détails des bus créés et des réservations effectuées.
Modification des réservations : Pour chaque réservation, le programme demande à l'utilisateur s'il souhaite modifier les détails. Si l'utilisateur le souhaite, il peut modifier le numéro du bus, le nom et le prénom du voyageur associé à la réservation.
Libération de la mémoire : Utilisation de la fonction free() pour libérer la mémoire allouée dynamiquement pour les voyageurs et les réservations à la fin du programme, évitant ainsi les fuites de mémoire.
