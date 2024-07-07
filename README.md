# cpp-algos

Algorithms, Data Structures and LeetCode solutions in C++

## Building

1. `$ cmake -S . -B build`
2. `$ cmake --build build -j$(nproc)`
3. Run tests with `$ cd build/ && ctest` or `$ ./build/CppAlgos`
4. Create `compile_commands.json` for [use with `clangd` linter](https://clangd.llvm.org/installation.html#project-setup) with `$ cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1`

## References

* [TheAlgorithms/C-Plus-Plus - GitHub](https://github.com/TheAlgorithms/C-Plus-Plus)

