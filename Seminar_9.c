//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////trebuie sa folositi fisierul masini.txt
////sau va creati un alt fisier cu alte date
//
//struct Masina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct Masina Masina;
//
////creare structura pentru un nod dintr-un arbore binar de cautare
//typedef struct Nod Nod;
//struct Nod {
//	Masina info;
//	Nod* st;
//	Nod* dr;
//};
//
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret= atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//
//void adaugaMasinaInArbore(Nod** arbore, Masina masinaNoua) {
//	
//	if (*arbore == NULL) {
//		Nod* nou = malloc(sizeof(Nod));
//		nou->info = masinaNoua;
//		nou->st = NULL;
//		nou->dr = NULL;
//		*arbore = nou;
//	}
//	else {
//		if (masinaNoua.id < (*arbore)->info.id) {
//			adaugaMasinaInArbore(&((*arbore)->st), masinaNoua);
//		}
//		else if (masinaNoua.id > (*arbore)->info.id) {
//			adaugaMasinaInArbore(&((*arbore)->dr), masinaNoua);
//		}
//	}
//}
//
//Nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* arbore = NULL;
//	while (!feof(f))
//	{
//		Masina m = citireMasinaDinFisier(f);
//		adaugaMasinaInArbore(&arbore, m);
//	}
//
//	fclose(f);
//	return arbore;
//}
//
//void afisareInOrdine(Nod* arbore)
//{
//	if (arbore)
//	{
//		afisareInOrdine(arbore->st);
//		afisareMasina(arbore->info);
//		afisareInOrdine(arbore->dr);
//	}
//}
//
//void afisarePreOrdine(Nod* arbore)
//{
//	if (arbore)
//	{
//		afisareMasina(arbore->info);
//		afisarePreOrdine(arbore->st);
//		afisarePreOrdine(arbore->dr);
//	}
//}
//
//void afisarePostOrdine(Nod* arbore)
//{
//	if (arbore)
//	{
//		afisarePostOrdine(arbore->st);
//		afisarePostOrdine(arbore->dr);
//		afisareMasina(arbore->info);
//	}
//}
//
//void afisareMasiniDinArbore(Nod* arbore) {
//	printf("----- Afisare IN ORDINE -----\n");
//	afisareInOrdine(arbore);
//
//	printf("----- Afisare PRE ORDINE -----\n");
//	afisarePreOrdine(arbore);
//
//	printf("----- Afisare POST ORDINE -----\n");
//	afisarePostOrdine(arbore);
//}
//
//void dezalocareArboreDeMasini(Nod** arbore) {
//
//	if (*arbore) {
//		dezalocareArboreDeMasini(&(*arbore)->st);
//		dezalocareArboreDeMasini(&(*arbore)->dr);
//		free((*arbore)->info.model);
//		free((*arbore)->info.numeSofer);
//		free(*arbore);
//		(*arbore) = NULL;	
//	}
//}
//
////radacina=6, id=8
//Masina getMasinaByID(Nod* arbore, int id) {
//	Masina m;
//	m.id = -1;
//
//	if (arbore) {
//		if (arbore->info.id < id) 
//			return getMasinaByID(arbore->dr, id);
//		
//		else if (arbore->info.id > id) 
//			return getMasinaByID(arbore->st, id);
//		
//		else 
//			return arbore->info;		
//	}
//
//	return m;
//}
//
//int determinaNumarNoduri(Nod* arbore) {
//	if (!arbore)
//		return 0;
//	
//	return 1 + determinaNumarNoduri(arbore->st) + determinaNumarNoduri(arbore->dr);
//}
//
//int calculeazaInaltimeArbore(Nod* arbore) {
//	if (arbore == NULL)
//		return 0;
//
//	int inaltimeSt = calculeazaInaltimeArbore(arbore->st);
//	int inaltimeDr = calculeazaInaltimeArbore(arbore->dr);
//
//	if (inaltimeSt > inaltimeDr)
//		return 1 + inaltimeSt;
//	else
//		return 1 + inaltimeDr;
//
//	return 0;
//}
//
//float calculeazaPretTotal(Nod*arbore) {
//	if (arbore == NULL) {
//		return 0;
//	}
//
//	float totalStanga = calculeazaPretTotal(arbore->st);
//	float totalDreapta = calculeazaPretTotal(arbore->dr);
//
//	return arbore->info.pret + totalStanga + totalDreapta;
//}
//
//float calculeazaPretulMasinilorUnuiSofer(Nod* arbore, const char* numeSofer) {
//	//calculeaza pretul tuturor masinilor unui sofer.
//	if (arbore == NULL)
//		return 0;
//
//	if (strcmp(arbore->info.numeSofer, numeSofer) == 0)
//		return arbore->info.pret + calculeazaPretulMasinilorUnuiSofer(arbore->st, numeSofer) 
//								 + calculeazaPretulMasinilorUnuiSofer(arbore->dr, numeSofer);
//	else
//		return calculeazaPretulMasinilorUnuiSofer(arbore->st, numeSofer) + calculeazaPretulMasinilorUnuiSofer(arbore->dr, numeSofer);
//}
//
//int main() {
//	Nod* radacina= NULL;
//	radacina = citireArboreDeMasiniDinFisier("masini.txt");
//
//
//	// AFISARI
//	afisareMasiniDinArbore(radacina);
//	//afisareInOrdine(radacina);
//	//afisarePostOrdine(radacina);
//	//afisarePreOrdine(radacina);
//
//	// ZONA GETTERE 
//	int id = 8;
//	printf("Masina cautata este:\n");
//	Masina m= getMasinaByID(radacina, id);
//	afisareMasina(m);
//
//	float pret;
//	pret = calculeazaPretTotal(radacina);
//	printf("Pretul este: %.2f\n", pret);
//
//	int nrNoduri = determinaNumarNoduri(radacina);
//	printf("Numar noduri arbore = %d\n", nrNoduri);
//
//	char* nume = "Ionescu";
//	float pretMasiniSofer = calculeazaPretulMasinilorUnuiSofer(radacina, nume);
//	printf("Pret total al masinilor detinute de %s este %.2f\n", nume, pretMasiniSofer);
//
//	int inaltimeArbore = calculeazaInaltimeArbore(radacina);
//	printf("Inaltimea arborelui este %d", inaltimeArbore);
//
//
//	// DEZALOCARE
//	dezalocareArboreDeMasini(&radacina);
//
//
//	return 0;
//}