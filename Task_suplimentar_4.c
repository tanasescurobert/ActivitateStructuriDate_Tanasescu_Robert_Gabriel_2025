//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct StructuraMasina Masina;
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//
//typedef struct Nod Nod;
//struct Nod {
//	Masina info;
//   Nod* next;
//};
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
//	m1.pret = atof(strtok(NULL, sep));
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
//void afisareMasinaVector(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//void afisareListaMasini(Nod* nod) {
//	while (nod) {
//		afisareMasinaVector(nod->info); 
//		nod = nod->next;
//	}
//}
//
//void adaugaMasinaInLista(Nod** lista, Masina masinaNoua) {
//	Nod* nou = malloc(sizeof(Nod));
//	nou->info = masinaNoua;
//	nou->next = NULL;
//
//	if (*lista != NULL) { 
//		Nod* temp = *lista;
//		
//		while (temp->next != NULL) {
//			temp = temp->next;
//		}
//
//		temp->next = nou;
//	}
//	else {
//		*lista = nou;
//	}
//}
//
//
//
//void adaugaLaInceputInLista(Nod** lista, Masina masinaNoua) {
//	Nod* listaNoua = (Nod*)malloc(sizeof(Nod));
//	listaNoua->info = masinaNoua;
//	listaNoua->next = *lista;
//	*lista = listaNoua;
//}
//
//Nod* citireListaMasiniDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//
//	if (!f) {
//		printf("Fisierul nu a putut fi deschis\n");
//		return NULL; 
//	}
//
//	Nod* lista = NULL;
//	while (!feof(f)) {
//		Masina m = citireMasinaDinFisier(f);
//		adaugaMasinaInLista(&lista, m);
//	}
//
//	fclose(f);
//	return lista;
//}
//
//void dezalocareListaMasini(Nod** lista) {
//	while (*lista) {
//		Nod* p = *lista;
//		*lista = p->next;
//
//		free(p->info.numeSofer);
//		free(p->info.model);
//		free(p);
//	}
//}
//
//float calculeazaPretMediu(Nod* lista) {
//	float suma = 0;
//	int contor = 0;
//
//	while (lista) {
//		suma += lista->info.pret;
//		contor++;
//
//		lista = lista->next;
//	}
//
//	if (contor == 0)
//		return 0;
//	else
//		return suma/contor;
//}
//
//Nod* getMasiniScumpe(Nod* lista, int dim, float prag) {
//	Nod* nou = NULL; 
//	int contor = 0;
//
//	if (lista) {
//		while (lista) {
//			if (lista->info.pret > prag) {
//				adaugaMasinaInLista(&nou, lista->info);
//			}
//			lista = lista->next;  
//		}
//	}
//
//	return nou;
//}
//
//void stergeMasinaDupaCod(Nod** lista, int cod) {
//	if (*lista != NULL && (*lista)->info.id == cod) {
//		Nod* deSters = (*lista); 
//		(*lista) = deSters->next; 
//		 
//		if (deSters->info.model) 
//			free(deSters->info.model); 
//
//		if (deSters->info.numeSofer) 
//			free(deSters->info.numeSofer); 
//
//		free(deSters); 
//		return;
//	}
//	
//	if (*lista)
//	{
//		Nod* temp = *lista;
//		while (temp) {
//			while (temp->next != NULL && temp->next->info.id != cod) {
//				temp = temp->next;
//			}
//
//			if (temp->next) {
//				Nod* deSters = temp->next;
//				temp->next = deSters->next;
//
//				if (deSters->info.model)
//					free(deSters->info.model);
//
//				if (deSters->info.numeSofer)
//					free(deSters->info.numeSofer);
//
//				free(deSters);
//				return;
//			}
//			else {
//				temp = NULL;
//			}
//		
//		}
//	}
//}
//
//void stergeMasiniDinSeria(Nod** lista, char serieCautata) {
//	while (*lista != NULL && (*lista)->info.serie == serieCautata) {
//		Nod* deSters = (*lista);
//		(*lista) = deSters->next;
//
//		if (deSters->info.model)
//			free(deSters->info.model);
//
//		if (deSters->info.numeSofer)
//			free(deSters->info.numeSofer);
//
//		free(deSters);
//	}
//
//	if (*lista != NULL) {
//		Nod* temp = *lista;
//		while (temp) {
//			while (temp->next != NULL && temp->next->info.serie != serieCautata) {
//				temp = temp->next;
//			}
//
//			if (temp->next) {
//				Nod* deSters = temp->next;
//				temp->next = deSters->next;
//
//				if (deSters->info.model) 
//					free(deSters->info.model); 
//				 
//				if (deSters->info.numeSofer) 
//					free(deSters->info.numeSofer);  
//
//				free(deSters); 
//			}
//			else {
//				temp = NULL; 
//			}
//		}
//	}
//}
//
//int getNrUsiMasinaScumpa(Nod* lista) {
//	if (lista) {
//		float pretMax = 0;
//		int nrUsiMasinaScumpa = 0;
//
//		while (lista) {
//			if (lista->info.pret > pretMax) {
//				pretMax = lista->info.pret;
//				nrUsiMasinaScumpa = lista->info.nrUsi;
//			}
//
//			lista = lista->next;
//		}
//
//		return nrUsiMasinaScumpa;
//	}
//
//	return 0;
//}
//
//float calculeazaPretulMasinilorUnuiSofer(Nod* lista, const char* numeSofer) {
//	float suma = 0;
//
//	while (lista) {
//		if (strcmp(lista->info.numeSofer, numeSofer) == 0)
//			suma += lista->info.pret;
//		
//		
//		lista = lista->next;
//	}
//
//	return suma;
//}
//
//int main() {
//	Nod* lista;
//	lista = citireListaMasiniDinFisier("masini.txt");
//
//
//
//	Masina m;
//	m.id = 123;
//	m.nrUsi = 5;
//	m.pret = 1200;
//	m.serie = 'c';
//
//	char* model = "Test Model 1";
//	m.model = malloc(strlen(model) + 1);
//	strcpy_s(m.model, strlen(model) + 1, model);
//
//	char* sofer = "Test Nume 1";
//	m.numeSofer = malloc(strlen(sofer) + 1);
//	strcpy_s(m.numeSofer, strlen(sofer) + 1, sofer);
//
//	adaugaMasinaInLista(&lista, m);
//	//afisareListaMasini(lista);
//
//	//stergeMasiniDinSeria(&lista, 'I');
//	//afisareListaMasini(lista);
//
//	//int dim = 10;
//	//Nod* listaScumpe = getMasiniScumpe(lista, &dim, 9000);
//	//afisareListaMasini(listaScumpe);
//
//	stergeMasinaDupaCod(&lista, 123);
//	afisareListaMasini(lista);
//	
//	/*float pretMediu = calculeazaPretMediu(lista);
//	printf("Pret mediu = %.2f\n", pretMediu);
//
//	float pretMasiniSofer = calculeazaPretulMasinilorUnuiSofer(lista, "Ionescu");
//	printf("Pret masini = %.2f\n", pretMasiniSofer);
//
//	int nrUsiMasinaScumpa = getNrUsiMasinaScumpa(lista);
//	printf("Nr usi masina scumpa = %d\n", nrUsiMasinaScumpa);*/
//
//	dezalocareListaMasini(&lista); 
//
//	return 0;
//}
