#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <libgen.h>
#include "elflookup.h"

int main(int argc, char **argv)
{
    int c;

    // option parsing
    int optc = 0;		// tally all the options to determine offset for positional arguments
    int opt_k = 0;		// prefix the section value with the key
    int opt_n = 0;		// print a final newline?
    int opt_q = 0;		// quote the output?

    while ((c = getopt(argc, argv, "knq")) != -1)
	switch (c) {
	case 'k':
	    opt_k++;
	    optc++;
	    break;
	case 'n':
	    opt_n++;
	    optc++;
	    break;
	case 'q':
	    opt_q++;
	    optc++;
	    break;
	default:
	    abort();
	}

    // show usage if there isn't exactly two positional arguments
    if (argc - optc != 3) {
	dprintf(1, "Usage: %s [options] FILENAME SECTION\n",
		basename(argv[0]));
	return 1;
    }

    char *filename = argv[1 + optc];
    char *section = argv[2 + optc];
    char *value = get_elf_section_file(section, filename);

    
	//format and print output based on option flags set as command line arguments
	dprintf(1, "%s%s\t%s%s%s", opt_q>0?"'":"", opt_k?section:"", value, opt_q>0?"'":"", opt_n||opt_k?"\n":"");

    return 0;
}
