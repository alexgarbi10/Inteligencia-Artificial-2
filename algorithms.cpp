/*
 *@autor: Alejandro Garbi
 *@correo: alexgarbi10@gmail.com
 *@archivo: algorithms.cpp
 * Algoritmo Genetico
 */

#include "algorithms.h"

using namespace std;

Classifier::Classifier(const char* filename) {
	cout << "-----------------------------------" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Preprocesando datos..." << endl;
	cout << "-----------------------------------" << endl;
	Preprocessing(filename);
	cout << "Archivo: " << filename << "\nLectura finalizada..." << endl << endl;
	cout << "Atributos continuos:" << endl;
	cout << "- A2-> " << "Rango: [" << min2 << "," << max2 << "] Promedio: " << mean2 << endl;
	cout << "   Frecuencia [13.75,30): " << frequencyA2[0] << endl;
	cout << "   Frecuencia [30,50): " << frequencyA2[1] << endl;
	cout << "   Frecuencia [50,80.25]: " << frequencyA2[2] << endl;
	cout << "- A3-> " << "Rango: [" << min3 << "," << max3 << "] Promedio: " << mean3 << endl;
	cout << "   Frecuencia [0,5): " << frequencyA3[0] << endl;
	cout << "   Frecuencia [5,15): " << frequencyA3[1] << endl;
	cout << "   Frecuencia [15,28]: " << frequencyA3[2] << endl;
	cout << "- A8-> " << "Rango: [" << min8 << "," << max8 << "] Promedio: " << mean8 << endl;
	cout << "   Frecuencia [0,5): " << frequencyA8[0] << endl;
	cout << "   Frecuencia [5,15): " << frequencyA8[1] << endl;
	cout << "   Frecuencia [15,28.5]: " << frequencyA8[2] << endl;
	cout << "- A11-> " << "Rango: [" << min11 << "," << max11 << "] Promedio: " << mean11 << endl;
	cout << "   Frecuencia [0,5): " << frequencyA11[0] << endl;
	cout << "   Frecuencia [5,20): " << frequencyA11[1] << endl;
	cout << "   Frecuencia [20,67]: " << frequencyA11[2] << endl;
	cout << "- A14-> " << "Rango: [" << min14 << "," << max14 << "] Promedio: " << mean14 << endl;
	cout << "   Frecuencia [0,200): " << frequencyA14[0] << endl;
	cout << "   Frecuencia [200,500): " << frequencyA14[1] << endl;
	cout << "   Frecuencia [500,2000]: " << frequencyA14[2] << endl;
	cout << "- A15-> " << "Rango: [" << min15 << "," << max15 << "] Promedio: " << mean15 << endl;
	cout << "   Frecuencia [0,1000): " << frequencyA15[0] << endl;
	cout << "   Frecuencia [1000,5000): " << frequencyA15[1] << endl;
	cout << "   Frecuencia [5000,100000]: " << frequencyA15[2] << endl;
	cout << endl;
	cout << "Atributos nominales:" << endl;
	cout << "- A1-> " << endl;
	cout << "   Frecuencia b: " << frequencyA1[0] << endl;
	cout << "   Frecuencia a: " << frequencyA1[1] << endl;
	cout << "- A4-> " << endl;
	cout << "   Frecuencia u: " << frequencyA4[0] << endl;
	cout << "   Frecuencia y: " << frequencyA4[1] << endl;
	cout << "   Frecuencia l: " << frequencyA4[2] << endl;
	cout << "   Frecuencia t: " << frequencyA4[3] << endl;
	cout << "- A5-> " << endl;
	cout << "   Frecuencia g: " << frequencyA5[0] << endl;
	cout << "   Frecuencia p: " << frequencyA5[1] << endl;
	cout << "   Frecuencia gg: " << frequencyA5[2] << endl;
	cout << "- A6-> " << endl;
	cout << "   Frecuencia c: " << frequencyA6[0] << endl;
	cout << "   Frecuencia p: " << frequencyA6[1] << endl;
	cout << "   Frecuencia cc: " << frequencyA6[2] << endl;
	cout << "   Frecuencia i: " << frequencyA6[3] << endl;
	cout << "   Frecuencia j: " << frequencyA6[4] << endl;
	cout << "   Frecuencia k: " << frequencyA6[5] << endl;
	cout << "   Frecuencia m: " << frequencyA6[6] << endl;
	cout << "   Frecuencia r: " << frequencyA6[7] << endl;
	cout << "   Frecuencia q: " << frequencyA6[8] << endl;
	cout << "   Frecuencia w: " << frequencyA6[9] << endl;
	cout << "   Frecuencia x: " << frequencyA6[10] << endl;
	cout << "   Frecuencia e: " << frequencyA6[11] << endl;
	cout << "   Frecuencia aa: " << frequencyA6[12] << endl;
	cout << "   Frecuencia ff: " << frequencyA6[13] << endl;
	cout << "- A7-> " << endl;
	cout << "   Frecuencia v: " << frequencyA7[0] << endl;
	cout << "   Frecuencia h: " << frequencyA7[1] << endl;
	cout << "   Frecuencia bb: " << frequencyA7[2] << endl;
	cout << "   Frecuencia j: " << frequencyA7[3] << endl;
	cout << "   Frecuencia n: " << frequencyA7[4] << endl;
	cout << "   Frecuencia z: " << frequencyA7[5] << endl;
	cout << "   Frecuencia dd: " << frequencyA7[6] << endl;
	cout << "   Frecuencia ff: " << frequencyA7[7] << endl;
	cout << "   Frecuencia o: " << frequencyA7[8] << endl;
	cout << "- A9-> " << endl;
	cout << "   Frecuencia t: " << frequencyA9[0] << endl;
	cout << "   Frecuencia f: " << frequencyA9[1] << endl;
	cout << "- A10-> " << endl;
	cout << "   Frecuencia t: " << frequencyA10[0] << endl;
	cout << "   Frecuencia f: " << frequencyA10[1] << endl;
	cout << "- A12-> " << endl;
	cout << "   Frecuencia t: " << frequencyA12[0] << endl;
	cout << "   Frecuencia f: " << frequencyA12[1] << endl;
	cout << "- A13-> " << endl;
	cout << "   Frecuencia g: " << frequencyA13[0] << endl;
	cout << "   Frecuencia p: " << frequencyA13[1] << endl;
	cout << "   Frecuencia s: " << frequencyA13[2] << endl;
	cout << "-----------------------------------" << endl;
	cout << "Preprocesado finalizado" << endl;
	cout << "-----------------------------------" << endl;
	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Procesando datos..." << endl;
	cout << "-----------------------------------" << endl;
	size = ReadFile(filename);
	cout << "Se cargaron " << dataSet.size() << " datos" << endl;
	cout << "Conjunto de entrenamiento: " << trainingSet.size() << endl;
	cout << " " << TRAINING_SIZE*100 << "%" << endl;
	cout << "Conjunto de prueba: " << testSet.size() << endl;
	cout << " " << TEST_SIZE*100 << "%" << endl;
	cout << "Datos positivos (+): " << positives << endl;
	cout << " " << (positives/(double) SIZE)*100 << "%" << endl;
	cout << "Datos negativos (-): " << negatives << endl;
	cout << " " << (negatives/(double) SIZE)*100 << "%" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Procesado finalizado" << endl;
	cout << "-----------------------------------" << endl << endl;
}

Classifier::~Classifier() {}

