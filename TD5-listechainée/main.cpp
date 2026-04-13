#include "Link.h"
#include "LinkedList.h"
#include <iostream>

void afficherListe(LinkedList& liste) {
    std::cout << "Liste (taille=" << liste.size() << "): ";
    for (int i = 0; i < liste.size(); i++) {
        std::cout << liste[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    try {
        LinkedList liste1;
        liste1.add(10);
        liste1.add(20);
        liste1.add(30);
        liste1.add(40);
        afficherListe(liste1);

        std::cout << "Element a la position 0: " << liste1[0] << std::endl;
        std::cout << "Element a la position 2: " << liste1[2] << std::endl;

        liste1.insert(25, 2);
        afficherListe(liste1);

        liste1.insert(5, 0);
        afficherListe(liste1);

        liste1.remove(2);
        afficherListe(liste1);

        liste1.remove(0);
        afficherListe(liste1);

        LinkedList liste2;
        std::cout << "Taille liste vide: " << liste2.size() << std::endl;
        liste2.add(100);
        afficherListe(liste2);

        try {
            liste1[100];
        }
        catch (std::out_of_range& e) {
            std::cout << "Exception capturee: " << e.what() << std::endl;
        }

        while (liste2.size() > 0) {
            liste2.remove(0);
        }
        std::cout << "Liste vide, taille: " << liste2.size() << std::endl;

        {
            LinkedList liste3;
            liste3.add(1);
            liste3.add(2);
            liste3.add(3);
        }
        return 0;

    }
    catch (std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
        return 1;
    }
}