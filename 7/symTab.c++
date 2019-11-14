#include <iostream>
#include <cstring>
#include "symTab.h"
using namespace std;

symTab symTable();

int symTab::search(char id[ID_LEN]) {
    for (int i=0; i<this->tableSize; i++) {
        if (strcmp(id, this->symbolTable[i].id) == 0) {
            return i;
        }
    }
    return -1;
}

int symTab::insert(char id[ID_LEN], char type, int size, int disp) {
    if (this->search(id) != -1) {
        cout<<"ERROR: variable "<<id<<" redeclared"<<endl;
        return;
    }

    int i = this->tableSize;
    strcpy(this->symbolTable[i].id, id);
    this->symbolTable[i].type = type;
    this->symbolTable[i].size = size;
    this->symbolTable[i].displacement = disp;
    this->tableSize++;
    return i;
}

symTab::symTab() {
    this->tableSize = 0;
}

void symTab::printTable() {
    for (int i=0; i<this->tableSize; i++) {
        cout<<this->symbolTable[i].type<<" "<<this->symbolTable[i].id
        <<"Size : "<<this->symbolTable[i].size<<"Displacement : "
        <<this->symbolTable[i].displacement
        <<endl;
    } 
}