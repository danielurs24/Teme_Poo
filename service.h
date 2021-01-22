#include <iostream>

class service{

private:

    std::string locatie;
    std::string manager;
    int locuri_masini;


public:



    service(const  std::string &locatie = "Focsani",const  std::string &manager = "Manager", const int &locuriMasini = 2)  {

        this->locatie=locatie;
        this->locuri_masini=locuriMasini;
        this->manager=manager;

    }
    service operator=(service &a) {
        if(this!=&a)
        {
            locatie=a.locatie;
            locuri_masini=a.locuri_masini;
            manager=a.manager;
        }
        return *this;
    }

    const  std::string &getLocatie() const {

        return locatie;
    }
    void setLocatie(const  std::string &locatie) {

        service::locatie = locatie;
    }

    const  std::string &getManager() const {

        return manager;
    }

    void setManager(const  std::string &manager) {

        service::manager = manager;
    }

    int getLocuriMasini() const {

        return locuri_masini;
    }

    void setLocuriMasini(int locuriMasini) {

        locuri_masini = locuriMasini;
    }

    virtual void info()
    {
        std:: cout << "Service-ul din " << locatie << " unde manager este " << manager << " are " << locuri_masini<< " locuri libere pentru reparatii \n";
    }

    int seRepara();

    int Reparata();

    virtual ~service() {

        std::cout << "Service-ul din " << locatie << " s-a inchis" << "\n";
    }
};

int service::seRepara(){

    return locuri_masini--;
}
int service::Reparata(){

    return locuri_masini++;
}
class service_factory{
public:
    static service service_bucuresti() { return service ("Bucuresti","Alex",5);}
    static service service_cluj() { return service ("Cluj","Marius", 5);}
};