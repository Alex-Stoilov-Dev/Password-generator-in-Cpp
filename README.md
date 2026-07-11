# C++ Password Generator
I already have an existing password generator in Python. However, I wanted to make one in C++ for fun.

This one should be better, since it's using a better random number generator under the hood``mt19937``.

## Functionality:
- You can generate a password of a desired length between 12 and 32 characters.
- You can choose which of the following character sets you want to include in your password:
    1. Lowercase letters 
    2. Uppercase letters
    3. Numbers
    4. Symbols
       
  > Note: You can mix and match these as you like. For example: if you want lowercase letters and numbers
  > in your password, pass in 13 to the program.
  > You can only list the numbers in ascending order. Example: 14 will generate a password
  > with lowercase letters and symbols, 41 will not generate a password like the latter.
- The default character set for the password includes all ASCII characters (upper and lower case), and special symbols.
  I forgot to add numbers to the vector, but I'll probably do it tomorrow. (Well I fixed that now. Only took me 6 months to come back to this repo)
- The program also supports CLI arguements. You can pass in the password length through the command line. Here's an example:
  
  ```
  ./main 16
  ```
  Unfortunately, you can only pass in the password length through the CLI.
  So if you use the CLI to generate a password you're always using the default character set.
  This is something I *could* improve. For now, this is how it works.

 ## Requirements:
  - C++ 11 or newer.
  > Note: In my initial commit I had this listed as C++ 20 or newer. I'm genuinely not sure why. I haven't added, nor removed, anything that's specific to C++20 as far as I'm aware.
  >  I compiled the code with C++ 11 and tested it a couple of times, so it should be fine for anyone using 11.

 ## Compilation:
  ```
  g++ main.cpp -o main -std=c++11
  ```
## Adding this as a built in function
If you wish to add this script to your terminal permanently as if it was a built in tool you can do this in your shell:
  ```bash
    echo "alias <PASSWORD_GENERATOR_COMMAND_NAME>=\"/path/to/where/you/saved/the/script\"" >> ~/.bashrc
  ```
Example:
 ```bash
    echo "alias genpass=\"~/Downloads/password_generator_script\"" >> ~/.bashrc
  ```
If you are using zsh, make sure to append the output to zshrc. If you're using fish, good luck :D, I don't.

This is a shortcut for writing:
```bash
  ./path/to/the/script/main
```
It will only work locally for your user, which is usually all you will need.

If there are multiple users on your machine, and you would like to use this as a system wide command, for any reason. Then you can do this:
```bash
  sudo cp /path/to/the/script /usr/local/bin/
```

