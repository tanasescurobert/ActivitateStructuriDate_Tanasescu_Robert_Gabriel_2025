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
//		else
//			return 0;
//	}
//}
//
//void modificareNumeArticol(Magazin* m, const char* numeNou) {
//	free(m->denumire);
//	m->denumire = (char*)malloc(strlen(numeNou) + 1);
//	strcpy_s(m->denumire, strlen(numeNou) + 1, numeNou);
//}
//
//int main() {
//	//Magazin m = citireArticol();
//	//afisareArticol(m);
//
//	float* preturi = (float*)malloc(sizeof(float) * 3);
//	preturi[0] = 30;
//	preturi[1] = 37;
//	preturi[2] = 40;
//
//	Magazin m2 = initializare(1, "Branzeturi", 3, preturi);
//	afisareArticol(m2);
//	printf("\n\n");
//
//	float medie = calculMediePret(m2);
//	printf("Media preturilor pentru %s este: %.2f", m2.denumire, medie);
//	printf("\n\n");
//
//	modificareNumeArticol(m2, "Vinuri");
//	afisareArticol(m2);
//	printf("\n\n");
//
//
//
//
//	return 0;
//}