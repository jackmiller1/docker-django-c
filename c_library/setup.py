#!/usr/bin/env python

from distutils.core import setup, Extension

module1 = Extension("hello", ["./c_library/helloworld.cpp"])

setup (name = 'PackageName',
        version = '1.0',
        description = 'This is a demo package',
        ext_modules = [module1])
