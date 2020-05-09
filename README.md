[![Actions Status](https://github.com/RobertIndie/smark/workflows/Ubuntu/badge.svg)](https://github.com/RobertIndie/smark/actions)
[![Actions Status](https://github.com/RobertIndie/smark/workflows/Style/badge.svg)](https://github.com/RobertIndie/smark/actions)
[![Actions Status](https://github.com/RobertIndie/smark/workflows/Install/badge.svg)](https://github.com/RobertIndie/smark/actions)
[![Actions Status](https://github.com/RobertIndie/smark/workflows/Standalone/badge.svg)](https://github.com/RobertIndie/smark/actions)
[![codecov](https://codecov.io/gh/RobertIndie/smark/branch/master/graph/badge.svg)](https://codecov.io/gh/RobertIndie/smark)
[![Conventional Commits](https://img.shields.io/badge/Conventional%20Commits-1.0.0-yellow.svg)](https://conventionalcommits.org)

# Smark

HTTP benchmark tool.

Edit

## Develop

[Wiki](https://github.com/RobertIndie/smark/wiki)

### Build and run the standalone target

Use the following command to build and run the executable target.

```bash
cmake -Hstandalone -Bbuild/standalone
cmake --build build/standalone
./build/standalone/Smark --help
```

### Build and run test suite

Use the following commands from the project's root directory to run the test suite.

```bash
cmake -Htest -Bbuild/test
cmake --build build/test
CTEST_OUTPUT_ON_FAILURE=1 cmake --build build/test --target test

# or simply call the executable: 
./build/test/SmarkTests
```

To collect code coverage information, run CMake with the `-DENABLE_TEST_COVERAGE=1` option.

### Run clang-format

Use the following commands from the project's root directory to run clang-format (must be installed on the host system).

```bash
cmake -Htest -Bbuild/test

# view changes
cmake --build build/test --target format

# apply changes
cmake --build build/test --target fix-format
```

Due to [this issue](https://github.com/TheLartians/Format.cmake/issues/8), for WSL developer:

```bash
git config core.filemode true

cmake --build build/test --target check-format # format or check-format

git config core.filemode false
```

Note: This is just a temporary solution for those working on WSL.

See [Format.cmake](https://github.com/TheLartians/Format.cmake) for more options.

### Additional tools

The project includes an [tools.cmake](cmake/tools.cmake) file that can be used to import additional tools on-demand through CMake configuration arguments.
The following are currently supported.

- `-DUSE_SANITIZER=<Address | Memory | MemoryWithOrigins | Undefined | Thread | Leak | 'Address;Undefined'>`
- `-DUSE_CCACHE=<YES | NO>`

## Acknowledgement

Project template: [TheLartians: ModernCppStarter](https://github.com/TheLartians/ModernCppStarter)
