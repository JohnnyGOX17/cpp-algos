# cpp-algos

Algorithms, Data Structures and LeetCode solutions in C++

## Building

1. `$ cmake -S . -B build`
2. `$ cd build`
3. `$ make -j$(nproc)`
4. Run tests with `$ ctest`
5. Create `compile_commands.json` for [use with `clangd` linter](https://clangd.llvm.org/installation.html#project-setup) with `$ cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1`

## References

* [TheAlgorithms/C-Plus-Plus - GitHub](https://github.com/TheAlgorithms/C-Plus-Plus)