void Classifier::Preprocessing(const char *filename) {
	fstream inputFile;
	inputFile.open(filename, ios::in);

	if (inputFile.is_open()) {
		string line = "";
		mean2 = 0;
		mean3 = 0;
		mean8 = 0;
		mean11 = 0;
		mean14 = 0;
		mean15 = 0;
		min2 = INT_MAX;
		min3 = INT_MAX;
		min8 = INT_MAX;
		min11 = INT_MAX;
		min14 = INT_MAX;
		min15 = INT_MAX;
		max2 = INT_MIN;
		max3 = INT_MIN;
		max8 = INT_MIN;
		max11 = INT_MIN;
		max14 = INT_MIN;
		max15 = INT_MIN;

		for (int i=0; i < 3; i++) frequencyA1[i] = 0;
		for (int i=0; i < 4; i++) frequencyA4[i] = 0;
		for (int i=0; i < 3; i++) frequencyA5[i] = 0;
		for (int i=0;i < 14; i++) frequencyA6[i] = 0;
		for (int i=0;i < 9; i++) frequencyA7[i] = 0;
		for (int i=0;i < 2; i++) frequencyA9[i] = 0;
		for (int i=0;i < 2; i++) frequencyA10[i] = 0;
		for (int i=0;i < 2; i++) frequencyA12[i] = 0;
		for (int i=0;i < 3; i++) frequencyA13[i] = 0;

		for (int i=0;i < 3; i++) frequencyA2[i] = 0;
		for (int i=0;i < 3; i++) frequencyA3[i] = 0;
		for (int i=0;i < 3; i++) frequencyA8[i] = 0;
		for (int i=0;i < 3; i++) frequencyA11[i] = 0;
		for (int i=0;i < 3; i++) frequencyA14[i] = 0;
		for (int i=0;i < 3; i++) frequencyA15[i] = 0;

		while (!inputFile.eof()) {
			getline(inputFile, line);
			if (line.length() > 2) UpdateStatistics(line);
		}

		// Considerar valores ausentes
		mean2 = mean2/(SIZE-12);
		mean3 = mean3/SIZE;
		mean8 = mean8/SIZE;
		mean11 = mean11/SIZE;
		mean14 = mean14/(SIZE-13);
		mean15 = mean15/SIZE;

		cout << mean14;
		cout << mean15;

		inputFile.close();
	}
	else {
		cout << "Error: No se pudo procesar el archivo " << filename << endl;
	}
}

int Classifier::ReadFile(const char *filename) {
	fstream inputFile;
	inputFile.open(filename, ios::in);
	positives = 0;
	negatives = 0;

	if (inputFile.is_open()) {
		string line = "";

		while (!inputFile.eof()) {
			getline(inputFile, line);
			if (line.length() > 2) ProcessLine(line);
		}

		random_shuffle(dataSet.begin(),dataSet.end());

		int training = (int) ceil(TRAINING_SIZE*dataSet.size());
		int test = (int) ceil(TEST_SIZE*dataSet.size());

		for (int i=0; i< training; i++) trainingSet.push_back(dataSet[i]);

		for (int i=0; i< test; i++) testSet.push_back(dataSet[i]);

		inputFile.close();
		return dataSet.size();
	}
	else {
		cout << "Error: No se pudo procesar el archivo " << filename << endl;
		return -1;
	}
}

void Classifier::GA() {
	double total;
	double result;
	double sum = 0.0;
	int count = 0;
	int mutated = 0;
	int crossed = 0;
	int index;
	double selectionSize = (1.0 - CROSSOVER_RATE)*POPULATION;
	double crossoverSize = CROSSOVER_RATE*POPULATION;
	double mutationSize = MUTATION_RATE*POPULATION;
	Chromosome child1;
	Chromosome child2;
	vector<Chromosome> children;

	cout << "-----------------------------------" << endl;
	cout << "-----------------------------------" << endl;
	cout << "       ALGORITMO GENETICO          " << endl;
	cout << "-----------------------------------" << endl;

	accuracy = -1;
	best = -1;
	mutated = 0;

	// Inicializacion de la poblacion
	for (int i=0; i< POPULATION; i++) {
		int genes = (rand()%2)+1;
		double probAA = (rand()%100)/100.00;
		double probDC = (rand()%100)/100.00;
		double probMutation = (rand()%100)/100.00;

		hypothesis[i] = RandomCreate(genes);
		total = Fitness(hypothesis[i], trainingSet);
		result = (total/(double) trainingSet.size())*100;
		hypothesis[i].fitness = pow(total,2);
		hypothesis[i].survives = false;
		sum += hypothesis[i].fitness;

		if (probMutation <= MUTATION_RATE) {
			hypothesis[i].mutate = true;
			mutated++;
		}
		else hypothesis[i].mutate = false;

		if (probAA <= AA_RATE) hypothesis[i].aa = true;
		else hypothesis[i].aa = false;

		if (probDC <= DC_RATE) hypothesis[i].dc = true;
		else hypothesis[i].dc = false;

		if (result > accuracy) {
			best = i;
			accuracy = result;
			maxScore = total;
		}
	}

	index = 0;

	while (mutated < mutationSize) {
		int prob = rand()%100;

		if (index >= POPULATION) index = 0;

		if (prob <= RANDOM_RATE) {
			hypothesis[index].mutate = true;
			mutated++;
		}

		index++;
	}

	cout << "Población inicial generada" << endl;
	cout << " " << POPULATION << " individuos aleatorios" << endl;
	cout << " Precisión del mejor cromosoma: " << accuracy << "%" << endl;
	cout << "Realizando proceso evolutivo..." << endl;

	/*
	for (int i=0; i< POPULATION; i++) {
	cout << "Cromosoma: " << i << endl;
	for (int j=0; j < hypothesis[i].rule.size(); j++) {
		cout << hypothesis[i].rule[j] << ", ";
	}

	cout << endl;
	cout << hypothesis[i].rule.size() << " ";
	cout << hypothesis[i].fitness << " ";
	cout << endl;
	}
	*/

	// Condicion de parada (generaciones || precision)
	while (accuracy < THRESHOLD && count < GENERATIONS) {
		// Elitismo
		int survivors = 1;
		crossed = 0;
		hypothesis[best].survives = true;
		hypothesis[best].mutate = false;
		hypothesis[best].aa = false;
		hypothesis[best].dc = false;

		// Seleccion de proxima generacion
		while (survivors < selectionSize) {
			// Torneo
			int option1 = rand()%POPULATION;
			int option2 = rand()%POPULATION;
			int max;
			int min;

			while (hypothesis[option1].survives) option1 = rand()%POPULATION;
			while (hypothesis[option2].survives || option1 == option2) option2 = rand()%POPULATION;


			if (hypothesis[option1].fitness > hypothesis[option2].fitness) {
				max = option1;
				min = option2;
			}
			else {
				max = option2;
				min = option1;
			}

			double chance = rand()%100;

			if (chance > TOURNAMENT_RATE) hypothesis[max].survives = true;
			else hypothesis[min].survives = true;

			/*
			// Rueda de la ruleta
			double chance = 0.0;
			double limit = (double) (rand()%(int) sum);
			index = 0;
			int option = -1;

			while (chance < limit) {
				if (index >= POPULATION) index = 0;
				if (!hypothesis[index].survives) chance += hypothesis[index].fitness/sum;
				if (chance >= limit) option = index;
				index++;
			}

			hypothesis[option].survives = true;
			*/

			survivors++;
		}

		// CrossOver
		while (crossed < crossoverSize) {
			// Torneo
			for (int k=0; k<2; k++) {
				int option1 = rand()%POPULATION;
				int option2 = rand()%POPULATION;
				int max;
				int min;

				while (hypothesis[option1].survives) option1 = rand()%POPULATION;
				while (hypothesis[option2].survives || option1 == option2) option2 = rand()%POPULATION;


				if (hypothesis[option1].fitness > hypothesis[option2].fitness) {
					max = option1;
					min = option2;
				}
				else {
					max = option2;
					min = option1;
				}

				double chance = rand()%100;

				if (chance > TOURNAMENT_RATE) {
					if (k == 0) child1 = hypothesis[max];
					if (k == 1) child2 = hypothesis[max];
				}
				else {
					if (k == 0) child1 = hypothesis[min];
					if (k == 1) child2 = hypothesis[min];
				}
			}

			/*
			// Rueda de la ruleta
			double chance = 0.0;
			double limit = (double) (rand()%(int) sum);
			index = 0;
			int option = -1;

			while (chance < limit) {
				if (index >= POPULATION) index = 0;
				if (!hypothesis[index].survives) chance += hypothesis[index].fitness/sum;
				if (chance >= limit) option = index;
				index++;
			}

			hypothesis[option].survives = true;
			*/



			crossed += 2;
		}


		// Evaluacion
		sum = 0.0;
		mutated = 0;

		for (int i=0; i< POPULATION; i++) {
			// Add Alternative
			if (hypothesis[i].aa) hypothesis[i] = AddAlternative(hypothesis[i]);

			// Drop Condition
			if (hypothesis[i].dc) hypothesis[i] = DropCondition(hypothesis[i]);

			// Mutacion
			if (hypothesis[i].mutate) hypothesis[i] = Mutate(hypothesis[i]);

			double probAA = (rand()%100)/100.00;
			double probDC = (rand()%100)/100.00;
			double probMutation = (rand()%100)/100.00;

			total = Fitness(hypothesis[i], trainingSet);
			result = (total/(double) trainingSet.size())*100;
			hypothesis[i].fitness = pow(total,2);
			hypothesis[i].survives = false;
			sum += hypothesis[i].fitness;

			if (probMutation <= MUTATION_RATE) {
				hypothesis[i].mutate = true;
				mutated++;
			}
			else hypothesis[i].mutate = false;

			if (probAA <= AA_RATE) hypothesis[i].aa = true;
			else hypothesis[i].aa = false;

			if (probDC <= DC_RATE) hypothesis[i].dc = true;
			else hypothesis[i].dc = false;

			if (result > accuracy) {
				best = i;
				accuracy = result;
				maxScore = total;
			}
		}

		index = 0;

		while (mutated < mutationSize) {
			int prob = rand()%100;

			if (index >= POPULATION) index = 0;

			if (prob <= RANDOM_RATE) {
				hypothesis[index].mutate = true;
				mutated++;
			}

			index++;
		}

		count++;
	}

	maxScore = Fitness(hypothesis[best], testSet);
	accuracy = (maxScore/(double) testSet.size())*100;

	cout << "Proceso evolutivo finalizado" << endl;
	cout << " Generaciones: " << GENERATIONS << endl;
	cout << "-----------------------------------" << endl;
	cout << " Precisión de la validación: " << accuracy << "%" << endl;
	cout << " Clasificados correctamente: " << maxScore << "/" << (int) testSet.size() << endl;
	cout << "-----------------------------------" << endl;
	cout << "Algoritmo finalizado" << endl;
	cout << "-----------------------------------" << endl;
}

