#include <iostream>
#include <regex>
#include <ctime>
#include <cstdlib>


using namespace std;

int validate_and_parse(string inputstr, regex input_validator_regexp);

int main()
{
    srand(time(NULL));
    unsigned short wylosowanaLiczba;
    const unsigned short MAX_TRIES = 4;

    //char const  *FINISH = "quit";
    char const *FINISH = "quit";


    string line;
    regex input_validator_regexp = regex("[0-9\\-]+",regex_constants::basic);

    cout << "Zgadnij liczbę od 0 do 10!" << endl << endl;

    unsigned int total_rounds = 0;
    unsigned int won_rounds = 0;

    do {
        total_rounds++;
        wylosowanaLiczba = rand() % 11;
        bool won = false;

        cout << endl << "------------- próba nr. " << total_rounds << " ------------" << endl;

        for(int i=1;i<= MAX_TRIES ;i++){


            cout << endl << "Wpisz liczbę całkowitą lub '" << FINISH << "' aby zakończyć: ";
            cin >> line;

            int guess;
            if((guess=validate_and_parse(line, input_validator_regexp)) >= 0){


                if(guess == wylosowanaLiczba){
                    cout << endl << "WYGRANA! Zgadł(a|e)ś! Nasza liczba to " << wylosowanaLiczba << endl << endl;
                    won_rounds++;
                    won = true;
                    break;
                }else if(guess < wylosowanaLiczba) {
                    cout << "Za mało!" << endl;
                }else{
                    cout << "Za dużo!" << endl;
                }

            }else if( line != FINISH){
                cerr << "!! Wprowadzono niepoprawne dane: "
                        << line << endl
                        << "!! Dozwolone jedynie liczby całkowite w przedziale od 0 do 10 lub "
                        << FINISH << endl;
            }else{
                break;
            }

            cout << "-- Próba " << i << " z "<<  MAX_TRIES << " nieudana! --";
        }

        if(!won) cout << endl << "PRZEGRANA! Nie Zgadł(a|e)ś! Nasza liczba to " << wylosowanaLiczba << endl << endl;

    } while ( line != FINISH );

    cout << "------------- koniec ------------" << endl;

    cout << "Wynik: " << won_rounds << " wygranych na " << total_rounds << " prób(y)" << endl;

    cout << "GoodBye!" << endl;

    return 0;
}

int validate_and_parse(string inputstr, regex input_validator_regexp){
    if(regex_match(inputstr,input_validator_regexp)){
        int guess = atoi(inputstr.c_str());
        if(guess >=0 && guess <= 10){
            return guess;
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}