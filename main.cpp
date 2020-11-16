#include <iostream>

using namespace std ;

class Masina{

private:

    string marca;
    string model;
    string culoare;
    int pret;

public:

    Masina(const string &marca, const string &model, const string &culoare, const int &pret) {

        this->marca=marca;
        this->model=model;
        this->culoare=culoare;
        this->pret=pret;

    }

    Masina(){

        this->marca="FaraMarca";
        this->model="FaraModel";
        this->culoare="FaraCuloare";
        this->pret=0;
    }

    Masina(const Masina &mas) {

        this->marca=mas.marca;
        this->model=mas.model;
        this->culoare=mas.culoare;
        this->pret=mas.pret;

    }

    const string &getMarca() const {

        return marca;
    }

    void setMarca(const string &marca) {

        Masina::marca = marca;
    }

    const string &getModel() const {

        return model;
    }

    void setModel(const string &model) {

        Masina::model = model;
    }

    const string &getCuloare() const {

        return culoare;
    }

    void setCuloare(const string &culoare) {

        Masina::culoare = culoare;
    }

    int getPret() const {

        return pret;
    }

    void setPret(int pret) {

        Masina::pret = pret;
    }

    virtual ~Masina() {

        cout << "Masina " << this->marca << " " << this->model << " a fost distrusa" << "\n";

    }

    friend ostream &operator<<(ostream &m, const Masina &masina1) {
        m << masina1.getMarca() << " " << masina1.getModel();
        return m;
    }

    void inService();
    void outService();

};

void Masina::inService(){

    cout << "Masina " << marca << " " << model << " de culoare " << culoare << " cu pretul de " << pret << "$ a intrat in service " << "\n";
};

void Masina::outService(){

    cout << "Masina " << this->marca << " " << this->model << " a fost reparata" << "\n";
};

class service{

private:

    string locatie;
    string manager;
    int locuri_masini;


public:



    service(const string &locatie = "Focsani",const string &manager = "Manager", const int &locuriMasini = 2)  {

    this->locatie=locatie;
    this->locuri_masini=locuriMasini;
    this->manager=manager;

}
    service(const service &srv) {

        this->manager = srv.manager;
        this->locatie = srv.locatie;
        this->locuri_masini = srv.locuri_masini;

    }

    const string &getLocatie() const {

        return locatie;
    }
    void setLocatie(const string &locatie) {

        service::locatie = locatie;
    }

    const string &getManager() const {

        return manager;
    }

    void setManager(const string &manager) {

        service::manager = manager;
    }

    int getLocuriMasini() const {

        return locuri_masini;
    }

    void setLocuriMasini(int locuriMasini) {

        locuri_masini = locuriMasini;
    }

    virtual ~service() {

        cout << "Service-ul din " << locatie << " s-a inchis" << "\n";
    }



    int seRepara();
    int Reparata();


};

    int service::seRepara(){

        return locuri_masini--;
    }
    int service::Reparata(){

    return locuri_masini++;
}



class reparatie{

private:

    string denumire;
    int durata;
    int cost;
    Masina m = Masina();

public:

    reparatie(const string &denumire, int durata, int cost,const Masina &m=Masina()) {

        this->denumire=denumire;
        this->durata=durata;
        this->cost=cost;
        this->m=m;

    }

    virtual ~reparatie() {


    }

    const string &getDenumire() const {

        return denumire;
    }

    void setDenumire(const string &denumire) {

        reparatie::denumire = denumire;
    }

    int getDurata() const {

        return durata;
    }

    void setDurata(int durata) {

        reparatie::durata = durata;
    }

    int getCost() const {

        return cost;
    }

    void setCost(int cost) {

        reparatie::cost = cost;
    }

    const Masina &getM() const {
        return m;
    }

    void setM(const Masina &m) {
        reparatie::m = m;
    }

    friend ostream &operator<<(ostream &m, const reparatie &rep) {
        m << "Se face operatiunea de "  << rep.getDenumire() << " la masina " << rep.getM() << " cu costul de " << rep.getCost() << " de lei care dureaza " << rep.getDurata() << " de minute \n";
        return m;
    }
};


int main() {

    service service1("Bucuresti","Alex",5);
    service service2("Cluj","Marius", 5);

    service service3 = service1;

    //cout << "Service-ul din " << service1.getLocatie() << " unde manager este " << service1.getManager() << " are " << service1.getLocuriMasini()<< " locuri libere pentru reparatii \n";
    //cout << "Service-ul din " << service2.getLocatie() << " unde manager este " << service2.getManager() << " are " << service2.getLocuriMasini()<< " locuri libere pentru reparatii \n";
    //cout << "Service-ul din " << service3.getLocatie() << " unde manager este " << service3.getManager() << " are " << service3.getLocuriMasini()<< " locuri libere pentru reparatii \n";

    service3 = service2;

    //cout << "Service-ul din " << service3.getLocatie() << " unde manager este " << service3.getManager() << " are " << service3.getLocuriMasini()<< " locuri libere pentru reparatii \n\n\n";

    Masina masina1("BMW","X5","Negru",5000);
    Masina masina2("Audi","A3","Verde",4000);

    reparatie repMasina1("Revizie", 40, 700,masina1);
    reparatie repMasina2("Schimb Placute de frana", 30, 350, masina2);

    masina1.inService();
    masina2.inService();

    service1.seRepara();

    cout <<"\n" << repMasina1;

    service1.Reparata();
    masina1.outService();
    //cout << masina1;




    return 0;
}
