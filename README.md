## Minimal example of a CMake-enabled C++ project

This repo contains the code for a multi file C++ project that uses CMake to manage the build process. 
The project consists of a main.cpp that calls a function defined in a separate file, my_library.cpp.

### Building the project

To build the project, create a build directory and run CMake from there:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

CMake will tell you if some dependency is missing in your system. If all goes well, a binary called `my_executable` will be created in the `build/bin` directory.
The library is built as a shared library and is placed in the `build/lib` directory.

You can run the executable with:

```bash
./bin/my_executable
```
If you now inspect the executable with ldd (on Linux) or otool (on macOS), you will see that it depends on the shared library:

```bash
$ ldd ./bin/my_executable
	linux-vdso.so.1 (0x00007f5155261000)
	libmy_library.so => /home/raul/repo/cmake-compilation/build/lib/libmy_library.so (0x00007f5155251000)
	libc.so.6 => /lib64/libc.so.6 (0x00007f515503a000)
	libstdc++.so.6 => /usr/lib64/libstdc++.so.6 (0x00007f5154e57000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f5155263000)
	libm.so.6 => /lib64/libm.so.6 (0x00007f5154d73000)
	librt.so.1 => /lib64/librt.so.1 (0x00007f5154d6c000)
	libgcc_s.so.1 => /usr/lib64/./libgcc_s.so.1 (0x00007f5154d51000)
```

If you remove libmy_library.so, the executable will not run:

```bash
$ rm build/lib/libmy_library.so
$ ./bin/my_executable
./bin/my_executable: error while loading shared libraries: libmy_library.so: cannot open shared object file: No such file or directory
```


### Cleaning the project

To clean the project, just remove the `build` directory:

```bash
rm -rf build
```
