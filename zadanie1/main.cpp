#include <iostream>
#include <regex>


using namespace std;

int get_nearest_dividable(int number, int divisor);

int main()
{
    //char const  *FINISH = "quit";
    char const *FINISH = "quit";
    int const DIVIDABLE_BY = 3;

    string line;
    regex input_validator_regexp = regex("[0-9\\-]+",regex_constants::basic);

    do {
        cout << "Wpisz liczbę całkowitą lub '" << FINISH << "' aby zakończyć: ";
        cin >> line;

        if(regex_match(line,input_validator_regexp)){
            int base = atoi(line.c_str());

            int result = get_nearest_dividable(base, DIVIDABLE_BY);

            cout << endl << "Najbliższa liczba podzielna przez " << DIVIDABLE_BY << " to " << result << endl;
        }else if( line != FINISH){
            cerr << "!! Wprowadzono niepoprawne dane: "
                    << line << endl
                    << "!! Dozwolone jedynie liczby całkowite oraz "
                    << FINISH << endl;
        }

    } while ( line != FINISH );

    cout << "GoodBye!" << endl;

    return 0;
}


int get_nearest_dividable(int number, int divisor)
{
    // divisor*number bedzie zawsze podzielnu przez divisor, nie ma sensu szukac dalej:
    int max = divisor * number;
    for(int i=0;i<= max;i++){
        int plus = number + i;
        int minus = number - i;

        // sprawdzamy +liczba i -liczba bo ma byc 'najblizsza':
        if( (plus % divisor) == 0) return plus;
        if( (minus % divisor) == 0) return minus;
    }

    // just in case:
    return divisor*number;
}
