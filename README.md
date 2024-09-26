## A template for a C++ project with tests and documentation

This is an example C++ project that includes tests using GTest and documentation using Doxygen+Sphinx+breathe. The project is built using CMake.

### Prerequisites

Install the dependencies using conda:

```bash
conda env create -f environment.yml
```
This will create a conda environment called `cppdev` which you can activate with:

```bash
conda activate cppdev
```
If you do not have conda installed, I recommend you https://github.com/conda-forge/miniforge .
**You will have to activate the environment every time you open a new terminal.**

### Building the project

To build the project, create a build directory and run CMake from there:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```
In Windows, you might need to specify the generator as Ninja:
```bash
cmake -G "Ninja" ..
cmake --build .
```
#### You can now run the tests:

```bash
ctest
```
It might be called ctest.exe in Windows.
Every test included in the source codes under `tests` will be run.

#### Rendering the documentation

The documentation will also be generated in the `build/docs/sphinx/index.html` directory. Open the `index.html` file in a web browser to view it. In OSX, you can use the `open` command:
```bash
open docs/sphinx/index.html
```
In Windows, you can use the `start` command:
```bash
start docs\sphinx\index.html
```
and in Linux, you can use `xdg-open`:
```bash
xdg-open docs/sphinx/index.html
```


### Cleaning the project

To clean the project, just remove the `build` directory:

```bash
rm -rf build
```

### About

You can use this repo as a template for other projects. Look for the places where the current files appear (like tests/CMakeLists.txt mentioning test_my_library.cpp) to learn how to add your own files.

GTest codes are in the `tests` directory, and code is in the `src` directory. Both the codes under `src` and `tests` will look for headers in the `include` directory.

The documentation is generated in the `docs` directory. CMake will first run Doxygen to generate an XML database with the comments in the code, then Sphinx to will use that and the ReSTructuredText files under `docs/source` to generate the documentation webpage.

Some variables in the root `CMakeLists.txt` are used to customize the webpage, like the project name, version, and author. You can change them to fit your project. By default, `docs/source/index.rst` will list the documentation for every class and function under the namespace "homework".

