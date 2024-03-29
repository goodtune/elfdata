# elfdata

Simple utility to make it easy to extract data sections from ELF binaries.

    make test

## Code-style

Use "Kernighan & Ritchie" style, with no tabs.

    indent -kr -nut *.c *.h

## Python extension

The `get_elf_section_file` function is exposed in Python module `elflookup` as
`elf_section_file` function.

    Python 3.6.8 (default, Aug  7 2019, 17:28:10) 
    [GCC 4.8.5 20150623 (Red Hat 4.8.5-39)] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import elflookup
    >>> elflookup.elf_section_file("PRODUCT_NAME", "demo")
    'demonstration'

    Python 3.7.4 (default, Sep  7 2019, 18:27:02) 
    [Clang 10.0.1 (clang-1001.0.46.4)] on darwin
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import elflookup
    >>> elflookup.elf_section_file("PRODUCT_NAME", "demo")
    'demonstration'

The extension is compatible with Python 2.7 and Python 3.x. Packages for Linux
and macOS are distributed on PyPI.
