/*
 *@autor: Alejandro Garbi
 *@correo: alexgarbi10@gmail.com
 *@archivo: main.cpp
 * TSP Solver 
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
    
    if (argc < 2) {
		cout << "Error: Faltan argumentos..." << endl;
		cout << "Uso: ./GA <archivo>" << endl;
		exit(1);
    }

    srand(time(0));
    Classifier problem(argv[1]);
    size = problem.GetSize();
    
    if (size == -1)
    	exit(1);
    

    //if (size != SIZE) {
    	//exit(1);
    //}

    time (&start);
    //problem.GA();
    time (&end);

     Chromosome individual = problem.RandomCreate(2);
     Chromosome individual2 = problem.RandomCreate(2);

    	for (int i=0; i < individual.rule.size(); i++) {
    		cout << individual.rule[i] << ", ";
    	}

    	cout << endl;
    	cout << individual.rule.size() << " ";
    	cout << endl;

    	for (int i=0; i < individual2.rule.size(); i++) {
    		cout << individual2.rule[i] << ", ";
    	}

    	cout << endl;
    	cout << individual2.rule.size() << " ";
    	cout << endl;

vector<Chromosome> children = problem.CrossOver(individual,individual2);

cout<<children.size() << endl;
for (int i=0; i < children[0].rule.size(); i++) {
	cout << children[0].rule[i] << ", ";
}

cout << endl;
cout << children[0].rule.size() << " ";
cout << endl;

for (int i=0; i < children[1].rule.size(); i++) {
	cout << children[1].rule[i] << ", ";
}

cout << endl;
cout << children[1].rule.size() << " ";
cout << endl;


    answer = difftime (end,start);
    cout.precision(2);
    cout << "Tiempo: " << fixed << answer << " segundos" << endl;
	cout << "-----------------------------------" << endl;
	cout << "-----------------------------------" << endl;
    exit(0);
}