double Classifier::Fitness(Chromosome individual, vector<Chromosome> set) {
	double total = 0.0;

	for (int k=0; k < (int) set.size(); k++) {
		bool correct;
		int size = individual.rule.size();
		int genes = 0;

		while (genes < size) {
			int i = 0;
			bool a1 = false;
			bool a2 = false;
			bool a3 = false;
			bool a4 = false;
			bool a5 = false;
			bool a6 = false;
			bool a7 = false;
			bool a8 = false;
			bool a9 = false;
			bool a10 = false;
			bool a11 = false;
			bool a12 = false;
			bool a13 = false;
			bool a14 = false;
			bool a15 = false;
			bool result = false;

			while (i < (ATTRIBUTES + 1)) {
				if (i < ATTRIBUTES) {
					if (i == 0) {
						bool dontCare = true;

						for (int j=0; j < 2; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a1 = true;
						}
						else {
							for (int j=0; j < 2; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a1 = true;
							}
						}

						if (!a1) i = ATTRIBUTES + 1;
					}

					// A2: Continuo
					if (i == 1) {
						bool dontCare = true;

						for (int j=0; j < 3; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a2 = true;
						}
						else {
							for (int j=2; j < 5; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a2 = true;
							}
						}

						if (!a2) i = ATTRIBUTES + 1;
					}

					// A3: Continuo
					if (i == 2) {
						bool dontCare = true;

						for (int j=0; j < 3; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a3 = true;
						}
						else {
							for (int j=5; j < 8; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a3 = true;
							}
						}

						if (!a3) i = ATTRIBUTES + 1;
					}

					// A4: u, y, l, t
					if (i == 3) {
						bool dontCare = true;

						for (int j=0; j < 4; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a4 = true;
						}
						else {
							for (int j=8; j < 12; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a4 = true;
							}
						}

						if (!a4) i = ATTRIBUTES + 1;
					}

					// A5: g, p, gg
					if (i == 4) {
						bool dontCare = true;

						for (int j=0; j < 3; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a5 = true;
						}
						else {
							for (int j=12; j < 15; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a5 = true;
							}
						}

						if (!a5) i = ATTRIBUTES + 1;
					}

					// A6: c, d, cc, i, j, k, m, r, q, w, x, e, aa, ff
					if (i == 5) {
						bool dontCare = true;

						for (int j=0; j < 14; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a6 = true;
						}
						else {
							for (int j=15; j < 29; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a6 = true;
							}
						}

						if (!a6) i = ATTRIBUTES + 1;
					}

					// A7: v, h, bb, j, n, z, dd, ff, o
					if (i == 6) {
						bool dontCare = true;

						for (int j=0; j < 9; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a7 = true;
						}
						else {
							for (int j=29; j < 38; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a7 = true;
							}
						}

						if (!a7) i = ATTRIBUTES + 1;
					}

					// A8: Continuo
					if (i == 7) {
						bool dontCare = true;

						for (int j=0; j < 3; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a8 = true;
						}
						else {
							for (int j=38; j < 41; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a8 = true;
							}
						}

						if (!a8) i = ATTRIBUTES + 1;
					}

					// A9: t, f
					if (i == 8) {
						bool dontCare = true;

						for (int j=0; j < 2; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a9 = true;
						}
						else {
							for (int j=41; j < 43; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a9 = true;
							}
						}

						if (!a9) i = ATTRIBUTES + 1;
					}

					// A10: t, f
					if (i == 9) {
						bool dontCare = true;

						for (int j=0; j < 2; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a10 = true;
						}
						else {
							for (int j=43; j < 45; j++) {
								if ((individual.rule[i+genes] == 1) && (set[k].rule[i] == 1)) a10 = true;
							}
						}

						if (!a10) i = ATTRIBUTES + 1;
					}

					// A11: Continuo
					if (i == 10) {
						bool dontCare = true;

						for (int j=0; j < 3; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a11 = true;
						}
						else {
							for (int j=45; j < 48; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a11 = true;
							}
						}

						if (!a11) i = ATTRIBUTES + 1;
					}

					// A12: t, f
					if (i == 11) {
						bool dontCare = true;

						for (int j=0; j < 2; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a12 = true;
						}
						else {
							for (int j=48; j < 50; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a12 = true;
							}
						}

						if (!a12) i = ATTRIBUTES + 1;
					}

					// A13: g, p, s
					if (i == 12) {
						bool dontCare = true;

						for (int j=0; j < 3; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a13 = true;
						}
						else {
							for (int j=50; j < 53; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a13 = true;
							}
						}

						if (!a13) i = ATTRIBUTES + 1;
					}

					// A14: Continuo
					if (i == 13) {
						bool dontCare = true;

						for (int j=0; j < 3; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a14 = true;
						}
						else {
							for (int j=53; j < 56; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a14 = true;
							}
						}

						if (!a14) i = ATTRIBUTES + 1;
					}

					// A15: Continuo
					if (i == 14) {
						bool dontCare = true;

						for (int j=0; j < 3; j++) {
							if (individual.rule[j+genes] == 0) dontCare = false;
						}

						if (dontCare) {
							a15 = true;
						}
						else {
							for (int j=56; j < 59; j++) {
								if ((individual.rule[j+genes] == 1) && (set[k].rule[j] == 1)) a15 = true;
							}
						}

						if (!a15) i = ATTRIBUTES + 1;
					}
				}
				else {
					if ((individual.rule[59+genes] == 1) && (set[k].rule[59] == 1)) result = true;
					if ((individual.rule[59+genes] == 0) && (set[k].rule[59] == 0)) result = true;
				}

				i++;
			}

			correct = a1 && a2 && a3 && a4 && a5 && a6 && a7 && a8 && a9
					&& a10 && a11 && a12 && a13 && a14 && a15 && result;

			if (correct) genes += GENE_SIZE;
			else genes = size;
		}

		if (correct) total++;
	}

	if (total == 0.0) total = 1.0;

	return total;
}

