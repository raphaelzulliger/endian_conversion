# Endian converting a struct

Tiny demo C++ project that shows the fully automated "endianness conversion" of a struct containing PODs.

## Introduction

While working on "embedded systems" projects, I often had to convert endianness of data, transferred in "structs" between systems. E.g. because the embedded system was running on a big endian CPU (e.g. PowerPC) while the PC was using Intel CPUs (little endian).

Often, we "manually" converted the endianness of each and every member of that struct, similar to this (pseudo) code:

```c++
SCommStruct s;

read_data_from_peer(s);

endian_convert(s.member1);
endian_convert(s.member2);
...
```

Sometimes we had some "semi-automatic" way to do conversion, but thus far, I've never came accross a fully automated solution despite having tried to google for one several times.

Today, I stumbled upon [a tweet](https://twitter.com/CppLibHunt/status/1330966204748496897), which led me to [Boost ptr](https://github.com/boostorg/pfr), which made me think that with that library, I should be able to fully automate conversion. So I tried it out and it indeed seems to be possible, as this small experiment shows.

## Build

```sh
mkdir build && cd build
conan install ..
cmake ..
make all
./bin/endian_fpr

```

## What it does

Boost ptr provides the ability to iterate over all members of a struct. It is then straight forward to endian-convert each of them. To demo this, this project then outputs the members in hex notation.

## Dependencies

- Boost pfr
- Boost endian

## Disclaimer

Having mentioned embedded systems, I should also mention that I did not run this code on any such system. Also, I did investigate how much the binary size increases by using 'pfr' and the 'endian' boost extensions. Thus, this solution may or may not be suitable for embedded systems...
