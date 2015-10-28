# BTECH CS SEM IV

[![Build Status](https://travis-ci.org/agauniyal/cs-iv-algorithm.svg?branch=master)](https://travis-ci.org/agauniyal/cs-iv-algorithm)
[![Build status](https://ci.appveyor.com/api/projects/status/krmgl0by1i1xa87a/branch/master?svg=true)](https://ci.appveyor.com/project/agauniyal/cs-iv-algorithm/branch/master)

####Build & Test Instructions:

For linux/unix-like, a build.sh is already supplied with this repo. Use it like this:

```
chmod +x build.sh
```

Now for Release or Debug
```
./build.sh -DCMAKE_BUILD_TYPE=Release
./build.sh -DCMAKE_BUILD_TYPE=Debug
```

For Windows, create a new directory `build` and cd into it.
```
mkdir build
cd build
cmake ..
```

Then build your project with VS or MSBuild or however you want. Executables will probably generated in `build/bin/Debug` or `build/bin/Release` directories. Check appveyor.yml for hints.

To test, use `./build.sh -DCMAKE_BUILD_TYPE=Debug`. Two executables will be created, `sample` and `tests` inside
`build/bin` directory. Run `tests` to confirm all tests are passing.

---

####Include Instructions:

Include `cs-iv-algorithm.h` from `src/` in your source and compile with `cs-iv-algorithm.cpp` from `src/`.
Read Header for more information.
