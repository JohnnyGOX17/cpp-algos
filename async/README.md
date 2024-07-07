# C++ Async

## Tools

* `lscpu -C` can show `COHERENCY-SIZE` as the "minimum amount of data in bytes transferred from memory to cache".
* Can show thread names in htop by F2 → Display options → Show custom thread names

## References

* https://eli.thegreenplace.net/2016/c11-threads-affinity-and-hyperthreading/
* https://kb.ettus.com/Getting_Started_with_DPDK_and_UHD

### Library Books

* C++ High Performance - Second Edition
  - Chp 2 - A const reference
* C++ Concurrency in Action, Second Edition
* Learn C++ by Example
* A Tour of C++, 3rd Edition
* Learn C++ by Example
* Effective Modern C++
* Designing Data-Intensive Applications
* The Art of Writing Efficient Programs
* Modern C++ Programming Cookbook - Third Edition

### Rust Refs

- [ ] [Rust `std` library](https://doc.rust-lang.org/std/index.html) compared to STL/atomic/threads
  + [Thread pool - Wikipedia](https://en.wikipedia.org/wiki/Thread_pool)
- [ ] [crossbeam](https://github.com/crossbeam-rs/crossbeam)
- [ ] [A Bounded SPSC queue for Rust](https://github.com/polyfractal/bounded-spsc-queue)
- [ ] [disruptor-rs](https://github.com/nicholassm/disruptor-rs)
- [ ] [hashbrown](https://docs.rs/hashbrown/latest/hashbrown/)
- [ ] [tracing](https://docs.rs/tracing/latest/tracing/)
  + For C++, see [spdlog](https://github.com/gabime/spdlog)
