#include<iostream>
#include<string>
#include<math.h>
#include<sstream>
#include <typeinfo>
using namespace std;

class Auto{
string type;
double prijsPerDag;
public:

Auto (string tp = "", double prPD = 0){
    type = tp;
    prijsPerDag = prPD;
}
string operator() (){
return toString();
}

void setPrijsPerDag(double prPD){
prijsPerDag = prPD;
}

double getPrijsPerDag(){
    return prijsPerDag;
}
string toString(){
       if (type.length() == 0){
       return "er is geen huurder bekend"; 
    }
    stringstream output;
    output << "autotype: "<< type <<" met prijs per dag: " << prijsPerDag;
    return output.str();
}
    friend ostream& operator<<(std::ostream& os, const Auto& rhs) { //Dit stukje code heb ik van een mede-student gekregen om de laatste 2 prints aan de praat te krijgen.
        os << rhs.type << " met de prijs per dag: " << rhs.prijsPerDag << endl;
        return os;
    }
};


class Klant{
string naam;
double kortingsPercentage;
public:

Klant (string nm = "",double kP = 0):naam(nm),kortingsPercentage(kP){}
void setKorting(double kP){
    kortingsPercentage = (100-kP)/100;
}
double getKorting(){
    return kortingsPercentage;
}

string toString(){
    if (naam.length() == 0){
       return "er is geen huurder bekend"; 
    }
    stringstream output;
    output << "op naam van: " << naam << " (korting: " << 100-(kortingsPercentage*100) << "%)";
    return output.str();
    }
};

class AutoHuur{
int aantalDagen;
Klant huurder;
Auto gehuurdeAuto;

public:
AutoHuur(){
    aantalDagen = 0;

}
void setAantalDagen(int aD){
    aantalDagen = aD;
}
void setGehuurdeAuto(Auto gA){
    gehuurdeAuto = gA;
}

Auto getGehuurdeAuto(){
    return gehuurdeAuto;
}

void setHuurder(Klant k){
    huurder = k;
}

Klant getHuurder(){
    return huurder;
}

double totaalPrijs(){
    return gehuurdeAuto.getPrijsPerDag()*aantalDagen*huurder.getKorting();
}

string toString(){
    stringstream output;
    output << "\n"<<gehuurdeAuto.toString()<<"\n"<<huurder.toString()<<"\naantal dagen: " << to_string(aantalDagen) << " en dat kost " << totaalPrijs()<<endl;
    return output.str();
}
};


int main(){
AutoHuur ah1;
cout<<"Eerste autohuur: " + ah1.toString()<<endl;

Klant k("Mijnheer de Vries");
k.setKorting(10.0);
ah1.setHuurder(k);
cout<<"Eerste autohuur: " + ah1.toString()<<endl;

Auto a1("Peugeot 207", 50);
ah1.setGehuurdeAuto(a1);
ah1.setAantalDagen(4);
cout<<"Eerste autohuur: " + ah1.toString()<<endl;

AutoHuur ah2;
Auto a2("Ferarri", 3500);
ah2.setGehuurdeAuto(a2);
ah2.setHuurder(k);
ah2.setAantalDagen(1);
cout<<"Tweede autohuur: " + ah2.toString()<<endl;


cout<<endl<<"Gehuurd: " << ah1.getGehuurdeAuto();
cout<<"Gehuurd: " << ah2.getGehuurdeAuto()<<endl;

}
