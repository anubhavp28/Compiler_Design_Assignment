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
    if (ac != 2) {
        cout<<"Supply exactly a single argument - object file name. \n";
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

    /* iterate over section header table. */
    for (int i=0; i<elfhP->e_shnum; i++, elfshP++) {
        /* check if this entry correspondes to .text section. */
        if (strcmp(elfshst + elfshP->sh_name, ".text") == 0) {
            int (*fP)(int);
            fP = ((int (*)(int)) ((char*)elfhP + elfshP->sh_offset));
            cout<<(*fP)(n)<<endl;
        }
    }
    close(fd);
    return 0;
}


