//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//
//typedef struct StructuraMasina Masina;
//
//void afisareMasina(Masina masina) {
//	printf("ID: %i\n", masina.id);
//	printf("Nr. usi: %i\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n", masina.serie);
//}
//
//void afisareVectorMasini(Masina* masini, int nrMasini) {
//	for (int i = 0; i < nrMasini; i++) {
//		afisareMasina(masini[i]);
//		printf("\n");
//	}
//}
//
//void adaugaMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua) {
//	Masina* temp = (Masina*)malloc(((*nrMasini) + 1) * sizeof(Masina));
//	for (int i = 0; i < (*nrMasini); i++) {
//		temp[i] = (*masini)[i];
//	}
//
//	temp[(*nrMasini)] = masinaNoua;
//	free(*masini);
//	(*masini) = temp;
//	(*nrMasini)++;
//}
//
//Masina citireMasinaFisier(FILE* file) {
//	char buffer[100];
//	char delimiter[4] = ",\n";
//	fgets(buffer, 100, file);
//	char* token = strtok(buffer, delimiter);
//
//	Masina masina;
//	masina.id = atoi(token);
//
//	token = strtok(NULL, delimiter);
//	masina.nrUsi = atoi(token);
//
//	token = strtok(NULL, delimiter);
//	masina.pret = atof(token);
//
//	token = strtok(NULL, delimiter);
//	masina.model = (char*)malloc(strlen(token) + 1);
//	strcpy(masina.model, token);
//
//	token = strtok(NULL, delimiter);
//	masina.numeSofer = (char*)malloc(strlen(token) + 1);
//	strcpy(masina.numeSofer, token);
//
//	token = strtok(NULL, delimiter);
//	masina.serie = token[0];
//
//	return masina;
//}
//
//Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
//	FILE* file = fopen(numeFisier, "r");
//	Masina* masini = NULL;
//	if (!file) {
//		printf("Fisierul nu a putut fi deschis\n");
//	}
//	else {
//		while (!feof(file)) {
//			Masina m = citireMasinaFisier(file);
//			adaugaMasinaInVector(masini, nrMasiniCitite, m);
//		}
//
//		fclose(file);
//		return masini;
//	}
//}
//
//void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
//	for (int i = 0; i < (*nrMasini); i++) {
//		free((*vector)[i].model);
//		free((*vector)[i].numeSofer);
//	}
//
//	free(*vector);
//	(*vector) = NULL;
//	(*nrMasini) = 0;
//}
//
//int main() {
//	Masina masina = citireMasinaFisier("masini.txt");
//	afisareMasina(masina);
//
//	return 0;
//}