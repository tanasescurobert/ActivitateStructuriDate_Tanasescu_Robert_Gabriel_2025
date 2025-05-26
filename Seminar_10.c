#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;
typedef struct Nod Nod;

struct Nod {
	Masina info;
	Nod* st;
	Nod* dr;
	int gradEchilibru;
};


Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret= atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

int calculeazaInaltimeArbore(Nod* arbore) {
	if (arbore == NULL)
		return 0;

	int st = calculeazaInaltimeArbore(arbore->st);
	int dr = calculeazaInaltimeArbore(arbore->dr);

	if (st > dr)
		return 1 + st;
	else
		return 1 + dr;
}

//ALTE FUNCTII NECESARE:
// - aici veti adauga noile functii de care aveti nevoie.
void rotireStanga(Nod** arbore) {
	Nod* aux = (*arbore)->dr;
	(*arbore)->dr = aux->st;
	aux->st = *arbore;
	*arbore = aux;
	(*arbore)->gradEchilibru--;
}

void rotireDreapta(Nod** arbore) {
	Nod* aux = (*arbore)->st;
	(*arbore)->st = aux->dr;
	aux->dr = *arbore;
	*arbore = aux;
	(*arbore)->gradEchilibru++;
}


void adaugaMasinaInArboreEchilibrat(Nod**arbore, Masina masinaNoua) {

	if (*arbore == NULL) {
		Nod* nou = malloc(sizeof(Nod));
		nou->info = masinaNoua;
		nou->st = NULL;
		nou->dr = NULL;
		nou->gradEchilibru = 0;
		*arbore = nou;
	}
	else {
		if (masinaNoua.id < (*arbore)->info.id) {
			adaugaMasinaInArboreEchilibrat(&((*arbore)->st), masinaNoua);
			(*arbore)->gradEchilibru++;
		}
		else {
			adaugaMasinaInArboreEchilibrat(&((*arbore)->dr), masinaNoua);
			(*arbore)->gradEchilibru--;
		}

		if ((*arbore)->gradEchilibru == 2) {
			if ((*arbore)->st->gradEchilibru == -1) {
				rotireStanga(&((*arbore)->st));
			}
				
			rotireDreapta(arbore);
		}

		if ((*arbore)->gradEchilibru == -2) {
			if ((*arbore)->dr->gradEchilibru == 1) {
				rotireDreapta(&((*arbore)->dr));
			}

			rotireStanga(arbore);
		}
	}
}


void* citireArboreDeMasiniDinFisier(const char* numeFisier) {
	FILE* f = fopen(numeFisier, "r");
	Nod* arbore = NULL;
	while (!feof(f)) {
		Masina m = citireMasinaDinFisier(f);
		adaugaMasinaInArboreEchilibrat(&arbore, m);
	}

	fclose(f);
	return arbore;
}

void afisarePreOrdine(Nod* arbore) {
	if (arbore) {
		afisareMasina(arbore->info);
		afisarePreOrdine(arbore->st);
		afisarePreOrdine(arbore->dr);
	}
}

void afisarePostOrdine(Nod* arbore) {
	if (arbore) {
		afisarePostOrdine(arbore->st);
		afisarePostOrdine(arbore->dr);
		afisareMasina(arbore->info);
	}
}

void afisareInOrdine(Nod* arbore) {
	if (arbore) {
		afisarePreOrdine(arbore->st);
		afisareMasina(arbore->info);
		afisarePreOrdine(arbore->dr);
	}
}

void afisareMasiniDinArbore(Nod* arbore) {
	printf("----- Afisare IN ORDINE -----\n");
	afisareInOrdine(arbore);
	
	printf("----- Afisare PRE ORDINE -----\n");
	afisarePreOrdine(arbore);
	
	printf("----- Afisare POST ORDINE -----\n");
	afisarePostOrdine(arbore);
}



void dezalocareArboreDeMasini(Nod** arbore) {

	if (*arbore != NULL) {
		dezalocareArboreDeMasini((*arbore)->st);
		dezalocareArboreDeMasini((*arbore)->dr);
		free((*arbore)->info.numeSofer);
		free((*arbore)->info.model);
		free(*arbore);
		*arbore = NULL;
	}
}

//Preluati urmatoarele functii din laboratorul precedent.
//Acestea ar trebuie sa functioneze pe noul arbore echilibrat.

Masina getMasinaByID(Nod* arbore, int id) {
	Masina m;
	m.id = -1;

	if (arbore != NULL) {
		if (arbore->info.id < id)
			return getMasinaByID(arbore->dr, id);

		else if (arbore->info.id > id)
			return getMasinaByID(arbore->st, id);

		else
			return arbore->info;
	}

	return m;
}

int determinaNumarNoduri(Nod* arbore) {
	if (arbore == NULL)
		return 0;

	return 1 + determinaNumarNoduri(arbore->st) + determinaNumarNoduri(arbore->dr);
}

float calculeazaPretTotal(Nod* arbore) {
	if (arbore == NULL)
		return 0;

	return arbore->info.pret + determinaNumarNoduri(arbore->st) + determinaNumarNoduri(arbore->dr);
}

float calculeazaPretulMasinilorUnuiSofer(Nod* arbore, const char* numeSofer) {
	if (arbore == NULL)
		return 0;

	if (strcmp(arbore->info.numeSofer, numeSofer) == 0)
		return arbore->info.pret + calculeazaPretulMasinilorUnuiSofer(arbore->st, numeSofer) 
									+ calculeazaPretulMasinilorUnuiSofer(arbore->dr, numeSofer);
	else 
		return calculeazaPretulMasinilorUnuiSofer(arbore->st, numeSofer) 
				+ calculeazaPretulMasinilorUnuiSofer(arbore->dr, numeSofer);
}

int main() {
	Nod* arbore = citireArboreDeMasiniDinFisier("masini.txt");
	afisareMasiniDinArbore(arbore);
	
	printf("Inaltime arbore = %d\n", calculeazaInaltimeArbore(arbore));

	return 0;
}