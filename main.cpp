#include <iostream>
#include <vector>
#include "masina.h"
#include "service.h"
#include "reparatie.h"

using namespace std ;

int main() {

    service service1 = service_factory::service_bucuresti();
    service service2 = service_factory::service_cluj();

    service *service3;
    service3 = &service1;

    service1.info();
    service2.info();

    service3->info();

    service3 = &service2; // op =

    service3->info();

    cout << "\n";

    Masina masina1 = masina_factory::BMW_X5();
    Masina masina2 = masina_factory::Audi_A3();



    reparatie repMasina1("Revizie", 40, masina1);
    reparatie repMasina2("Schimb Placute de frana", 30, masina2);

    masina1.inService();
    masina2.inService();

    cout << "\n";

    repMasina1.seRepara(); //scade numarul de locuri din service

    service3 = &repMasina1; // Functia virtuala
    service3->info();


    repMasina1.cost_reparatie(700); //costuri reparatie
    repMasina1.cost_reparatie(500);

    masina1.outService(); //masina a fost reparata

    repMasina1.Reparata(); //creste numarul de locuri din service

    repMasina1.afisare_pret_total(); // afisare pret reparatie

    cout << "\n"; //




    return 0;
}
