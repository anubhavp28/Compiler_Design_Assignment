#ifndef SYMTAB_H
#define SYMTAB_H

#define ID_LEN 100
#define SYM_SIZE 100
typedef struct {
    char id[ID_LEN];
    char type;
    int size;
    int displacement;
} symTabEntry;

class symTab {
    symTabEntry symbolTable[SYM_SIZE];
    int tableSize;
public:
    symTab();
    int search(char id[ID_LEN]);
    int insert(char id[ID_LEN], char type, int size, int disp);
    void printTable();
};

extern symTab symTable();
#endif