#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

void espaniolIngles(string entradaUsuario);
void inglesEspaniol(string entradaUsuario);
void guardarEnDiccionario(string nombreArchivo, const char entradaGuardarArchivo[]);

int main (){
    cout << "################## Menu ##################\n";
    cout << "Escribe la opcion que deseas realizar:\n";
    cout << "1.- Ingles-Espaniol\n";
    cout << "2.- Espaniol-Ingles\n";
    cout << "##########################################\n";
    int opcion;
    cin >> opcion;
    cout << "Ingresa la cadena a traducir: \n";
    string entradaATraducir;
    if (opcion==1) {
        cout << "############ Ingles-Espaniol #############\n";
        cin.ignore();
        std::getline (cin,entradaATraducir);
        inglesEspaniol(entradaATraducir);
        cout << "\n##########################################\n";
    } else if (opcion==2) {
        cout << "############ Espaniol-Ingles #############\n";
        cin.ignore();
        std::getline (cin,entradaATraducir);
        espaniolIngles(entradaATraducir);
        cout << "\n##########################################\n";
    }
}

void guardarEnDiccionario(string nombreArchivo, const char entradaGuardarArchivo[]){
    ofstream archivoDiccionario(nombreArchivo,ios_base::app);
    archivoDiccionario << "\n";
    archivoDiccionario << entradaGuardarArchivo;
    archivoDiccionario.close();
}

void inglesEspaniol(string entradaUsuario){
    string oracionTraducida,separarPalabra,palabraActual;
    vector <string> palabrasEntrada;
    stringstream oracion(entradaUsuario);
    while(getline(oracion, separarPalabra,' ')) {
        palabrasEntrada.push_back(separarPalabra);
    }
    bool bandera;
    for(int i = 0; i < palabrasEntrada.size();++i){
        bandera = false;
        FILE *archivoEspaniol = fopen ("espanol.txt","r");
        FILE *archivoIngles = fopen ("ingles.txt", "r");
        palabraActual = palabrasEntrada[i];
        while(!feof(archivoEspaniol)){
            char PalabraEspaniol[20],PalabraIngles[20];
            fscanf(archivoEspaniol,"%s",&PalabraEspaniol);
            fscanf(archivoIngles,"%s",&PalabraIngles);
            if(palabraActual == PalabraIngles){
                palabraActual = PalabraEspaniol;
                bandera = true;
                break;
            }
        }
        fclose(archivoEspaniol);
        fclose(archivoIngles);
        if(bandera == false) {
            cout << "\nLa palabra " << palabraActual << " No esta registrada\n en el diccionario\n";
            cout << "1.- Escribir la traduccion\n";
            cout << "2.- Continuar sin traducir\n";
            int opcion;
            scanf("%d",&opcion);
            if (opcion == 1) {
                cout << "Escribe la traduccion de la palabra: " << palabraActual << "\n";
                char traduccionDePalabraEntrada[20];
                scanf("%s",&traduccionDePalabraEntrada);
                guardarEnDiccionario("espanol.txt",traduccionDePalabraEntrada); //Guardar palabra traducida
                guardarEnDiccionario("ingles.txt",palabraActual.c_str()); //Guardar palabra original
                palabraActual = traduccionDePalabraEntrada;
            } else if (opcion == 2) {
                cout << "Continuando sin traducir la palabra " << palabraActual << "... \n";
            }
        }
        oracionTraducida = oracionTraducida + " " + palabraActual;
    }
    cout << oracionTraducida;
}

void espaniolIngles(string entradaUsuario){
    string oracionTraducida,separarPalabra,palabraActual;
    vector <string> palabrasEntrada;
    stringstream oracion(entradaUsuario);
    while(getline(oracion, separarPalabra,' ')) {
        palabrasEntrada.push_back(separarPalabra);
    }
    bool bandera;
    for(int i = 0; i < palabrasEntrada.size();++i){
        bandera = false;
        FILE *archivoEspaniol = fopen ("espanol.txt","r");
        FILE *archivoIngles = fopen ("ingles.txt", "r");
        palabraActual = palabrasEntrada[i];
        while(!feof(archivoEspaniol)){
            char PalabraEspaniol[20],PalabraIngles[20];
            fscanf(archivoEspaniol,"%s",&PalabraEspaniol);
            fscanf(archivoIngles,"%s",&PalabraIngles);
            if(palabraActual == PalabraEspaniol){
                palabraActual = PalabraIngles;
                bandera = true;
                break;
            }
        }
        fclose(archivoEspaniol);
        fclose(archivoIngles);
        if(bandera == false) {
            cout << "\nLa palabra " << palabraActual << " No esta registrada\n en el diccionario\n";
            cout << "1.- Escribir la traduccion\n";
            cout << "2.- Continuar sin traducir\n";
            int opcion;
            scanf("%d",&opcion);
            if (opcion == 1) {
                cout << "Escribe la traduccion de la palabra: " << palabraActual << "\n";
                char traduccionDePalabraEntrada[20];
                scanf("%s",&traduccionDePalabraEntrada);
                guardarEnDiccionario("espanol.txt",palabraActual.c_str()); //Guardar palabra original
                guardarEnDiccionario("ingles.txt",traduccionDePalabraEntrada); //Guardar palabra traducida
                palabraActual = traduccionDePalabraEntrada;
            } else if (opcion == 2) {
                cout << "Continuando sin traducir la palabra " << palabraActual << "... \n";
            }
        }
        oracionTraducida = oracionTraducida + " " + palabraActual;
    }
    cout << oracionTraducida;
}
