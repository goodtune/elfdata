#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __APPLE__
#include <libelf/libelf.h>
#elif _WIN32
#include "elf.h"
#else
#include <elf.h>
#endif

char *get_elf_section_data(FILE * fd, Elf64_Ehdr eh, Elf64_Shdr sh_table[],
                           char *section)
{
    int i;
    char *sh_str;
    char *buff;

    buff = malloc(sh_table[eh.e_shstrndx].sh_size);

    if (buff != NULL) {

        fseek(fd, sh_table[eh.e_shstrndx].sh_offset, SEEK_SET);
        fread(buff, 1, sh_table[eh.e_shstrndx].sh_size, fd);
    }
    sh_str = buff;

    for (i = 0; i < eh.e_shnum; i++) {
        if (!strcmp(section, (sh_str + sh_table[i].sh_name))) {
            break;
        }

    }

    free(buff);

    if (i < eh.e_shnum) {

        char *res = malloc(sh_table[i].sh_size + 1);
        fseek(fd, sh_table[i].sh_offset, SEEK_SET);
        fread(res, 1, sh_table[i].sh_size, fd);
        res[sh_table[i].sh_size] = 0;
        return res;

    }

    return "";
}

char *get_elf_section_file(char *section, char *filename)
{
    char *res;

    Elf64_Ehdr elf_header;      // Elf header
    Elf64_Shdr *sh_table;       // Elf symbol table

    FILE *fp = fopen(filename, "r");

    fseek(fp, 0, SEEK_SET);
    if (fread(&elf_header, 1, sizeof(Elf64_Ehdr), fp) == 0) {
        return "";
        }
    sh_table = malloc(elf_header.e_shentsize * elf_header.e_shnum);

    fseek(fp, elf_header.e_shoff, SEEK_SET);
    if (fread(sh_table, 1, elf_header.e_shentsize * elf_header.e_shnum, fp) == 0) {
        return "";
        }

    res = get_elf_section_data(fp, elf_header, sh_table, section);

    free(sh_table);
    fclose(fp);

    return res;
}

char *get_elf_section(char *section)
{
    return get_elf_section_file(section, "/proc/self/exe");
}
