#include <Python.h>
#include "elflookup.h"

static PyObject *elf_section_file(PyObject * self, PyObject * args)
{
    // function arguments
    char *section;
    char *filename;

    // return value
    char *res;

    // argument parsing
    if (!PyArg_ParseTuple(args, "ss", &section, &filename)) {
        return NULL;
    }
    // be useful
    res = get_elf_section_file(section, filename);
    return Py_BuildValue("s", res);
}

static char elf_section_file_docs[] =
    "elf_section_file(section, filename): retrieve the section from the filename";

static PyMethodDef elf_section_file_funcs[] = {
    {"elf_section_file", (PyCFunction) elf_section_file, METH_VARARGS,
     elf_section_file_docs},
    {NULL}
};

void initelflookup(void)
{
    Py_InitModule3("elflookup", elf_section_file_funcs,
                   "elflookup C extension");
}
