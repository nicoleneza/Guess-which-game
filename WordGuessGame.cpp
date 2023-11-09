
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>

using namespace std;

const int ARRAY_SIZE = 9;

const char *getWord(const char array[][20], int size)
{
    srand(static_cast<unsigned>(time(nullptr)));
    int index = rand() % size;
    if (index >= 0 && index < size)
    {
        return array[index];
    }
    else
    {
        return const_cast<char*>("Invalid index"); //using const_cast to remove the const qualifier
    }
}


int main()
{

   const char animals[ARRAY_SIZE][20] = {"Elephant", "Goat", "Cat", "Lion", "Wolf", "Leopard","tiger","dog","giraffe"};
   const char teams[ARRAY_SIZE][20] = {"machester", "Devdynamos", "Real Madrid", "Arsenal", "Amavubi","fbling","barcelona"};
   const char districts[ARRAY_SIZE][20] = {"Gasabo", "Nyabihu", "Gatsibo", "Kicukiro", "Burera", "Muhanga","musanze","kamonyi"};
   const char films[ARRAY_SIZE][20] = {"Blood sisters", "Dangerous", "Avengers", "Spiderman", "Mission", "Barbie","flash"};
   const char books[ARRAY_SIZE][20] = {"The Forth", "Romeo and Juliet", "Twin Troubles", "Love story", "Bible Learn","chemistry"};

    char choice = 'y';
    bool won = false;

    while (choice != 'n')
    {
        cout << "Choose category of word you need?\n"
             << "1. Animals\n"
             << "2. Teams\n"
             << "3. Districts\n"
             << "4. Films\n"
             << "5. Books\n";
        int category;
        const char *word;
        if (cin >> category)
        {
            switch (category)
            {
            case 1:
                word = getWord(animals, ARRAY_SIZE);
                break;
            case 2:
                word = getWord(teams, ARRAY_SIZE);
                break;
            case 3:
                word = getWord(districts, ARRAY_SIZE);
                break;
            case 4:
                word = getWord(films, ARRAY_SIZE);
                break;
            case 5:
                word = getWord(books, ARRAY_SIZE);
                break;
            default:
                cout << "Invalid category\n";
                return false;
                break;
            }
        }
        else
        {
            cout << "you have to enter an integer";
            return false;
        }
        char option;
        int chances = 15;

        char guess[20];
        cout<<"you have 15 guessed \n";

        for (unsigned i = 0; i < strlen(word); i++)
        {
            guess[i] = '_';

        }
        guess[strlen(word)] = '\0'; 

        while (chances > 0)
        {
            cout<<chances--<<" chances left "<<endl;
            cout << "guess the letter or q for exit: ";
            cin >> option;

            if (option == 'q' || isdigit(option))
            {
                break;
            }
            else
            {
                
                for (int i = 0; i < strlen(word) ; i++)
                {

                    if (tolower(word[i]) == option)
                    {
                        guess[i] = word[i];
                    }
                    if (word[i] == ' ')
                    {
                        guess[i] = ' ';
                    }
                    if (!guess[i] || guess[i] == '_')
                    {
                        guess[i] = '_';
                    }
                }

                for (unsigned j = 0; j < strlen(guess); j++)
                {
                    if (guess[j] == '_')
                    {
                        cout << "_ ";
                    }
                    else if (guess[j] == ' ')
                    {
                        cout << "  ";
                    }
                    else
                    {
                        cout << guess[j] << ' ';
                    }
                }
                cout << "\n\n";
            
                    bool match = true;
                    for (unsigned i = 0; i < strlen(word); i++)
                    {
                        if (guess[i] != word[i])
                        {
                            match = false;
                            break; 
                        } 
                    }
                    if (match)
                    {
                        cout << "Congratulations! Your guess is correct.\n\n";
                        won = true;
                        chances = 0;
                    }
                
            }
            chances--;
        }
        if (!won)
        {
            cout << "Out of guesses!!\n\n";
            cout<<word<<endl;
        }

        cout << "Continue? y or n  : ";
        cin >> choice;
    }
    return 0;
}
