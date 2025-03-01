# elfdata

Simple utility to make it easy to extract data sections from ELF binaries.

    make test

## Code-style

Use "Kernighan & Ritchie" style, with no tabs.

    indent -kr -nut *.c *.h

## Python extension

The `get_elf_section_file` function is exposed in Python module `elflookup` as
`elf_section_file` function.

    Python 3.7.9 (default, Aug 23 2020, 15:46:47) 
    [Clang 10.0.1 ] on darwin
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import elflookup
    >>> elflookup.elf_section_file("PRODUCT_NAME", "demo")
    'demonstration'

    Python 3.13.0 (main, Oct  7 2024, 05:02:14) [Clang 16.0.0 (clang-1600.0.26.4)] on darwin
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import elflookup
    >>> elflookup.elf_section_file("PRODUCT_NAME", "demo")
    'demonstration'

The extension is compatible with Python 3.7 and higher.
