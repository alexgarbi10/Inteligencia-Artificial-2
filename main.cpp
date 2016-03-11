/*
*@autor: Alejandro Garbi
*@correo: alexgarbi10@gmail.com
*@archivo: main.cpp
* Clasificador por Algoritmo Genetico
*/

#include "algorithms.h"
#include "time.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {
  time_t start,end;
  double answer;
  int size;
  bool tournament = false;
  bool rouletteWheel = false;
  bool replaceFather = false;
  bool replaceWorst = false;
  bool penalty = false;
  bool fileFlag = false;
  int file = -1;

  if (argc < 3) {
    cout << "Error: Faltan argumentos..." << endl;
    cout << "Uso: ./GA <opciones> -f <archivo>" << endl;
    cout << "donde las opciones pueden ser: " << endl;
    cout << " -st  Selección por torneo" << endl;
    cout << " -sr  Selección por rueda de la ruleta" << endl;
    cout << " -rd  Reemplazo directo de los padres" << endl;
    cout << " -rp  Reemplazo de los peores estocástico (10% de la población)" << endl;
    cout << " --p  Penalización sobre la longitud de las reglas" << endl;
    return -1;
  }

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i],"-st") == 0) tournament = true;
    else if (strcmp(argv[i],"-sr") == 0) rouletteWheel = true;
    else if (strcmp(argv[i],"-rd") == 0) replaceFather = true;
    else if (strcmp(argv[i],"-rp") == 0) replaceWorst = true;
    else if (strcmp(argv[i],"--p") == 0) penalty = true;
    else if (strcmp(argv[i],"-f") == 0) {
      file = i+1;
      fileFlag = true;
    }
  }

  if (!tournament && !rouletteWheel) {
    cout << "Error: Debe seleccionar el método de selección para el clasificador" << endl;
    cout << "Uso: ./GA <opciones> <archivo>" << endl;
    cout << "donde las opciones pueden ser: " << endl;
    cout << " -st  Selección por torneo" << endl;
    cout << " -sr  Selección por rueda de la ruleta" << endl;
    cout << " -rd  Reemplazo directo de los padres" << endl;
    cout << " -rp  Reemplazo de los peores estocástico (10% de la población)" << endl;
    cout << " --p  Penalización sobre la longitud de las reglas" << endl;
    return -1;
  }

  if (tournament && rouletteWheel) {
    cout << "Error: Debe seleccionar solo un método de selección para el clasificador" << endl;
    cout << "Uso: ./GA <opciones> <archivo>" << endl;
    cout << "donde las opciones pueden ser: " << endl;
    cout << " -st  Selección por torneo" << endl;
    cout << " -sr  Selección por rueda de la ruleta" << endl;
    cout << " -rd  Reemplazo directo de los padres" << endl;
    cout << " -rp  Reemplazo de los peores estocástico (10% de la población)" << endl;
    cout << " --p  Penalización sobre la longitud de las reglas" << endl;
    return -1;
  }

  if (!replaceFather && !replaceWorst) {
    cout << "Error: Debe seleccionar el método de reemplazo para el clasificador" << endl;
    cout << "Uso: ./GA <opciones> <archivo>" << endl;
    cout << "donde las opciones pueden ser: " << endl;
    cout << " -st  Selección por torneo" << endl;
    cout << " -sr  Selección por rueda de la ruleta" << endl;
    cout << " -rd  Reemplazo directo de los padres" << endl;
    cout << " -rp  Reemplazo de los peores estocástico (10% de la población)" << endl;
    cout << " --p  Penalización sobre la longitud de las reglas" << endl;
    return -1;
  }

  if (replaceFather && replaceWorst) {
    cout << "Error: Debe seleccionar solo un método de reemplazo para el clasificador" << endl;
    cout << "Uso: ./GA <opciones> <archivo>" << endl;
    cout << "donde las opciones pueden ser: " << endl;
    cout << " -st  Selección por torneo" << endl;
    cout << " -sr  Selección por rueda de la ruleta" << endl;
    cout << " -rd  Reemplazo directo de los padres" << endl;
    cout << " -rp  Reemplazo de los peores estocástico (10% de la población)" << endl;
    cout << " --p  Penalización sobre la longitud de las reglas" << endl;
    return -1;
  }

  if (!fileFlag) {
    cout << "Error: Debe indicar un archivo" << endl;
    cout << "Uso: ./GA <opciones> <archivo>" << endl;
    cout << "donde las opciones pueden ser: " << endl;
    cout << " -st  Selección por torneo" << endl;
    cout << " -sr  Selección por rueda de la ruleta" << endl;
    cout << " -rd  Reemplazo directo de los padres" << endl;
    cout << " -rp  Reemplazo de los peores estocástico (10% de la población)" << endl;
    cout << " --p  Penalización sobre la longitud de las reglas" << endl;
    return -1;
  }

  if (!ifstream(argv[file]).good()) {
    cout << "Error: El archivo seleccionado no pudo abrirse" << endl;
    return -1;
  };

  srand(time(0));
  Classifier problem(argv[file]);
  size = problem.GetSize();

  if (tournament && replaceWorst) problem.Configure(true, true);
  else if (tournament && replaceFather) problem.Configure(true, false);
  else if (rouletteWheel && replaceWorst) problem.Configure(false, true);
  else if (rouletteWheel && replaceFather) problem.Configure(false, false);

  if (penalty) problem.UsePenalty(true);
  else problem.UsePenalty(false);

  if (size == -1) exit(1);

  if (size != SIZE) exit(1);

  time (&start);
  problem.GA();
  time (&end);

  answer = difftime (end,start);
  cout.precision(2);
  cout << "Tiempo: " << fixed << answer << " segundos" << endl;
  cout << "-----------------------------------" << endl;
  cout << "-----------------------------------" << endl;
  exit(0);
}
