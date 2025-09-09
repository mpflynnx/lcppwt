## Installation of CppUTest

- Open bash prompt in a terminal. NOTE: bash prompt only, fish shell or others require different steps.
```bash
$ bash
$ cd ~
$ git clone https://github.com/cpputest/cpputest.git
```
- NOTE: To use MakefileWorker you need to build from the cpputest home directory.

```bash
$ cd cpputest
$ autoreconf . -i
$ ./configure
$ make tdd
```
- Open ~/.bashrc for editing

```bash
$ nano ~/.bashrc
```
- Enter at the last line of file
```bash
export CPPUTEST_HOME="$HOME/cpputest"
```