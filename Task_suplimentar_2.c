//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Magazin {
//	int cod;
//	char* denumire;
//	int nrProduse;
//	float* preturi;
//};
//
//typedef struct Magazin Magazin;
//
//
//Magazin initializare(int cod, const char* denumire, int nrProduse, float* preturi) {
//	Magazin m;
//	m.cod = cod;
//	m.denumire = (char*)malloc(strlen(denumire) + 1);
//	strcpy_s(m.denumire, strlen(denumire) + 1, denumire);
//	m.nrProduse = nrProduse;
//	m.preturi = (float*)malloc(sizeof(float) * nrProduse);
//	for (int i = 0; i < nrProduse; i++) {
//		m.preturi[i] = preturi[i];
//	}
//
//	return m;
//}
//
//Magazin citireArticol() {
//	int cod;
//	printf("Scrie cod articol: ");
//	scanf("%d", &cod);
//
//	char denumire[20];
//	printf("Scrie denumire produs: ");
//	scanf("%s", &denumire);
//
//	int nrProduse;
//	printf("Scrie nr produse: ");
//	scanf("%d", &nrProduse);
//
//	float* preturi = malloc(sizeof(float) * nrProduse);
//	printf("Introduceti preturile: ");
//	for (int i = 0; i < nrProduse; i++) {
//		scanf("%f", &preturi[i]);
//	}
//
//	Magazin m;
//	m.cod = cod;
//	m.denumire = (char*)malloc(strlen(denumire) + 1);
//	strcpy_s(m.denumire, strlen(denumire) + 1, denumire);
//	m.nrProduse = nrProduse;
//	m.preturi = (float*)malloc(sizeof(float) * nrProduse);
//	for (int i = 0; i < nrProduse; i++) {
//		m.preturi[i] = preturi[i];
//	}
//
//	return m;
//}
//
//void afisareArticol(Magazin m) {
//	printf("Cod articol: %d\n", m.cod);
//	printf("Denumire produs: %s\n", m.denumire);
//	printf("Nr produse: %d\n", m.nrProduse);
//	printf("Preturile: ");
//	for (int i = 0; i < m.nrProduse; i++) {
//		printf(", %.2f", m.preturi[i]);
//	}
//}
//
//float calculMediePret(Magazin m) {
//	if (m.nrProduse > 0 && m.preturi != NULL)
//	{
//		float suma = 0;
//		int count = 0;
//
//		for (int i = 0; i < m.nrProduse; i++) {
//			suma += m.preturi[i];
//			count++;
//		}
//
//		if (count != 0)
//			return suma / count;
//	}
//
//	return 0;
//}
//
//void modificareNumeArticol(Magazin* m, const char* numeNou) {
//	free(m->denumire);
//	m->denumire = (char*)malloc(strlen(numeNou) + 1);
//	strcpy_s(m->denumire, strlen(numeNou) + 1, numeNou);
//}
//
//void copiazaArticoleCuMedieMare(Magazin* vector, int nrElem, float prag, Magazin** vectorNou, int *dim) {
//	if (nrElem > 0 && vector != NULL) {
//		(*dim) = 0;
//
//		for (int i = 0; i < nrElem; i++) {
//			if (calculMediePret(vector[i]) > prag) {
//				(*dim)++;
//			}
//		}
//
//		(*vectorNou) = malloc(sizeof(Magazin) * (*dim));
//		int contor = 0;
//
//		for (int i = 0; i < nrElem; i++) {
//			if (calculMediePret(vector[i]) > prag) {
//				(*vectorNou)[contor] = initializare(vector[i].cod, vector[i].denumire, 
//													vector[i].nrProduse, vector[i].preturi);
//				contor++;
//			}
//		}
//	}
//}
//
//void afisareVector(Magazin* vector, int dim) {
//	if (vector != NULL && dim > 0) {
//		for (int i = 0; i < dim; i++) {
//			afisareArticol(vector[i]);
//			printf("\n");
//		}
//	}
//}
//
//void dezalocare(Magazin* vector, int dim) {
//	for (int i = 0; i < dim; i++) {
//		free(vector[i].denumire);
//		free(vector[i].preturi);
//	}
//	free(vector);
//}
//
//Magazin* concatenarePrinVectorNou(Magazin* v1, Magazin*v2, int dim1, int dim2, int *dimConcatenat) {
//	(*dimConcatenat) = dim1 + dim2;
//	Magazin* vectorConcatenat = malloc(sizeof(Magazin) * (dim1 + dim2));
//
//	for (int i = 0; i < dim1; i++) {
//		vectorConcatenat[i] = initializare(v1[i].cod, v1[i].denumire, v1[i].nrProduse, v1[i].preturi);
//	}
//
//	for (int j = 0; j < dim2; j++) {
//		vectorConcatenat[dim1 + j] = initializare(v2[j].cod, v2[j].denumire, v2[j].nrProduse, v2[j].preturi);
//	}
//
//	return vectorConcatenat;
//}
//
//void concatenarePrinVectorExistent(Magazin** v1, Magazin* v2, int* dim1, int dim2) {
//	*v1 = (Magazin*)realloc(*v1, sizeof(Magazin) * (*dim1 + dim2));
//
//	for (int i = 0; i < dim2; i++) {
//		(*v1)[*dim1 + i] = initializare(v2[i].cod, v2[i].denumire, v2[i].nrProduse, v2[i].preturi);
//	}
//
//	*dim1 = *dim1 + dim2;
//}
//
//int main() {
//
//	float* preturi = (float*)malloc(sizeof(float) * 3);
//	preturi[0] = 30;
//	preturi[1] = 37;
//	preturi[2] = 40;
//
//	Magazin m1 = initializare(1, "Branzeturi", 3, preturi);
//	Magazin m2 = initializare(2, "Vinuri", 3, preturi);
//	Magazin m3 = initializare(3, "Salate", 3, preturi);
//	Magazin m4 = initializare(4, "Sucuri", 3, preturi);
//	Magazin m5 = initializare(5, "Mere", 3, preturi);
//
//	int dimVector = 5;
//	Magazin* vector = (Magazin*)malloc(sizeof(Magazin) * 5);
//	vector[0] = m1;
//	vector[1] = m2;
//	vector[2] = m3;
//	vector[3] = m4;
//	vector[4] = m5;
//
//	Magazin* medieMare = NULL;
//	int dim = 5;
//	copiazaArticoleCuMedieMare(vector, 5, 35, &medieMare, &dim);
//	//afisareVector(medieMare, dim);
//	printf("\n\n");
//
//
//	//// concatenare prin vector nou
//	//Magazin* concat = NULL;
//	//int dimConcat;
//	//concat = concatenarePrinVectorNou(vector, medieMare, 5, dim, &dimConcat);
//	//afisareVector(concat, dimConcat);
//
//	// concatenare prin vector existent
//	concatenarePrinVectorExistent(&vector, medieMare, &dimVector, dim);
//	afisareVector(vector, dimVector);
//
//	dezalocare(vector, 5);
//	dezalocare(medieMare, dim);  
//	//dezalocare(concat, dimConcat);
//
//	return 0;
//}