vector<Chromosome> Classifier::CrossOver(Chromosome father1, Chromosome father2) {
	vector<Chromosome> children;
	Chromosome child1;
	Chromosome child2;
	int distance1;
	int distance2;
	int count = -1;
	int genes;
	int point1;
	int point2;
	int point3;
	int point4;
	int gen1;
	int gen2;
	int aux;
	int x;
	int y;

	if (father1.rule.size() > father2.rule.size()) {
		point1 = rand()%father2.rule.size();
		point2 = rand()%father2.rule.size();

		while (point1 == point2) point2 = rand()%father2.rule.size();

		genes = father2.rule.size()/GENE_SIZE;
	}
	else {
		point1 = rand()%father1.rule.size();
		point2 = rand()%father1.rule.size();

		while (point1 == point2) point2 = rand()%father1.rule.size();

		genes = father2.rule.size()/GENE_SIZE;
	}

	gen1 = rand()%genes;
	gen2 = rand()%genes;

	if (point1 > point2) {
		aux = point1;
		point1 = point2;
		point2 = aux;
	}

	if (gen1 > gen2) {
		aux = gen1;
		gen1 = gen2;
		gen2 = aux;
	}

	x = point1;
	y = point2;

	while (x >= 0) {
		x -= GENE_SIZE;
		count++;
	}

	distance1 = point1 - count*GENE_SIZE;

	count = -1;

	while (y >= 0) {
		y -= GENE_SIZE;
		count++;
	}

	distance2 = point2 - count*GENE_SIZE;

	point3 = gen1*GENE_SIZE+distance1;
	point4 = gen2*GENE_SIZE+distance2;

	if (gen1 == 0 && gen2 == 0 && point3 > point4) {
		aux = point3;
		point3 = point4;
		point4 = aux;
	}

	for (int i=0; i < point1; ++i) child1.rule.push_back(father1.rule[i]);
	for (int i=point3; i < point4; ++i) child1.rule.push_back(father2.rule[i]);
	for (int i=point2; i < (int) father1.rule.size(); ++i) child1.rule.push_back(father1.rule[i]);

	for (int i=0; i < point3; ++i) child2.rule.push_back(father2.rule[i]);
	for (int i=point1; i < point2; ++i) child2.rule.push_back(father1.rule[i]);
	for (int i=point4; i < (int) father2.rule.size(); ++i) child2.rule.push_back(father2.rule[i]);

	children.push_back(child1);
	children.push_back(child2);

	return children;
}

Chromosome Classifier::Mutate(Chromosome individual) {
	int attribute;
	int index = rand()%GENE_SIZE;
	int gene = rand()%(individual.rule.size()/GENE_SIZE);

	if (individual.rule[gene*GENE_SIZE+index] == 0) individual.rule[gene*GENE_SIZE+index] = 1;
	else if (individual.rule[gene*GENE_SIZE+index] == 1) {
		if (index >= 0 && index < 2) attribute = 0;
		if (index >= 2 && index < 5) attribute = 1;
		if (index >= 5 && index < 8) attribute = 2;
		if (index >= 8 && index < 12) attribute = 3;
		if (index >= 12 && index < 15) attribute = 4;
		if (index >= 15 && index < 29) attribute = 5;
		if (index >= 29 && index < 38) attribute = 6;
		if (index >= 38 && index < 41) attribute = 7;
		if (index >= 41 && index < 43) attribute = 8;
		if (index >= 43 && index < 45) attribute = 9;
		if (index >= 45 && index < 48) attribute = 10;
		if (index >= 48 && index < 50) attribute = 11;
		if (index >= 50 && index < 53) attribute = 12;
		if (index >= 53 && index < 56) attribute = 13;
		if (index >= 56 && index < 59) attribute = 14;

		if (Valid(individual, attribute, gene*GENE_SIZE+index)) individual.rule[gene*GENE_SIZE+index] = 0;
	}

	return individual;
}

