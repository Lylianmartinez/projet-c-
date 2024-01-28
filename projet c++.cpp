#include <iostream>
#include <string>

// Classe abstraite pour un service de maintenance
class ServiceMaintenance {
public:
    virtual void effectuerMaintenance() = 0;
};

// Structure pour représenter les coordonnées d'un lieu
struct Coordonnees {
    double latitude;
    double longitude;

    Coordonnees(double lat, double lon) : latitude(lat), longitude(lon) {}
};

// Classe de base Vehicule
class Vehicule {
public:
    virtual void demarrer() = 0;
    virtual void arreter() {
        std::cout << "Le vehicule est arrete." << std::endl;
    }
};

// Classe Voiture héritant de Vehicule
class Voiture : public Vehicule, public ServiceMaintenance {
private:
    std::string marque;
    std::string modele;
    Coordonnees position;  // Nouvelle fonctionnalité : position du véhicule

public:
    Voiture(std::string m, std::string mod, double lat, double lon) : marque(m), modele(mod), position(lat, lon) {}

    void demarrer() override {
        std::cout << "La voiture de marque " << marque << " et de modele " << modele << " demarre." << std::endl;
    }

    void effectuerMaintenance() override {
        std::cout << "Maintenance de la voiture effectuee." << std::endl;
    }

    void afficherPosition() {
        std::cout << "Position de la voiture : Latitude " << position.latitude << ", Longitude " << position.longitude << std::endl;
    }
};

// Nouvelle classe Moto héritant de Vehicule
class Moto : public Vehicule {
private:
    std::string marque;
    std::string modele;

public:
    Moto(std::string m, std::string mod) : marque(m), modele(mod) {}

    void demarrer() override {
        std::cout << "La moto de marque " << marque << " et de modele " << modele << " demarre." << std::endl;
    }
};

// Fonction utilitaire pour effectuer une opération générique sur un Vehicule
void effectuerOperation(Vehicule& vehicule) {
    vehicule.demarrer();
    vehicule.arreter();
}

int main() {
    Voiture maVoiture("Toyota", "Yaris", 48.8566, 2.3522);
    maVoiture.demarrer();
    maVoiture.arreter();
    maVoiture.effectuerMaintenance();
    maVoiture.afficherPosition();

    Moto maMoto("Honda", "CBR");
    effectuerOperation(maMoto);

    return 0;
}
