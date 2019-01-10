#!/usr/bin/env python

import setuptools
from setuptools import setup
try:
    import pypandoc
    # pypandoc.download_pandoc()
    read_md = lambda f: pypandoc.convert(f, 'rst')
except ImportError:
    print("warning: pypandoc module not found, could not convert Markdown to RST")
    read_md = lambda f: open(f, 'r').read()


setup(
    name='Chess',
    version='3.3.0',
    description='Python chess client',
    long_description=read_md("README.md"),
    platforms='MacOS X, Windows, Linux',
    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 2.7',
    ],
    author='Aubhro Sengupta',
    author_email='maxonus2@gmail.com',
    url='https://github.com/mv-yurchenko/Chess',
    license='MIT',
    packages=setuptools.find_packages()
)
