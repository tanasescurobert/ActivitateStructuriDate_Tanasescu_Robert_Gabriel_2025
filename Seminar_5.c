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
typedef struct ListaDubla ListaDubla;

struct Nod {
    Nod* prev;
    Nod* next;
    Masina info;
};


struct ListaDubla {
    Nod* cap;
    Nod* coada;
};


Masina citireMasinaDinFisier(FILE* file) {
    char buffer[100];
    char sep[3] = ",\n";
    if (fgets(buffer, 100, file) == NULL) {
        Masina m1 = { 0 };
        return m1;
    }
    char* aux;
    Masina m1;
    aux = strtok(buffer, sep);
    m1.id = atoi(aux);
    m1.nrUsi = atoi(strtok(NULL, sep));
    m1.pret = (float)atof(strtok(NULL, sep));
    aux = strtok(NULL, sep);
    m1.model = malloc(strlen(aux) + 1);
    strcpy(m1.model, aux);

    aux = strtok(NULL, sep);
    m1.numeSofer = malloc(strlen(aux) + 1);
    strcpy(m1.numeSofer, aux);

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

void afisareListaMasiniDeLaInceput(ListaDubla lista) {
    Nod* m = lista.cap;

    while (m) {
        afisareMasina(m->info);
        m = m->next;
    }
}

void afisareListaMasiniDeLaFinal(ListaDubla lista) {
    Nod* m = lista.coada;

    while (m) {
        afisareMasina(m->info);
        m = m->prev;
    }
}

void adaugaMasinaInLista(ListaDubla* lista, Masina masinaNoua) {
    Nod* nou = (Nod*)malloc(sizeof(Nod));

    nou->info = masinaNoua;
    nou->prev = lista->coada;
    nou->next = NULL;

    if (lista->coada != NULL) {
        lista->coada->next = nou;
    }
    else {
        lista->cap = nou;
    }

    lista->coada = nou;
}

void adaugaLaInceputInLista(ListaDubla* lista, Masina masinaNoua) {
    Nod* nou = malloc(sizeof(Nod));
    nou->info = masinaNoua;
    nou->next = lista->cap;
    nou->prev = NULL;

    if (lista->cap) {
        lista->cap->prev = nou;
    }
    else {
        lista->coada = nou;
    }

    lista->cap = nou;
}

ListaDubla citireLDMasiniDinFisier(const char* numeFisier) {
    FILE* f = fopen(numeFisier, "r");
    if (f == NULL) {
        printf("Eroare %s\n", numeFisier);
        ListaDubla lista = { NULL, NULL };
        return lista;
    }
    ListaDubla lista;
    lista.cap = NULL;
    lista.coada = NULL;

    while (!feof(f)) {
        Masina m = citireMasinaDinFisier(f);
        if (m.id != 0) { 
            adaugaMasinaInLista(&lista, m);
        }
    }

    fclose(f);
    return lista;
}

void dezalocareLDMasini(ListaDubla* lista) {
    while (lista->cap) {
        if (lista->cap->info.numeSofer) {
            free(lista->cap->info.numeSofer);
        }
        if (lista->cap->info.model) {
            free(lista->cap->info.model);
        }

        Nod* m = lista->cap;
        lista->cap = m->next;
        free(m);
    }
}

float calculeazaPretMediu(ListaDubla lista) {
    float suma = 0;
    int nrMasini = 0;

    Nod* temp = lista.cap;
    while (temp) {
        suma += temp->info.pret;
        nrMasini++;
        temp = temp->next;
    }

    if (nrMasini == 0)
        return 0;
    else
        return suma / nrMasini;
}

void stergeMasinaDupaID(ListaDubla* lista, int id) {
    Nod* m = lista->cap;

    while (m && m->info.id != id) {
        m = m->next;
    }

    if (m) {
        if (m->prev) {
            m->prev->next = m->next;

            if (m->next)
                m->next->prev = m->prev;
            else
                lista->coada = m->prev;
        }
        else {
            lista->cap = m->next;
            if (m->next)
                m->next->prev = NULL;
            else
                lista->coada = NULL;
        }

        free(m->info.numeSofer);
        free(m->info.model);
        free(m);
    }

}

char* getNumeSoferMasinaScumpa(ListaDubla lista) {
    Nod* m = lista.cap;
    Nod* maxPretMasina = m;

    if (lista.cap) {
        while (m) {
            if (m->info.pret > maxPretMasina->info.pret) {
                maxPretMasina = m;
            }

            m = m->next;
        }

        char* nume = malloc(strlen(maxPretMasina->info.numeSofer) + 1);
        strcpy(nume, maxPretMasina->info.numeSofer);
        return nume;
    }
    else {
        return NULL;
    }
}

int main() {
    ListaDubla lista = citireLDMasiniDinFisier("masini.txt");
    afisareListaMasiniDeLaInceput(lista);

    stergeMasinaDupaID(&lista, 5);
    afisareListaMasiniDeLaFinal(lista);

    float medie = calculeazaPretMediu(lista);
    printf("Pret mediu = %.2f\n", medie);

    char* nume = getNumeSoferMasinaScumpa(lista);
    if (nume) {
        printf("Nume sofer care are masina cea mai scumpa: %s\n", nume);
        free(nume);
    }

    dezalocareLDMasini(&lista);

    return 0;
}
