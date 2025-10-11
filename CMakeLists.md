# IMUSim Project Architecture
This diagram shows how the CMakeLists.txt builds the project, 
linking the main executable and the tests to the shared library.


                          ┌──────────────────────────────────┐
                          │          CMake Project           │
                          │            (IMUSim)              │
                          └──────────────────────────────────┘
                                        │
                                        │
                                        ▼
                      ┌──────────────────────────────────────┐
                      │ Collect sources in /src/*.cpp        │
                      │ EXCEPT main.cpp                      │
                      └──────────────────────────────────────┘
                                        │
                                        ▼
         ┌──────────────────────────────────────────────────────────┐
         │                  imusim_lib  (STATIC LIB)                │
         │ -------------------------------------------------------- │
         │  Contains all core logic:                                │
         │    - imu_sensor.cpp                                      │
         │    - kalman_filter.cpp                                   │
         │    - trajectory.cpp                                      │
         │    - vec3.cpp                                            │
         │    - logger.cpp                                          │
         │  Does *not* contain main.cpp                             │
         └──────────────────────────────────────────────────────────┘
                                        │
                   ┌────────────────────┴──────────────────────┐
                   │                                           │
                   ▼                                           ▼
    ┌──────────────────────────────┐             ┌──────────────────────────────┐
    │        imusim (EXE)          │             │      runTests (EXE)          │
    │----------------------------- │             │----------------------------- │
    │  main.cpp                    │             │  test_sensor.cpp             │
    │  links → imusim_lib          │             │  test_kalman.cpp             │
    │                              │             │  test_utils.cpp              │
    │  Produces the simulation     │             │  vec3_test.cpp               │
    └──────────────────────────────┘             │                              │
                                                 │  links → imusim_lib          │
                                                 │  links → gtest + gtest_main  │
                                                 └──────────────────────────────┘
                                                                     │
                                                                     ▼
                                  ┌────────────────────────────────────────────┐
                                  │                CTest                       │
                                  │ Registers: add_test(NAME AllTests runTests)│
                                  │ Running `ctest` executes runTests          │
                                  └────────────────────────────────────────────┘


