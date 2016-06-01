#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;
using std::strlen;
using std::strcat;

char const * say_hello(const char* name) {
    char hello[] = "Hello, ";
    char excla[] = "!\n";
    char *greeting = (char *)malloc ( sizeof(char) * ( strlen(name) + strlen(hello) + strlen(excla) + 1 ) );
    if( greeting == NULL) exit(1);
    strcpy( greeting , hello);
    strcat(greeting, name);
    strcat(greeting, excla);
    return greeting;
}

#include <Python.h>

static PyObject *py_say_hello(PyObject* self, PyObject* args) {
    const char *name;
    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;

    return Py_BuildValue("s", say_hello(name));
}

static PyMethodDef HelloMethods[] =
{
     {"say_hello", py_say_hello, METH_VARARGS, "Greet somebody."},
     {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
inithello(void)
{
     (void) Py_InitModule("hello", HelloMethods);
}
