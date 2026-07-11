#include <iostream>
#include <stdexcept>
#include <vector>
#include <random>

//using namespace std;

int main(int argc, char* argv[]){

    int password_length;
    char dontclose;

    std::random_device rd;
    std::mt19937 gen(rd()); // Using mt19937 for random number generation.
			     
    const std::vector<char> ascii_set = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '!', '"', '#', '$', '%', '&', '(', ')', '*', '+', ',', '-', '/', ':', ';', '<', '=', '>', '?', '@', '[', ']', '^', '`', '{', '|', '}', '~', 
    };

    const std::vector<char> lowercase = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };

    const std::vector<char> uppercase = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    const std::vector<char> numbers = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };

    const std::vector<char> symbols = {
        '!', '"', '#', '$', '%', '&', '(', ')', '*', '+', ',', '-', '/', 
        ':', ';', '<', '=', '>', '?', '@', '[', ']', '^', '`', '{', '|', '}', '~'
    };

    std::vector<char> password = {};
    std::vector<char> custom_char_set = {};


    std::uniform_int_distribution<int> dist(0,81);
    std::uniform_int_distribution<int> custom_dist(0,0);
    int choose_character_set;
    bool custom_charset_chosen;
    // This ensures that we generate a random number between 0-81 

    // This whole chunk allows the user to run ./main <pass_length>
    if(argc > 1){
        
        try{
	
            unsigned int password_length = std::stoi(argv[1]);

            if (password_length < 12 || password_length > 32){
                std::cout << "Password length is not adequate. Please specify a password in range 12-32 characters!";
                exit(1);
            }
            
            else{
                for (int i = 0; i < password_length; i++){
                    char random_char = ascii_set[dist(gen)];
                    password.push_back(random_char);
		    std::cout << password.at(i);
                }
                exit(1);
            }
        }
        catch(const std::invalid_argument& e){
            std::cout << "That's not a number!" << std::endl;
            exit(1);
        }
    }

    // This is the logic if the user runs main without arguments
    std::cout << "How many characters would you like your password to have? (12-32) ";
    std::cin >> password_length;

    while(password_length < 12 || password_length > 32){	
        std::cout << "Password length is inadequate. Please specify a password in the range 12-32 characters! ";
        std::cin >> password_length;
    }

    std::cout << "Which characters would you like to include in the password (leave blank for all)\n1. Lowercase\n2. Uppercase\n3. Numbers \n4. Symbols\n";
    std::cin >> choose_character_set;

    switch (choose_character_set)
    {
    case 1:
        custom_charset_chosen = true;
        custom_char_set = lowercase;
        break;

    case 12:
        custom_charset_chosen = true;
        custom_char_set.insert(custom_char_set.end(), lowercase.begin(), lowercase.end());
        custom_char_set.insert(custom_char_set.end(), uppercase.begin(), uppercase.end());
        break;

    case 123:
        custom_charset_chosen = true;
        custom_char_set.insert(custom_char_set.end(), lowercase.begin(), lowercase.end());
        custom_char_set.insert(custom_char_set.end(), uppercase.begin(), uppercase.end());
        custom_char_set.insert(custom_char_set.end(), numbers.begin(), numbers.end());
        break;

    case 1234:
        custom_charset_chosen = true;
        custom_char_set = ascii_set; 
        break;
        
    case 124:
        custom_charset_chosen = true;
        custom_char_set.insert(custom_char_set.end(), lowercase.begin(), lowercase.end());
        custom_char_set.insert(custom_char_set.end(), uppercase.begin(), uppercase.end());
        custom_char_set.insert(custom_char_set.end(), symbols.begin(), symbols.end());
        break;

    case 134:
        custom_charset_chosen = true;
        custom_char_set.insert(custom_char_set.end(), lowercase.begin(), lowercase.end());
        custom_char_set.insert(custom_char_set.end(), numbers.begin(), numbers.end());
        custom_char_set.insert(custom_char_set.end(), symbols.begin(), symbols.end());
        break;

    case 13:
        custom_charset_chosen = true;
        custom_char_set.insert(custom_char_set.end(), lowercase.begin(), lowercase.end());
        custom_char_set.insert(custom_char_set.end(), numbers.begin(), numbers.end());
    
        break;

    case 14:
        custom_charset_chosen = true;
        custom_char_set.insert(custom_char_set.end(), lowercase.begin(), lowercase.end());
        custom_char_set.insert(custom_char_set.end(), symbols.begin(), symbols.end());
    
        break;

    case 2:
        custom_charset_chosen = true;
        custom_char_set = uppercase;
    
        break;

    case 23:
        custom_charset_chosen = true;
        custom_char_set.insert(custom_char_set.end(), uppercase.begin(), uppercase.end());
        custom_char_set.insert(custom_char_set.end(), numbers.begin(), numbers.end());
        break;

    case 234:
        custom_charset_chosen = true;
        custom_char_set.insert(custom_char_set.end(), uppercase.begin(), uppercase.end());
        custom_char_set.insert(custom_char_set.end(), numbers.begin(), numbers.end());
        custom_char_set.insert(custom_char_set.end(), symbols.begin(), symbols.end()); 
        break;

    case 24:
        custom_charset_chosen = true;
        custom_char_set.insert(custom_char_set.end(), uppercase.begin(), uppercase.end());
        custom_char_set.insert(custom_char_set.end(), symbols.begin(), symbols.end());  
        break;

    case 3:
        custom_charset_chosen = true;
        custom_char_set = numbers;
        break;

    case 34:
        custom_charset_chosen = true;
        custom_char_set.insert(custom_char_set.end(), numbers.begin(), numbers.end());
        custom_char_set.insert(custom_char_set.end(), symbols.begin(), symbols.end()); 

        break;
    
    case 4:
        custom_charset_chosen = true;
        custom_char_set = symbols;
        break;

    default:
        custom_charset_chosen = false;
        break;
    }

    if(custom_charset_chosen){

        custom_dist.param(std::uniform_int_distribution<int>::param_type(0, custom_char_set.size() - 1));

        for (int i = 0; i < password_length; i++){
            char random_char = custom_char_set[custom_dist(gen)];
            password.push_back(random_char);
        }

        for (char c : password){
            std::cout << c;
        }
    }
    else{
        for (int i = 0; i < password_length; i++){
            char random_char = ascii_set[dist(gen)];
            password.push_back(random_char);
        }

        for (char c : password){
            std::cout << c;
        }
    }


    std::cin.clear(); // Resets any error flags
    std::cin.ignore(1000, '\n'); // Skips the leftovers

    std::cout << "\nPress any key to continue...";
    std::cin.get();
}
