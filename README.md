# BTECH CS SEM IV

[![Build Status](https://travis-ci.org/agauniyal/cs-iv-algorithm.svg?branch=master)](https://travis-ci.org/agauniyal/cs-iv-algorithm)

####Build & Test Instructions:

```
chmod +x build.sh
```

Now for Release or Debug
```
./build.sh -DCMAKE_BUILD_TYPE=Release
./build.sh -DCMAKE_BUILD_TYPE=Debug
```

To test, use `./build.sh -DCMAKE_BUILD_TYPE=Debug`. Two executables will be created, `sample` and `tests` inside
`build/bin` directory. Run `tests` to confirm all tests are passing.

---

####Include Instructions:

Include `cs-iv-algorithm.h` from `src/` in your source and compile with `cs-iv-algorithm.cpp` from `src/`.
Read Header for more information.
