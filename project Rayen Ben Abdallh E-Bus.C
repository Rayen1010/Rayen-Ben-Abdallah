#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
typedef struct {
    char nom[50];
    char prenom[50];
    int age;
} Voyageur;

 
typedef struct {
    int numero;
    char destination[50];
    int capacite;
    int places_disponibles;
} Bus;

 
typedef struct {
    int numero_reservation;
    int numero_bus;
    char nom_voyageur[50];
    char prenom_voyageur[50];
} Reservation;

 
Voyageur* creer_voyageur(char nom[], char prenom[], int age) {
    Voyageur* voyageur = (Voyageur*)malloc(sizeof(Voyageur));
    strcpy(voyageur->nom, nom);
    strcpy(voyageur->prenom, prenom);
    voyageur->age = age;
    return voyageur;
}

 
Reservation* creer_reservation(int numero_reservation, int numero_bus, char nom_voyageur[], char prenom_voyageur[]) {
    Reservation* reservation = (Reservation*)malloc(sizeof(Reservation));
    reservation->numero_reservation = numero_reservation;
    reservation->numero_bus = numero_bus;
    strcpy(reservation->nom_voyageur, nom_voyageur);
    strcpy(reservation->prenom_voyageur, prenom_voyageur);
    return reservation;
}

 
void afficher_details_bus(Bus* bus) {
    printf("Numéro du bus : %d\n", bus->numero);
    printf("Destination : %s\n", bus->destination);
    printf("Capacité : %d\n", bus->capacite);
    printf("Places disponibles : %d\n", bus->places_disponibles);
}

 
void afficher_modifier_reservation(Reservation* reservation) {
    printf("Numéro de réservation : %d\n", reservation->numero_reservation);
    printf("Numéro du bus : %d\n", reservation->numero_bus);
    
    char nouveau_nom[50];
    char nouveau_prenom[50];
    
    
    char choix;
    printf("Voulez-vous modifier les détails de la réservation ? (O/N) : ");
    scanf(" %c", &choix);

    if (choix == 'O' || choix == 'o') {
         
        printf("Nouveau numéro du bus : ");
        scanf("%d", &reservation->numero_bus);
        
        printf("Nouveau nom du voyageur : ");
        scanf("%s", nouveau_nom);
        strcpy(reservation->nom_voyageur, nouveau_nom);
        
        printf("Nouveau prénom du voyageur : ");
        scanf("%s", nouveau_prenom);
        strcpy(reservation->prenom_voyageur, nouveau_prenom);
    } else {
      
        printf("Nom du voyageur : %s\n", reservation->nom_voyageur);
        printf("Prénom du voyageur : %s\n", reservation->prenom_voyageur);
    }
}



int main() {
    int nombre_voyageurs;

    printf("Combien de voyageurs souhaitez-vous saisir ? : ");
    scanf("%d", &nombre_voyageurs);

    Voyageur** voyageurs = (Voyageur**)malloc(nombre_voyageurs * sizeof(Voyageur*));
    Reservation** reservations = (Reservation**)malloc(nombre_voyageurs * sizeof(Reservation*));

 
    for (int i = 0; i < nombre_voyageurs; i++) {
        char nom_voyageur[50], prenom_voyageur[50];
        int age_voyageur;

        printf("\nVeuillez saisir les informations du voyageur %d :\n", i + 1);
        printf("Nom : ");
        fgets(nom_voyageur, sizeof(nom_voyageur), stdin);
        nom_voyageur[strcspn(nom_voyageur, "\n")] = 0;    
        
        printf("Prénom : ");
        fgets(prenom_voyageur, sizeof(prenom_voyageur), stdin);
        prenom_voyageur[strcspn(prenom_voyageur, "\n")] = 0;   
        
        printf("Age : ");
        scanf("%d", &age_voyageur);
        getchar();  
        

        voyageurs[i] = creer_voyageur(nom_voyageur, prenom_voyageur, age_voyageur);
        reservations[i] = creer_reservation(i + 1, i + 1, voyageurs[i]->nom, voyageurs[i]->prenom);
    }

     
    for (int i = 0; i < nombre_voyageurs; i++) {
        printf("\nDétails de la reservation pour le voyageur %d :\n", i + 1);
        afficher_modifier_reservation(reservations[i]);
    }

    
    for (int i = 0; i < nombre_voyageurs; i++) {
        free(voyageurs[i]);
        free(reservations[i]);
    }
    free(voyageurs);
    free(reservations);

    return 0;
}

