/* Name : Anubhav Dinesh Patel 
   Roll No : 17020
   Reg No : 218
*/
#include <iostream>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main(int ac, char *av[]) {
    if (ac != 3) {
        cout<<"Incorrect or insufficient arguments supplied. \n";
        return 1;
    }

    int fd = open(av[1], O_RDONLY);
    long size = sysconf(_SC_PAGE_SIZE);

    Elf64_Ehdr *elfhP = (Elf64_Ehdr *)mmap(0, size, PROT_EXEC, MAP_PRIVATE, fd, 0); /* pointer to ELF header. */
    Elf64_Shdr *elfshP = (Elf64_Shdr *)((char *)(elfhP) + elfhP->e_shoff); /* pointer to section header table. */
    Elf64_Shdr *elfshsteP = (elfshP + elfhP->e_shstrndx); /* pointer to entry in section header table corresponding to section name table. */
    char *elfshst = (char *)elfhP + elfshsteP->sh_offset; /* pointer to section name table. */    

    int n;
    cin>>n;

    if (ac == 2) {
        /* iterate over section header table. */
        for (int i=0; i<elfhP->e_shnum; i++, elfshP++) {
            /* check if this entry correspondes to .text section. */
            if (strcmp(elfshst + elfshP->sh_name, ".text") == 0) {
                int (*fP)(int);
                fP = ((int (*)(int)) ((char*)elfhP + elfshP->sh_offset));
                cout<<(*fP)(n)<<endl;
            }
        }
    }
    else {
        /* iterate over section header table. */
        Elf64_Shdr *section_hdr_p = elfshP;
        for (int i=0; i<elfhP->e_shnum; i++, section_hdr_p++) {
            /* check if this entry correspondes to .symtab section. */
            if (strcmp(elfshst + section_hdr_p->sh_name, ".symtab") == 0) {

                /* use sh_link to get section header entry for corresponding symbol string table */
                char *elf64_sym_name_table = (char *)elfhP + (elfshP + section_hdr_p->sh_link)->sh_offset;

                /* find the beginning and end of symbol table */
                Elf64_Sym *elf64_sym_table = (Elf64_Sym *)((char *)elfhP + section_hdr_p->sh_offset);
                Elf64_Sym *elf64_sym_table_end =  (Elf64_Sym *)((char *)elfhP + section_hdr_p->sh_offset + section_hdr_p->sh_size);

                for (;  elf64_sym_table < elf64_sym_table_end; elf64_sym_table++) {

                    /* check if this symbol entry correspondes to the given function. */
                    if (strcmp(elf64_sym_name_table + elf64_sym_table->st_name, av[2]) == 0) {
                        int (*fP)(int);
                        char *section_Addr = (char *)elfhP + (elfshP + elf64_sym_table->st_shndx)->sh_offset;
                        fP = (int (*)(int)) (section_Addr + elf64_sym_table->st_value);
                        cout<<(*fP)(n)<<endl;
                    }
                }
            }
        }
    }

    close(fd);
    return 0;
}


