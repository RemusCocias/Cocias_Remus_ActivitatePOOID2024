#include<iostream>
#include<cstring>
using namespace std;

class Autobuz{
    private:
    const int idAutobuz;
    static int nrAutobuze;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;

    public:
    // Constructor fără parametri
    Autobuz():idAutobuz(++nrAutobuze){
    this->capacitate=0;
    this->nrPersoaneImbarcate=0;
    this->producator=new char[strlen("Necunoscut")+1];
    strcpy(this->producator,"Necunoscut");}
   
    // Constructor cu parametri
    Autobuz(const char* producator,int capacitate,int nrPersoane):idAutobuz(++nrAutobuze){
    if(nrPersoane<0 || nrPersoane>capacitate) throw invalid_argument("Numarul de persoane este invalid!");
    this->capacitate=capacitate;
    this->nrPersoaneImbarcate=nrPersoane;
    if(producator!=nullptr){
    this->producator=new char[strlen(producator)+1];
    strcpy(this->producator,producator);} 
    else{
    this->producator=nullptr;}}

    // Constructor de copiere
    Autobuz(const Autobuz& s):idAutobuz(++nrAutobuze){
    this->capacitate=s.capacitate;
    this->nrPersoaneImbarcate=s.nrPersoaneImbarcate;
    if (s.producator!=nullptr){
    this->producator=new char[strlen(s.producator)+1];
    strcpy(this->producator,s.producator);}
    else{
    this->producator=nullptr;}}

    //Destructor
    ~Autobuz(){
    if (producator!=nullptr){
    delete[] producator;}}

    //Metode accesor(get si set) pentru doua atribute
    int getCapacitate(){
    return capacitate;}

    void setCapacitate(int capacitateNoua){
    if(capacitateNoua<nrPersoaneImbarcate){
    throw invalid_argument("Capacitatea este mai mica decat numarul de persoane imbarcate!");}
    else{
    capacitate=capacitateNoua;}}

    int getNrPersoaneImbarcate(){
    return nrPersoaneImbarcate;}

    void setNrPersoaneImbarcate(int nrNou){
    if(nrNou>capacitate){
    throw invalid_argument("Numarul de persoane imbracate este mai mmare decat capacitatea!");}
    else{
    nrPersoaneImbarcate=nrNou;}}

    //Supraincarcarea operatorului "="
    Autobuz& operator=(const Autobuz& a){
    if(this==&a){
    return *this;}
    if(this->producator!=nullptr){
    delete[] this->producator;}
    this->capacitate=a.capacitate;
    this->nrPersoaneImbarcate=a.nrPersoaneImbarcate;
    if(a.producator!=nullptr) {
    int lungimeProducator=strlen(a.producator);
    this->producator=new char[lungimeProducator+1];
    strcpy(this->producator,a.producator);} 
    else{
    this->producator=nullptr;}
    return *this;}

    //Supraincarcarea operatorului "<<"" pentru afișarea obiectelor de tipul Autobuz
    friend ostream& operator<<(ostream& os, const Autobuz& a);

    int getNumarLocuriLibere(){
    return capacitate-nrPersoaneImbarcate;}

    operator int(){
    return this->nrPersoaneImbarcate;}

    bool operator>(const Autobuz& a){
    return this->capacitate>a.capacitate;}
};

ostream& operator<<(ostream& os, const Autobuz& a) {
    os<<a.idAutobuz<<"; "<<a.capacitate<<"; "<<a.nrPersoaneImbarcate<<"; ";
    if(a.producator==nullptr){
    os<<"nedefinit";} 
    else{
    os<<a.producator;}
    return os;}

int Autobuz::nrAutobuze=0;

int main(){
    char producator1[]="Producator 1";
    Autobuz a1(producator1,18,6);
    Autobuz a2(a1);                
    Autobuz a3;                    
    a3 = a1; 
    cout<< "a1: "<<a1<<"\n";
    cout<< "a2: "<<a2<<"\n";
    cout<< "a3: "<<a3<<"\n";

    a1.setCapacitate(7);
    cout<<"Capacitate a1: " <<a1.getCapacitate()<<"\n";

    a1.setNrPersoaneImbarcate(3);
    cout<< "Persoane imbarcate a1: "<<a1.getNrPersoaneImbarcate()<<"\n";
    cout<< "Numar locuri libere a1: "<<a1.getNumarLocuriLibere()<<"\n";

    int nrPersoaneImbarcate_a1=a1;
    cout<< "Persoane imbarcate a1: "<<nrPersoaneImbarcate_a1<<"\n";

    char producator2[] = "Producator 2";
    Autobuz a4(producator2,20,9);

    bool x=a1>a4; 
    cout<<"a1>a4: "<<x<<"\n";
    return 0;}