Chromosome Classifier::AddAlternative(Chromosome individual) {
	int index = rand()%ATTRIBUTES;
	int gene = rand()%(individual.rule.size()/GENE_SIZE);

	// A1: b, a
	if (index == 0) {
		int alternative = rand()%2;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A2: Continuo
	if (index == 1) {
		int alternative = (rand()%3)+2;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A3: Continuo
	if (index == 2) {
		int alternative = (rand()%3)+5;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A4: u, y, l, t
	if (index == 3) {
		int alternative = (rand()%4)+8;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A5: g, p, gg
	if (index == 4) {
		int alternative = (rand()%3)+12;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A6: c, d, cc, i, j, k, m, r, q, w, x, e, aa, ff
	if (index == 5) {
		int alternative = (rand()%14)+15;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A7: v, h, bb, j, n, z, dd, ff, o
	if (index == 6) {
		int alternative = (rand()%9)+29;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A8: Continuo
	if (index == 7) {
		int alternative = (rand()%3)+38;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A9: t, f
	if (index == 8) {
		int alternative = (rand()%2)+41;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A10: t, f
	if (index == 9) {
		int alternative = (rand()%2)+43;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A11: Continuo
	if (index == 10) {
		int alternative = (rand()%3)+45;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A12: t, f
	if (index == 11) {
		int alternative = (rand()%2)+48;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A13: g, p, s
	if (index == 12) {
		int alternative = (rand()%3)+50;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A14: Continuo
	if (index == 13) {
		int alternative = (rand()%3)+53;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	// A15: Continuo
	if (index == 14) {
		int alternative = (rand()%3)+56;
		individual.rule[gene*GENE_SIZE+alternative] = 1;
	}

	return individual;
}

Chromosome Classifier::DropCondition(Chromosome individual) {
	int index = rand()%ATTRIBUTES;
	int gene = rand()%(individual.rule.size()/GENE_SIZE);

	// A1: b, a
	if (index == 0) {
		for (int i=0; i < 2; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A2: Continuo
	if (index == 1) {
		for (int i=2; i < 5; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A3: Continuo
	if (index == 2) {
		for (int i=5; i < 8; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A4: u, y, l, t
	if (index == 3) {
		for (int i=8; i < 12; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A5: g, p, gg
	if (index == 4) {
		for (int i=12; i < 15; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A6: c, d, cc, i, j, k, m, r, q, w, x, e, aa, ff
	if (index == 5) {
		for (int i=15; i < 29; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A7: v, h, bb, j, n, z, dd, ff, o
	if (index == 6) {
		for (int i=29; i < 38; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A8: Continuo
	if (index == 7) {
		for (int i=38; i < 41; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A9: t, f
	if (index == 8) {
		for (int i=41; i < 43; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A10: t, f
	if (index == 9) {
		for (int i=43; i < 45; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A11: Continuo
	if (index == 10) {
		for (int i=45; i < 48; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A12: t, f
	if (index == 11) {
		for (int i=48; i < 50; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A13: g, p, s
	if (index == 12) {
		for (int i=50; i < 53; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A14: Continuo
	if (index == 13) {
		for (int i=53; i < 56; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	// A15: Continuo
	if (index == 14) {
		for (int i=56; i < 59; i++) individual.rule[gene*GENE_SIZE+i] = 1;
	}

	return individual;
}

Chromosome Classifier::RandomCreate(int genes) {
    Chromosome individual;
	int chance = rand()%100;

	if (chance <= RANDOM_RATE || genes <= 0) {
		int index = rand()%SIZE;
		return dataSet[index];
	}

	while (genes > 0) {
		int i = 0;

		while (i < (ATTRIBUTES + 1)) {
			if (i < ATTRIBUTES) {
				// A1: b, a
				if (i == 0) {
					bool added = false;

					for (int i=0; i < 2; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=0; i < 2; i++) individual.rule[i] = 1;
					}
				}

				// A2: Continuo
				if (i == 1) {
					bool added = false;

					for (int i=0; i < 3; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=2; i < 5; i++) individual.rule[i] = 1;
					}
				}

				// A3: Continuo
				if (i == 2) {
					bool added = false;

					for (int i=0; i < 3; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=5; i < 8; i++) individual.rule[i] = 1;
					}
				}

				// A4: u, y, l, t
				if (i == 3) {
					bool added = false;

					for (int i=0; i < 4; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=8; i < 12; i++) individual.rule[i] = 1;
					}
				}

				// A5: g, p, gg
				if (i == 4) {
					bool added = false;

					for (int i=0; i < 3; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=12; i < 15; i++) individual.rule[i] = 1;
					}
				}

				// A6: c, d, cc, i, j, k, m, r, q, w, x, e, aa, ff
				if (i == 5) {
					bool added = false;

					for (int i=0; i < 14; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=15; i < 29; i++) individual.rule[i] = 1;
					}
				}

				// A7: v, h, bb, j, n, z, dd, ff, o
				if (i == 6) {
					bool added = false;

					for (int i=0; i < 9; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=29; i < 38; i++) individual.rule[i] = 1;
					}
				}

				// A8: Continuo
				if (i == 7) {
					bool added = false;

					for (int i=0; i < 3; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=38; i < 41; i++) individual.rule[i] = 1;
					}
				}

				// A9, A10, A12: t, f
				if (i == 8 || i == 9 || i == 11) {
					int p = rand()%100;
					if (p >= 50) {
						individual.rule.push_back(1);
						individual.rule.push_back(0);
					}
					else {
						individual.rule.push_back(0);
						individual.rule.push_back(1);
					}
				}

				// A11: Continuo
				if (i == 10) {
					bool added = false;

					for (int i=0; i < 3; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=45; i < 48; i++) individual.rule[i] = 1;
					}
				}

				// A13: g, p, s
				if (i == 12) {
					bool added = false;

					for (int i=0; i < 3; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=50; i < 53; i++) individual.rule[i] = 1;
					}
				}

				// A14: Continuo
				if (i == 13) {
					bool added = false;

					for (int i=0; i < 3; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=53; i < 56; i++) individual.rule[i] = 1;
					}
				}

				// A15: Continuo
				if (i == 14) {
					bool added = false;

					for (int i=0; i < 3; i++) {
						int p = rand()%100;
						if (p >= 50) {
							added = true;
							individual.rule.push_back(1);
						}
						else {
							individual.rule.push_back(0);
						}
					}

					if (!added) {
						for (int i=56; i < 59; i++) individual.rule[i] = 1;
					}
				}
			}
			else {
				int p = rand()%100;

				if (p >= 50) individual.rule.push_back(1);
				else individual.rule.push_back(0);
			}

			i++;
		}

		genes--;
	}

	individual.fitness = 0;
	individual.survives = false;
	individual.mutate = false;
	individual.aa = false;
	individual.dc = false;
	return individual;
}

bool Classifier::Valid(Chromosome individual, int index, int pos) {
	individual.rule[pos] = 0;

	// A1: b, a
	if (index == 0) {
		for (int i=0; i < 2; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A2: Continuo
	if (index == 1) {
		for (int i=2; i < 5; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A3: Continuo
	if (index == 2) {
		for (int i=5; i < 8; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A4: u, y, l, t
	if (index == 3) {
		for (int i=8; i < 12; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A5: g, p, gg
	if (index == 4) {
		for (int i=12; i < 15; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A6: c, d, cc, i, j, k, m, r, q, w, x, e, aa, ff
	if (index == 5) {
		for (int i=15; i < 29; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A7: v, h, bb, j, n, z, dd, ff, o
	if (index == 6) {
		for (int i=29; i < 38; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A8: Continuo
	if (index == 7) {
		for (int i=38; i < 41; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A9: t, f
	if (index == 8) {
		for (int i=41; i < 43; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A10: t, f
	if (index == 9) {
		for (int i=43; i < 45; i++) if (individual.rule[i] == 1) return true;
	}

	// A11: Continuo
	if (index == 10) {
		for (int i=45; i < 48; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A12: t, f
	if (index == 11) {
		for (int i=48; i < 50; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A13: g, p, s
	if (index == 12) {
		for (int i=50; i < 53; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A14: Continuo
	if (index == 13) {
		for (int i=53; i < 56; i++)
			if (individual.rule[i] == 1) return true;
	}

	// A15: Continuo
	if (index == 14) {
		for (int i=56; i < 59; i++)
			if (individual.rule[i] == 1) return true;
	}

	return false;
}

void Classifier::UpdateStatistics(string &line) {
	char* cstr = new char[line.size()+1];
	char* t;
	int i = 0;

	strcpy(cstr, line.c_str());
	t = strtok(cstr,",");

	while (t != NULL && i < ATTRIBUTES) {
		// A1: b, a
		if (i == 0) {
			if (strcmp(t,"b") == 0) frequencyA1[0]++;
			if (strcmp(t,"a") == 0) frequencyA1[1]++;
		}

		// A2: Continuo
		if (i == 1) {
			// Missing value
			if (strcmp(t,"?") != 0) {
				double value = atof(t);
				mean2 += value;

				if (value > max2) max2 = value;
				if (value < min2) min2 = value;

				if ((value > 13) && (value < 30)) frequencyA2[0]++;
				if ((value >= 30) && (value < 50)) frequencyA2[1]++;
				if ((value >= 50) && (value < 81)) frequencyA2[2]++;
			}
		}

		// A3: Continuo
		if (i == 2) {
			double value = atof(t);
			mean3 += value;

			if (value > max3) max3 = value;
			if (value < min3) min3 = value;

			if ((value >= 0) && (value < 5)) frequencyA3[0]++;
			if ((value >= 5) && (value < 15)) frequencyA3[1]++;
			if ((value >= 15) && (value < 29)) frequencyA3[2]++;
		}

		// A4: u, y, l, t
		if (i == 3) {
			if (strcmp(t,"u") == 0) frequencyA4[0]++;
			if (strcmp(t,"y") == 0) frequencyA4[1]++;
			if (strcmp(t,"l") == 0) frequencyA4[2]++;
			if (strcmp(t,"t") == 0) frequencyA4[3]++;
		}

		// A5: g, p, gg
		if (i == 4) {
			if (strcmp(t,"g") == 0) frequencyA5[0]++;
			if (strcmp(t,"p") == 0) frequencyA5[1]++;
			if (strcmp(t,"gg") == 0) frequencyA5[2]++;
		}

		// A6: c, d, cc, i, j, k, m, r, q, w, x, e, aa, ff
		if (i == 5) {
			if (strcmp(t,"c") == 0) frequencyA6[0]++;
			if (strcmp(t,"d") == 0) frequencyA6[1]++;
			if (strcmp(t,"cc") == 0) frequencyA6[2]++;
			if (strcmp(t,"i") == 0) frequencyA6[3]++;
			if (strcmp(t,"j") == 0) frequencyA6[4]++;
			if (strcmp(t,"k") == 0) frequencyA6[5]++;
			if (strcmp(t,"m") == 0) frequencyA6[6]++;
			if (strcmp(t,"r") == 0) frequencyA6[7]++;
			if (strcmp(t,"q") == 0) frequencyA6[8]++;
			if (strcmp(t,"w") == 0) frequencyA6[9]++;
			if (strcmp(t,"x") == 0) frequencyA6[10]++;
			if (strcmp(t,"e") == 0) frequencyA6[11]++;
			if (strcmp(t,"aa") == 0) frequencyA6[12]++;
			if (strcmp(t,"ff") == 0) frequencyA6[13]++;
		}

		// A7: v, h, bb, j, n, z, dd, ff, o
		if (i == 6) {
			if (strcmp(t,"v") == 0) frequencyA7[0]++;
			if (strcmp(t,"h") == 0) frequencyA7[1]++;
			if (strcmp(t,"bb") == 0) frequencyA7[2]++;
			if (strcmp(t,"j") == 0) frequencyA7[3]++;
			if (strcmp(t,"n") == 0) frequencyA7[4]++;
			if (strcmp(t,"z") == 0) frequencyA7[5]++;
			if (strcmp(t,"dd") == 0) frequencyA7[6]++;
			if (strcmp(t,"ff") == 0) frequencyA7[7]++;
			if (strcmp(t,"o") == 0) frequencyA7[8]++;
		}

		// A8: Continuo
		if (i == 7) {
			double value = atof(t);
			mean8 += value;

			if (value > max8) max8 = value;
			if (value < min8) min8 = value;

			if ((value >= 0) && (value < 5)) frequencyA8[0]++;
			if ((value >= 5) && (value < 15)) frequencyA8[1]++;
			if ((value >= 15) && (value < 29)) frequencyA8[2]++;
		}

		// A9: t, f
		if (i == 8) {
			if (strcmp(t,"t") == 0) frequencyA9[0]++;
			if (strcmp(t,"f") == 0) frequencyA9[1]++;
		}

		// A10: t, f
		if (i == 9) {
			if (strcmp(t,"t") == 0) frequencyA10[0]++;
			if (strcmp(t,"f") == 0) frequencyA10[1]++;
		}

		// A11: Continuo
		if (i == 10) {
			double value = atof(t);
			mean11 += value;

			if (value > max11) max11 = value;
			if (value < min11) min11 = value;

			if ((value > 0) && (value < 5)) frequencyA11[0]++;
			if ((value >= 5) && (value < 20)) frequencyA11[1]++;
			if ((value >= 20) && (value < 68)) frequencyA11[2]++;
		}

		// A12: t, f
		if (i == 11) {
			if (strcmp(t,"t") == 0) frequencyA12[0]++;
			if (strcmp(t,"f") == 0) frequencyA12[1]++;
		}


		// A13: g, p, s
		if (i == 12) {
			if (strcmp(t,"g") == 0) frequencyA13[0]++;
			if (strcmp(t,"p") == 0) frequencyA13[1]++;
			if (strcmp(t,"s") == 0) frequencyA13[2]++;
		}

		// A14: Continuo
		if (i == 13) {
			if (strcmp(t,"?") != 0) {
				double value = atof(t);
				mean14 += value;

				if (value > max14) max14 = value;
				if (value < min14) min14 = value;

				if ((value >= 0) && (value < 200)) frequencyA14[0]++;
				if ((value >= 200) && (value < 500)) frequencyA14[1]++;
				if ((value >= 500) && (value < 2001)) frequencyA14[2]++;
			}
		}

		// A15: Continuo
		if (i == 14) {
			double value = atof(t);

			mean15 += value;

			if (value > max15) max15 = value;
			if (value < min15) min15 = value;

			if ((value >= 0) && (value < 1000)) frequencyA15[0]++;
			if ((value >= 1000) && (value < 5000)) frequencyA15[1]++;
			if ((value >= 5000) && (value < 100001)) frequencyA15[2]++;
		}

		t = strtok(NULL,",");
		i++;
	}
}

void Classifier::ProcessLine(string &line) {
    Chromosome individual;
	char* cstr = new char[line.size()+1];
	char* t;
	int i = 0;

	strcpy(cstr, line.c_str());
	t = strtok(cstr,",");

	while (t != NULL && i < (ATTRIBUTES + 1)) {
		if (i < ATTRIBUTES) {
			// A1: b, a
			if (i == 0) {
				// [1,0]
				if (strcmp(t,"b") == 0) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				else if (strcmp(t,"a") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
				// Missing value
				else {
					int max = MaxFrequency(1);
					if (max == 0) {
						individual.rule.push_back(1);
						individual.rule.push_back(0);
					}
					else {
						individual.rule.push_back(0);
						individual.rule.push_back(1);
					}
				}
			}

			// A2: Continuo
			if (i == 1) {
				if (strcmp(t,"?") != 0) {
					double value = atof(t);

					if ((value > 13) && (value < 30)) {
						individual.rule.push_back(1);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
					}
					else if ((value >= 30) && (value < 50)) {
						individual.rule.push_back(0);
						individual.rule.push_back(1);
						individual.rule.push_back(0);
					}
					if ((value >= 50) && (value < 81)) {
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(1);
					}
				}
				// Missing value, media 31.56
				else {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
			}

			// A3: Continuo
			if (i == 2) {
				double value = atof(t);

				if ((value >= 0) && (value < 5)) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				else if ((value >= 5) && (value < 15)) {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				else if ((value >= 15) && (value < 29)) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
			}

			// A4: u, y, l, t
			if (i == 3) {
				// [1,0,0,0]
				if (strcmp(t,"u") == 0) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				// [0,1,0,0]
				else if (strcmp(t,"y") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				// [0,0,1,0]
				else if (strcmp(t,"l") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				// [0,0,0,1]
				else if (strcmp(t,"t") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
				// Missing values
				else {
					int max = MaxFrequency(4);
					if (max == 0) {
						individual.rule.push_back(1);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
					}
					else if (max == 1) {
						individual.rule.push_back(0);
						individual.rule.push_back(1);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
					}
					else if (max == 2) {
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(1);
						individual.rule.push_back(0);
					}
					else {
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(1);
					}
				}
			}

			// A5: g, p, gg
			if (i == 4) {
				// [1,0,0]
				if (strcmp(t,"g") == 0) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				// [0,1,0]
				else if (strcmp(t,"p") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				// [0,0,1]
				else if (strcmp(t,"gg") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
				// Missing values
				else {
					int max = MaxFrequency(5);
					if (max == 0) {
						individual.rule.push_back(1);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
					}
					else if (max == 1) {
						individual.rule.push_back(0);
						individual.rule.push_back(1);
						individual.rule.push_back(0);
					}
					else {
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(1);
					}
				}
			}

			// A6: c, d, cc, i, j, k, m, r, q, w, x, e, aa, ff
			if (i == 5) {
				// [1,0,0,0,0,0,0,0,0,0,0,0,0,0]
				if (strcmp(t,"c") == 0) {
					individual.rule.push_back(1);
					for (int k=0; k < 13; k++) individual.rule.push_back(0);
				}
				// [0,1,0,0,0,0,0,0,0,0,0,0,0,0]
				else if (strcmp(t,"d") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 12; k++) individual.rule.push_back(0);
				}
				// [0,0,1,0,0,0,0,0,0,0,0,0,0,0]
				else if (strcmp(t,"cc") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 11; k++) individual.rule.push_back(0);
				}
				// [0,0,0,1,0,0,0,0,0,0,0,0,0,0]
				else if (strcmp(t,"i") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 10; k++) individual.rule.push_back(0);
				}
				// [0,0,0,0,1,0,0,0,0,0,0,0,0,0]
				else if (strcmp(t,"j") == 0) {
					for (int k=0; k < 4; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 9; k++) individual.rule.push_back(0);
				}
				// [0,0,0,0,0,1,0,0,0,0,0,0,0,0]
				else if (strcmp(t,"k") == 0) {
					for (int k=0; k < 5; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 8; k++) individual.rule.push_back(0);
				}
				// [0,0,0,0,0,0,1,0,0,0,0,0,0,0]
				else if (strcmp(t,"m") == 0) {
					for (int k=0; k < 6; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 7; k++) individual.rule.push_back(0);
				}
				// [0,0,0,0,0,0,0,1,0,0,0,0,0,0]
				else if (strcmp(t,"r") == 0) {
					for (int k=0; k < 7; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 6; k++) individual.rule.push_back(0);
				}
				// [0,0,0,0,0,0,0,0,1,0,0,0,0,0]
				else if (strcmp(t,"q") == 0) {
					for (int k=0; k < 8; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 5; k++) individual.rule.push_back(0);
				}
				// [0,0,0,0,0,0,0,0,0,1,0,0,0,0]
				else if (strcmp(t,"w") == 0) {
					for (int k=0; k < 9; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 4; k++) individual.rule.push_back(0);
				}
				// [0,0,0,0,0,0,0,0,0,0,1,0,0,0]
				else if (strcmp(t,"x") == 0) {
					for (int k=0; k < 10; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				// [0,0,0,0,0,0,0,0,0,0,0,1,0,0]
				else if (strcmp(t,"e") == 0) {
					for (int k=0; k < 11; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				// [0,0,0,0,1,0,0,0,0,0,0,0,0,0]
				else if (strcmp(t,"aa") == 0) {
					for (int k=0; k < 12; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				// [0,0,0,0,0,0,0,0,0,0,0,0,0,1]
				else if (strcmp(t,"ff") == 0) {
					for (int k=0; k < 13; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
				// Missing values
				else {
					int max = MaxFrequency(6);
					if (max == 0) {
						individual.rule.push_back(1);
						for (int k=0; k < 13; k++) individual.rule.push_back(0);
					}
					else if (max == 1) {
						individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 12; k++) individual.rule.push_back(0);
					}
					else if (max == 2) {
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 11; k++) individual.rule.push_back(0);
					}
					else if (max == 3) {
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 10; k++) individual.rule.push_back(0);
					}
					else if (max == 4) {
						for (int k=0; k < 4; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 9; k++) individual.rule.push_back(0);
					}
					else if (max == 5) {
						for (int k=0; k < 5; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 8; k++) individual.rule.push_back(0);
					}
					else if (max == 6) {
						for (int k=0; k < 6; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 7; k++) individual.rule.push_back(0);
					}
					else if (max == 7) {
						for (int k=0; k < 7; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 6; k++) individual.rule.push_back(0);
					}
					else if (max == 8) {
						for (int k=0; k < 8; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 5; k++) individual.rule.push_back(0);
					}
					else if (max == 9) {
						for (int k=0; k < 9; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 4; k++) individual.rule.push_back(0);
					}
					else if (max == 10) {
						for (int k=0; k < 10; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
					}
					else if (max == 11) {
						for (int k=0; k < 11; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
					}
					else if (max == 12) {
						for (int k=0; k < 12; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						individual.rule.push_back(0);
					}
					else {
						for (int k=0; k < 13; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
					}
				}
			}

			// A7: v, h, bb, j, n, z, dd, ff, o
			if (i == 6) {
				// [1,0,0,0,0,0,0,0,0]
				if (strcmp(t,"v") == 0) {
					individual.rule.push_back(1);
					for (int k=0; k < 8; k++) individual.rule.push_back(0);
				}
				// [0,1,0,0,0,0,0,0,0]
				else if (strcmp(t,"h") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 7; k++) individual.rule.push_back(0);
				}
				// [0,0,1,0,0,0,0,0,0]
				else if (strcmp(t,"bb") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 6; k++) individual.rule.push_back(0);
				}
				// [0,0,0,1,0,0,0,0,0]
				else if (strcmp(t,"j") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 5; k++) individual.rule.push_back(0);
				}
				// [0,0,0,0,1,0,0,0,0]
				else if (strcmp(t,"n") == 0) {
					for (int k=0; k < 4; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 4; k++) individual.rule.push_back(0);
				}
				// [0,0,0,0,0,1,0,0,0]
				else if (strcmp(t,"z") == 0) {
					for (int k=0; k < 5; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					for (int k=0; k < 3; k++) individual.rule.push_back(0);
				}
				// [0,0,0,0,0,0,1,0,0]
				else if (strcmp(t,"dd") == 0) {
					for (int k=0; k < 6; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				// [0,0,0,0,0,0,0,1,0]
				else if (strcmp(t,"ff") == 0) {
					for (int k=0; k < 7; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				// [0,0,0,0,0,0,0,0,1]
				else if (strcmp(t,"o") == 0) {
					for (int k=0; k < 8; k++) individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
				// Missing values
				else {
					int max = MaxFrequency(7);
					if (max == 0) {
						individual.rule.push_back(1);
						for (int k=0; k < 8; k++) individual.rule.push_back(0);
					}
					else if (max == 1) {
						individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 7; k++) individual.rule.push_back(0);
					}
					else if (max == 2) {
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 6; k++) individual.rule.push_back(0);
					}
					else if (max == 3) {
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 5; k++) individual.rule.push_back(0);
					}
					else if (max == 4) {
						for (int k=0; k < 4; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 4; k++) individual.rule.push_back(0);
					}
					else if (max == 5) {
						for (int k=0; k < 5; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						for (int k=0; k < 3; k++) individual.rule.push_back(0);
					}
					else if (max == 6) {
						for (int k=0; k < 6; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						individual.rule.push_back(0);
						individual.rule.push_back(0);
					}
					else if (max == 7) {
						for (int k=0; k < 7; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
						individual.rule.push_back(0);
					}
					else {
						for (int k=0; k < 8; k++) individual.rule.push_back(0);
						individual.rule.push_back(1);
					}
				}
			}

			// A8: Continuo
			if (i == 7) {
				double value = atof(t);

				if ((value >= 0) && (value < 5)) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				else if ((value >= 5) && (value < 15)) {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				else if ((value >= 15) && (value < 29)) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
			}

			// A9: t, f
			if (i == 8) {
				// [1,0]
				if (strcmp(t,"t") == 0) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				else {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
			}

			// A10: t, f
			if (i == 9) {
				// [1,0]
				if (strcmp(t,"t") == 0) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				else {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
			}

			// A11: Continuo
			if (i == 10) {
				double value = atof(t);

				if ((value >= 0) && (value < 5)) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				else if ((value >= 5) && (value < 20)) {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				else if ((value >= 20) && (value < 68)) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
			}

			// A12: t, f
			if (i == 11) {
				// [1,0]
				if (strcmp(t,"t") == 0) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				else {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
			}


			// A13: g, p, s
			if (i == 12) {
				// [1,0,0]
				if (strcmp(t,"g") == 0) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				// [0,1,0]
				else if (strcmp(t,"p") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				// [0,0,1]
				else if (strcmp(t,"s") == 0) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
			}

			// A14: Continuo
			if (i == 13) {
				double value = atof(t);

				if ((value >= 0) && (value < 200)) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				else if ((value >= 200) && (value < 500)) {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				else if ((value >= 500) && (value < 2001)) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
			}

			// A15: Continuo
			if (i == 14) {
				double value = atof(t);

				if ((value >= 0) && (value < 1000)) {
					individual.rule.push_back(1);
					individual.rule.push_back(0);
					individual.rule.push_back(0);
				}
				else if ((value >= 1000) && (value < 5000)) {
					individual.rule.push_back(0);
					individual.rule.push_back(1);
					individual.rule.push_back(0);
				}
				else if ((value >= 5000) && (value < 100001)) {
					individual.rule.push_back(0);
					individual.rule.push_back(0);
					individual.rule.push_back(1);
				}
			}
		}
		else {
			if (strcmp(t,"+") == 0) {
				individual.rule.push_back(1);
				positives++;
			}
			else {
				individual.rule.push_back(0);
				negatives++;
			}
		}

		t = strtok(NULL,",");
		i++;
	}

	/*
	cout << "Cromosoma: ";
	for (int i=0; i < individual.rule.size(); i++) {
		cout << individual.rule[i] << ", ";
	}

	cout << endl;
	cout << individual.rule.size() << " ";
	cout << endl;
	*/

	dataSet.push_back(individual);
}

int Classifier::MaxFrequency(int index) {
	if (index == 1) {
		if (frequencyA1[0] > frequencyA1[1]) return 0;
		if (frequencyA1[0] <= frequencyA1[1]) return 1;
		return -1;
	}
	else if (index == 2) {
		int best = max(frequencyA2[0],frequencyA2[1]);
		best = max(best, frequencyA2[2]);

		if (best == frequencyA2[0]) return 0;
		if (best == frequencyA2[1]) return 1;
		if (best == frequencyA2[2]) return 2;
		return -1;
	}
	else if (index == 3) {
		int best = max(frequencyA3[0],frequencyA3[1]);
		best = max(best, frequencyA3[2]);

		if (best == frequencyA3[0]) return 0;
		if (best == frequencyA3[1]) return 1;
		if (best == frequencyA3[2]) return 2;
		return -1;
	}
	else if (index == 4) {
		int best = max(frequencyA4[0],frequencyA4[1]);
		best = max(best, frequencyA4[2]);
		best = max(best, frequencyA4[3]);

		if (best == frequencyA4[0]) return 0;
		if (best == frequencyA4[1]) return 1;
		if (best == frequencyA4[2]) return 2;
		if (best == frequencyA4[3]) return 3;
		return -1;
	}
	else if (index == 5) {
		int best = max(frequencyA5[0],frequencyA5[1]);
		best = max(best, frequencyA5[2]);

		if (best == frequencyA5[0]) return 0;
		if (best == frequencyA5[1]) return 1;
		if (best == frequencyA5[2]) return 2;
		return -1;
	}
	else if (index == 6) {
		int best = max(frequencyA6[0],frequencyA6[1]);
		for (int i=2; i<14;i++) {
			best = max(best, frequencyA6[i]);
		}
		for (int i=0; i<14;i++) if (best == frequencyA6[i]) return i;
		return -1;
	}
	else if (index == 7) {
		int best = max(frequencyA7[0],frequencyA7[1]);
		for (int i=2; i<9;i++) {
			best = max(best, frequencyA7[i]);
		}
		for (int i=0; i<9;i++) if (best == frequencyA7[i]) return i;
		return -1;
	}
	else if (index == 8) {
		int best = max(frequencyA8[0],frequencyA8[1]);
		best = max(best, frequencyA8[2]);

		if (best == frequencyA8[0]) return 0;
		if (best == frequencyA8[1]) return 1;
		if (best == frequencyA8[2]) return 2;
		return -1;
	}
	else if (index == 9) {
		if (frequencyA9[0] > frequencyA9[1]) return 0;
		if (frequencyA9[0] <= frequencyA9[1]) return 1;
		return -1;
	}
	else if (index == 10) {
		if (frequencyA10[0] > frequencyA10[1]) return 0;
		if (frequencyA10[0] <= frequencyA10[1]) return 1;
		return -1;
	}
	else if (index == 12) {
		if (frequencyA12[0] > frequencyA12[1]) return 0;
		if (frequencyA12[0] <= frequencyA12[1]) return 1;
		return -1;
	}
	else if (index == 13) {
		int best = max(frequencyA13[0],frequencyA13[1]);
		best = max(best, frequencyA13[2]);

		if (best == frequencyA13[0]) return 0;
		if (best == frequencyA13[1]) return 1;
		if (best == frequencyA13[2]) return 2;
		return -1;
	}
	else if (index == 14) {
		int best = max(frequencyA14[0],frequencyA14[1]);
		best = max(best, frequencyA14[2]);

		if (best == frequencyA14[0]) return 0;
		if (best == frequencyA14[1]) return 1;
		if (best == frequencyA14[2]) return 2;
		return -1;
	}
	else if (index == 15) {
		int best = max(frequencyA15[0],frequencyA15[1]);
		best = max(best, frequencyA15[2]);

		if (best == frequencyA15[0]) return 0;
		if (best == frequencyA15[1]) return 1;
		if (best == frequencyA15[2]) return 2;
		return -1;
	}
	else return -1;
}
