#include <iostream>
#include <cstring>
#include "symTab.h"
using namespace std;

symTab symTable;

int symTab::search(char id[ID_LEN]) {
    for (int i=0; i<this->tableSize; i++) {
        if (strcmp(id, this->symbolTable[i].id) == 0) {
            return i;
        }
    }
    return -1;
}

int symTab::insert(char id[ID_LEN]) {
    static int disp = 0;
    if (this->search(id) != -1) {
        return this->search(id);
    }

    int i = this->tableSize;
    strcpy(this->symbolTable[i].id, id);
    this->symbolTable[i].type = 0;
    this->symbolTable[i].size = 4;
    disp += 4;
    this->symbolTable[i].displacement = disp;
    this->tableSize++;
    return i;
}

symTab::symTab() {
    this->tableSize = 0;
}

void symTab::printTable() {
    for (int i=0; i<this->tableSize; i++) {
        switch (this->symbolTable[i].type) {
            case 'i': cout<<"int"; break;
            case 'r': cout<<"real"; break;
            case 'U': cout<<"undefined"; 
        }
        cout<<" "<<this->symbolTable[i].id
        <<" size : "<<this->symbolTable[i].size<<" displacement : "
        <<-this->symbolTable[i].displacement
        <<endl;
    } 
}