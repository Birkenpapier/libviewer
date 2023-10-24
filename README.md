# libviewer
An image viewer built to be lightweight and free from heavy dependencies.

> [!WARNING]
> This software is in its early stages. It's a work in progress, so keep your expectations in check.

## Prerequisites

To build and run `libviewer`, you'll need to have a few things set up:

1. **Visual Studio 2022** - The project is configured to be opened and built with VS2022.
2. **CMake** - A cross-platform build system. You can download it from [here](https://cmake.org/download/).
3. **vcpkg** - A C++ package manager that helps with acquiring and managing dependencies.

## Setting up vcpkg

1. First, clone `vcpkg`:
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg


2. Bootstrap `vcpkg`:
- Windows:
  ```
  .\bootstrap-vcpkg.bat
  ```

3. Integrate `vcpkg` with Visual Studio:

.\vcpkg integrate install


## Building and Running with CMake

1. Navigate to the `libviewer` directory.
2. Create a build directory and navigate into it:

mkdir build
cd build


3. Run CMake configuration:


cmake .. -DCMAKE_TOOLCHAIN_FILE=path_to_vcpkg/scripts/buildsystems/vcpkg.cmake


4. Build the project:


cmake --build .



5. Run the viewer:


.\Debug\PPMViewer.exe



## Building and Running with Visual Studio 2022

1. After configuring with CMake, there should be a `PPMViewer.sln` file inside the `build` directory. Double-click to open with Visual Studio 2022.
2. In Visual Studio, right-click on the `PPMViewer` project in the Solution Explorer and select 'Set as StartUp Project'.
3. Press `F5` or click on the "Local Windows Debugger" button to build and run.

## License

This project is unlicensed. It's free for anyone to use for any purpose. Check the [Unlicense](http://unlicense.org/) for more details.

---

**Note:** This software is in its early stages. Contributions, suggestions, and feedback are always welcome.



