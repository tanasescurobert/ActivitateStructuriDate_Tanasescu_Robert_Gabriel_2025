#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StructuraMasina Masina;
struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};

typedef struct Nod Nod;
struct Nod {
	Masina info;
    Nod* next;
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
	m1.pret = atof(strtok(NULL, sep));
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

void afisareListaMasini(Nod* nod) {
	while (nod) {
		afisareMasina(nod->info);
		nod = nod->next;
	}
}

void adaugaMasinaInLista(Nod** lista, Masina masinaNoua) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));

	nou->info = masinaNoua;
	nou->next = NULL;

	if (*lista) {
		Nod* temp = (*lista);
		while (temp->next) {
			temp = temp->next;
		}

		temp->next = nou;
	}
	else {
		(*lista) = nou;
	}
}

void adaugaLaInceputInLista(/*lista de masini*/ Masina masinaNoua) {
	//adauga la inceputul listei o noua masina pe care o primim ca parametru


}

Nod* citireListaMasiniDinFisier(const char* numeFisier) {
	FILE* f = fopen(numeFisier, "r");

	Nod* lista = NULL;
	while (!feof(f)) {
		Masina m = citireMasinaDinFisier(f);
		adaugaMasinaInLista(&lista, m);
	}

	fclose(f);
	return lista;
}

void dezalocareListaMasini(Nod** lista) {
	while (*lista) {
		Nod* p = *lista;
		*lista = (*lista)->next;

		free(p->info.numeSofer);
		free(p->info.model);
		free(p);
	}
}

float calculeazaPretMediu(Nod* lista) {
	float suma = 0;
	int contor = 0;

	while (lista) {
		suma += lista->info.pret;
		contor++;

		lista = lista->next;
	}

	if (contor == 0)
		return 0;
	else
		return suma/contor;
}

void stergeMasiniDinSeria(/*lista masini*/ char serieCautata) {
	//sterge toate masinile din lista care au seria primita ca parametru.
	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie


}

int getNrUsiMasinaScumpa(Nod* lista) {
	if (lista) {
		float pretMax = 0;
		int nrUsiMasinaScumpa = 0;

		while (lista) {
			if (lista->info.pret > pretMax) {
				pretMax = lista->info.pret;
				nrUsiMasinaScumpa = lista->info.nrUsi;
			}

			lista = lista->next;
		}

		return nrUsiMasinaScumpa;
	}

	return 0;
}

float calculeazaPretulMasinilorUnuiSofer(Nod* lista, const char* numeSofer) {
	float suma = 0;

	while (lista) {
		if (strcmp(lista->info.numeSofer, numeSofer) == 0)
			suma += lista->info.pret;
		
		lista = lista->next;
	}

	return suma;
}

int main() {
	Nod* lista;
	lista = citireListaMasiniDinFisier("masini.txt");
	
	afisareListaMasini(lista);
	
	float pretMediu = calculeazaPretMediu(lista);
	printf("Pret mediu = %.2f\n", pretMediu);

	float pretMasiniSofer = calculeazaPretulMasinilorUnuiSofer(lista, "Ionescu");
	printf("Pret masini = %.2f\n", pretMasiniSofer);

	int nrUsiMasinaScumpa = getNrUsiMasinaScumpa(lista);
	printf("Nr usi masina scumpa = %d\n", nrUsiMasinaScumpa);

	dezalocareListaMasini(&lista);

	return 0;
}
