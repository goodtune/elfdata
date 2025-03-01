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
        return NULL;  // Argument parsing failed
    }

    // Check if the file exists and is readable
    if (access(filename, R_OK) != 0) {
        PyErr_SetString(PyExc_FileNotFoundError, "File does not exist or is not readable");
        return NULL;
    }

    res = get_elf_section_file(section, filename);
    if (res == NULL) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to retrieve ELF section");
        return NULL;  // Properly propagate the error to Python
    }

    return Py_BuildValue("s", res);
}

static char elf_section_file_docs[] =
    "elf_section_file(section, filename): retrieve the section from the filename";

static PyMethodDef elf_section_file_funcs[] = {
    {"elf_section_file", (PyCFunction) elf_section_file, METH_VARARGS,
     elf_section_file_docs},
    {NULL}
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef elflookup = {
    PyModuleDef_HEAD_INIT,
    "elflookup",
    NULL,                       // module documentation
    -1,
    elf_section_file_funcs
};

PyMODINIT_FUNC PyInit_elflookup(void)
{
    return PyModule_Create(&elflookup);
}
#else
void initelflookup(void)
{
    Py_InitModule3("elflookup", elf_section_file_funcs,
                   "elflookup C extension");
}
#endif
