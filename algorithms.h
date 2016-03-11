/*******************************************************************
* Representacion de Datos
* ------------------------------------------------------------------
* Alejandro Garbi, 08-10398
* Email: alexgarbi10@gmail.com
********************************************************************/

#ifndef _Algorithms_h
#define _Algorithms_h

/* Headers y librerias */
#include "limits.h"
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define SIZE 690
#define GENE_SIZE 59
#define ATTRIBUTES 15
#define POPULATION 100
#define GENERATIONS 1000
#define RULE_SIZE 2
#define RULE_THRESHOLD 100
#define THRESHOLD 99
#define WORST 0.15
#define CROSSOVER_RATE 0.6
#define MUTATION_RATE 0.1
#define AA_RATE 0.05
#define DC_RATE 0.6
#define TOURNAMENT_SIZE 2
#define TRAINING_SIZE 0.7
#define TEST_SIZE 0.3
#define PENALTY_RATE 10

using namespace std;

/*******************************************************************
* Chromosome: Codificacion binaria para conjuntos de reglas IF-THEN
********************************************************************/

struct Chromosome {
	vector<int> rule;
	double fitness;
	bool aa;
	bool dc;
	bool survives;
};

/*******************************************************************
* Classifier: Clasificador por Algoritmo Genetico
********************************************************************/

class Classifier {
	private:
		// Datos GA
		int size;
		Chromosome hypothesis[POPULATION];
		//vector<Chromosome> hypothesis;
		vector<Chromosome> dataSet;
		vector<Chromosome> positivesSet;
		vector<Chromosome> negativesSet;
		vector<Chromosome> trainingSet;
		vector<Chromosome> testSet;
		vector<Chromosome> children;
		int best;
		double maxScore;
		double accuracy;
		double rules;
		bool penalty;
		bool tournament;
		bool worst;

		// Datos estadisticos
		double min2;
		double max2;
		double mean2;
		double min3;
		double max3;
		double mean3;
		double min8;
		double max8;
		double mean8;
		double min11;
		double max11;
		double mean11;
		double min14;
		double max14;
		double mean14;
		double min15;
		double max15;
		double mean15;
		int frequencyA1[2];
		int frequencyA4[4];
		int frequencyA5[3];
		int frequencyA6[14];
		int frequencyA7[9];
		int frequencyA9[2];
		int frequencyA10[2];
		int frequencyA12[2];
		int frequencyA13[3];

		// Rangos A2: [13,40],[40,60],[60,80]
		int frequencyA2[3];
		// Rangos A3: [0,10],[10,20],[20,28]
		int frequencyA3[3];
		// Rangos A8: [0,10],[10,20],[20,28.5]
		int frequencyA8[3];
		// Rangos A11: [0,20],[20,40],[40,67]
		int frequencyA11[3];
		// Rangos A14: [0,500],[500,1000],[1000,2000]
		int frequencyA14[3];
		// Rangos A15: [0,1000],[1000,5000],[5000,100000]
		int frequencyA15[3];

	public:

		Classifier(const char* filename);
		~Classifier();
		void Configure(bool selection, bool replacement);
		void UsePenalty(bool choise);
		void Preprocessing(const char *filename);
		int ReadFile(const char* filename);
		int GetSize() { return size; }
		void GA();
		double Fitness(Chromosome individual, vector<Chromosome> set);
		vector<Chromosome> CrossOver(Chromosome father1, Chromosome father2);
		Chromosome Mutate(Chromosome individual);
		Chromosome AddAlternative(Chromosome individual);
		Chromosome DropCondition(Chromosome individual);
		Chromosome RandomCreate(int genes);
		bool Valid(Chromosome individual, int attribute, int gene, int pos);
		void UpdateStatistics(string &line);
		void ProcessLine(string &line);
		int MaxFrequency(int index);

};

#endif
