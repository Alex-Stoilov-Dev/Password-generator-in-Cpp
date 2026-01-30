#include <iostream>
#include <stdexcept>
#include <vector>
#include <random>

using namespace std;

int main(int argc, char* argv[]){

    int password_length;
    char dontclose;

    std::random_device rd;
    std::mt19937 gen(rd()); // Using mt19937 for random number generation.
			     
    const std::vector<char> ascii_set = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '`', '{', '|', '}', '~'
    };

    std::vector<char> password = {};

    std::uniform_int_distribution<int> dist(0, 81);
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
    cout << "How many characters would you like your password to have? (12-32) ";
    cin >> password_length;

    while(password_length < 12 || password_length > 32){
    	
	std::cout << "Password length is inadequate. Please specify a password in the range 12-32 characters! ";
	std::cin >> password_length;

    }

    for (int i = 0; i < password_length; i++){

        char random_char = ascii_set[dist(gen)];
        password.push_back(random_char);
    }

    for ( char c : password){
        cout << c;
    }

    std::cin.clear(); // Resets any error flags
    std::cin.ignore(1000, '\n'); // Skips the leftovers

    std::cout << "\nPress any key to continue...";
    std::cin.get();
}
