# push_swap

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

## State

[![push_swap Build](https://img.shields.io/github/actions/workflow/status/WOLFIE-OG/push_swap/makefile.yml?style=for-the-badge)](https://github.com/WOLFIE-OG/push_swap/actions/workflows/makefile.yml) ![push_swap Score](https://img.shields.io/badge/Score-100%2F125-brightgreen?style=for-the-badge)

## Installation & Building

To install and build

```bash
  git clone https://github.com/WOLFIE-OG/push_swap
  cd push_swap
  git submodule update --init --recursive
  make
  ./push_swap 7 4 8 5 2 10 3 9 6 1
```

## Testing

To run the tests

```bash
  bash tests/test_10.sh
  bash tests/test_10_1_arg.sh
  bash tests/test_50.sh
  bash tests/test_50_1_arg.sh
  bash tests/test_100.sh
  bash tests/test_100_1_arg.sh
```

## Testing [Debug]

To run the tests with additional debug information

```bash
  make re CFLAGS+=-DDEBUG_PRINT=1
  bash tests/test_10.sh
  bash tests/test_10_1_arg.sh
  bash tests/test_50.sh
  bash tests/test_50_1_arg.sh
  bash tests/test_100.sh
  bash tests/test_100_1_arg.sh
```