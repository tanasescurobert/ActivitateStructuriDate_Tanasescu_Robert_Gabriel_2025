//#include <stdio.h>
//#include <stdlib.h>
//
//struct Masina {
//	int id;
//	int anFabricatie;
//	char* sofer;
//	float kilometriiParcursi;
//	char initialaProducator;
//};
//
//typedef struct Masina Masina;
//
//Masina initializare(int id, int anFabricatie, const char* sofer, float kilometriiParcursi, char initialaProducator) {
//    Masina m;
//	m.id = id;
//	m.anFabricatie = anFabricatie;
//
//	if (sofer == NULL)
//		sofer = "n/a";
//
//	m.sofer = (char*)malloc(strlen(sofer) + 1);
//	strcpy_s(m.sofer, strlen(sofer) + 1, sofer);
//
//	m.kilometriiParcursi = kilometriiParcursi;
//	m.initialaProducator = initialaProducator;
//	return m;
//}
//
//void afisare(Masina m) {
//	printf("ID: %d \n", m.id);
//	printf("An fabricatie: %d \n", m.anFabricatie);
//	printf("Sofer: %s \n", m.sofer);
//	printf("Kilometrii Parcursi : %.2f \n", m.kilometriiParcursi);
//	printf("Initiala producator: %c \n", m.initialaProducator);
//}
//
//void afisareVector(Masina* vector, int dim) {
//	if (vector != NULL && dim > 0) {
//		for (int i = 0; i < dim; i++) {
//			afisare(vector[i]);
//			printf("\n");
//		}
//	}
//}
//
//Masina* copiazaPrimeleNElemente(Masina* vector, int dim, int nrElementeCopiate) {
//	Masina* vectorNou = NULL;
//	if (vector != NULL && nrElementeCopiate <= dim && nrElementeCopiate > 0) {
//		vectorNou = malloc(sizeof(Masina) * nrElementeCopiate);
//
//		for (int i = 0; i < nrElementeCopiate; i++) {
//			vectorNou[i] = initializare(vector[i].id, vector[i].anFabricatie,
//				vector[i].sofer, vector[i].kilometriiParcursi, vector[i].initialaProducator);
//		}
//	}
//
//	return vectorNou;
//}
//
//void dezalocare(Masina** vector, int* dim) {
//	if (*vector != NULL && *dim > 0) {
//		for (int i = 0; i < *dim; i++) {
//			free((*vector)[i].sofer);
//		}
//
//		free(*vector);
//		*vector = NULL;
//		*dim = 0;
//	}
//}
//
//void copiazaMasinaCuMultiKilometrii(Masina* vector, char nrElemente, float prag, struct Masina** vectorNou, int* dim) {
//	if (vector != NULL && nrElemente > 0) {
//		(*dim) = 0;
//		for (int i = 0; i < nrElemente; i++) {
//			if (vector[i].kilometriiParcursi > prag) {
//				(*dim)++;
//			}
//		}
//
//		(*vectorNou) = malloc(sizeof(Masina) * (*dim));
//		int contor = 0;
//
//		for (int i = 0; i < nrElemente; i++) {
//			if (vector[i].kilometriiParcursi > prag) {
//				(*vectorNou)[contor] = vector[i];
//
//				(*vectorNou)[contor].sofer = malloc(sizeof(char) * (strlen(vector[i].sofer) + 1));
//				strcpy_s((*vectorNou)[contor].sofer, strlen(vector[i].sofer) + 1, vector[i].sofer);
//
//				contor++;
//			}
//		}
//	}
//
//}
//
//Masina getPrimaMasinaDupaSofer(Masina* vector, int dim, const char* numeSofer) {
//	for (int i = 0; i < dim; i++) {
//		if (strcmp(numeSofer, vector[i].sofer) == 0) {
//			return vector[i];
//		}
//	}
//
//	return initializare(-1, 0, NULL, 0, '-');
//}
//
//
//int main() {
//	int nrElemente = 3;
//	struct Masina* vector = malloc(sizeof(struct Masina) * nrElemente);
//
//	vector[0] = initializare(1, 2020, "Marian", 2300, 'F');
//	vector[1] = initializare(2, 2008, "Cristi", 3500.6, 'A');
//	vector[2] = initializare(3, 2007, "Marian", 7500, 'W');
//
//	//afisare(vector[0]);
//	//afisare(vector[1]);
//	//afisare(vector[2]);
//
//	//afisareVector(vector, nrElemente);
//
//	int nrElementeCopiate = 2;
//	Masina* vectorNou = copiazaPrimeleNElemente(vector, nrElemente, nrElementeCopiate);
//	afisareVector(vectorNou, nrElementeCopiate);
//	dezalocare(&vectorNou, &nrElementeCopiate);
//
//
//	float prag = 2500;
//	copiazaMasinaCuMultiKilometrii(vector, nrElemente, prag, &vectorNou, &nrElementeCopiate);
//	afisareVector(vectorNou, nrElementeCopiate);
//	dezalocare(&vectorNou, &nrElementeCopiate);
//
//
//	Masina masina = getPrimaMasinaDupaSofer(vector, nrElemente, "Marian");
//	afisare(masina);
//	dezalocare(&vector, &nrElemente);
//
//	
//
//	return 0;
//}
//
