# C++ Password Generator
I already have an existing password generator in Python. However, I wanted to make one in C++ for fun.

This one should be better, since it's using a better random number generator under the hood``mt19937``.

## This password generator has the following functionality:

- Gives a password of specified length between 12-32.
- The valid character set for the password includes all (except for 0-9) ASCII characters (upper and lower case), and special symbols. I forgot to add numbers to the vector, but I'll probably do it tomorrow.
- Allows you to pass a command line argument for password length:
  
  ```
  ./main 16
  ```
  ^ This is perfectly valid. (More than 1 CLI arguments are not used)

 ## Requirements:
  - C++ 20 or newer.

 ## Compilation:
  ```
  g++ main.cpp -o main -std=c++20
  ```
