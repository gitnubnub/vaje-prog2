
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    for (int i = 0; i < stStudentov; i++) {
        if (studentje[i] -> vpisna == vpisna) {
            return i;
        }
    }

    return -1;
}

int poisciPO(Student* student, char* predmet) {
    int velikostTabele = student -> stPO;
    for (int i = 0; i < velikostTabele; i++) {
        PO trenutni = student -> po[i];
        if (strcmp(trenutni.predmet, predmet) == 0) {
            return i;
        }
    }

    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    int indeksStudenta = poisciStudenta(studentje, stStudentov, vpisna);
    if (indeksStudenta == -1) {
        studentje[stStudentov] = (Student*) calloc(1, sizeof(Student));
        studentje[stStudentov] -> vpisna = vpisna;
        studentje[stStudentov] -> stPO = 1;
        studentje[stStudentov] -> po = (PO*) calloc(10, sizeof(PO));

        strcpy(studentje[stStudentov] -> po[0].predmet, predmet);
        studentje[stStudentov] -> po[0].ocena = ocena;
        stStudentov++;
        return stStudentov;
    } else {
        Student* student = studentje[indeksStudenta];

        int indeksPara = poisciPO(student, predmet);
        if (indeksPara == -1)  {
            int velikostTabele = student -> stPO;
            strcpy(student -> po[velikostTabele].predmet, predmet);
            student -> po[velikostTabele].ocena = ocena;
            
            velikostTabele++;
            student -> stPO = velikostTabele;
            return stStudentov;
        } else {
            student -> po[indeksPara].ocena = ocena;
            return stStudentov;
        }
    }
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
