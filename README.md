## Minimal example of a CMake-enabled C++ project

This is an example C++ project that includes tests using GTest and documentation using Doxygen+Sphinx+breathe. The project is built using CMake.

### Prerequisites

Install the dependencies:

```bash
conda env create -f environment.yml
```
This will create a conda environment called `cppdev` which you can activate with:

```bash
conda activate cppdev
```

### Building the project

To build the project, create a build directory and run CMake from there:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

You can now run the tests:

```bash
ctest
```
It might be called ctest.exe in Windows.

The documentation will also be generated in the `build/docs/sphinx/index.html` directory. Open the `index.html` file in a web browser to view it.


### Cleaning the project

To clean the project, just remove the `build` directory:

```bash
rm -rf build
```
