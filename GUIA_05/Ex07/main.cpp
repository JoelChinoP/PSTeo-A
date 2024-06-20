#include <iostream>
using namespace std;
struct FechaNacimiento {
    int dia;
    int mes;
    int anho;
};
struct Persona {
    string nombre;
    FechaNacimiento cumple;
};

int main(){

    //Insertando ciertos datos
    Persona persona[4];
    persona[0].nombre = "Juan";
    persona[0].cumple.dia = 6;
    persona[0].cumple.mes = 1;
    persona[0].cumple.anho = 2003;

    persona[1].nombre = "Pedro";
    persona[1].cumple.dia = 8;
    persona[1].cumple.mes = 1;
    persona[1].cumple.anho = 2004;

    persona[2].nombre = "Pedro";
    persona[2].cumple.dia = 13;
    persona[2].cumple.mes = 2;
    persona[2].cumple.anho = 2006;

    persona[3].nombre = "Pedro";
    persona[3].cumple.dia = 10;
    persona[3].cumple.mes = 2;
    persona[3].cumple.anho = 1990;

    int mes=100;
    while (mes != 0){
        cout << "Ingrese el mes que desea ver los cumpleanos?" << endl;
        cin >> mes;
        string resultado = "";
        for(int i=0; i<4; i++){


            if (persona[i].cumple.mes == mes){
                //cout << "Las personas que cumplen anhos en el mes " << mes << "son" << endl;
                string retorno = persona[i].nombre + " " +to_string(persona[i].cumple.dia) +"/"+ to_string(persona[i].cumple.mes) +"/"+ to_string(persona[i].cumple.anho) + "\n";
                resultado = resultado + retorno;
            }

        }
        if (resultado == ""){
            cout << "No se encontraron cumpleanos en este mes" << endl;
        }else {
            cout << "Las personas que cumplen anos el mes de "<< mes  << " son" << endl;
            cout << resultado << endl;
        }
    }


    return 0;
}
