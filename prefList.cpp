#include<iostream>
#include<string>
#include<cctype>
#include<stdio.h>
#include<limits>

using namespace std;

const string CHORES[] = {"Dishes", "Trash", "Sweep", "Berkeley", "Tables", "Mop"};
const string ROOMIES[] = {"Ariana", "Chris", "Gretchen", "Jake", "John", "Oscar"};
const unsigned short int N_CHORES = sizeof(CHORES)/sizeof(*CHORES);
const unsigned short int N_PPL = sizeof(ROOMIES)/sizeof(*ROOMIES);

void printChores(){
    for (int i=0; i < N_CHORES; i++){
        cout << i+1 << " --> " << CHORES[i] << "\n";
    }
}

void printPrompt(int j){
    if (j == 0)
        printf("%-11s", "Favorite:");
    else { 
        if (j == 1)
            printf("%d%-10s",j+1,"nd:");
        else if (j == 2) printf("%d%-10s",j+1,"rd:");
        else printf("%d%-10s",j+1,"th:");
    }
}

bool isAvaliable(unsigned short int a, int who, int choiceNumber,  unsigned short int choices[N_PPL][N_CHORES]){

    for (int i = 0; i < choiceNumber; i++){
        if (choices[who][i] == a-1){
            cout << "You have already selected " << CHORES[a-1] << ". Please select a different chore.\n";
            return false;
        }
    }
    return true;
}

bool isValid(int a){
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (!(1 <= a && a <= 6)){
        cout << "Please enter a valid number (1-6)\n";
        return false;
    }
    return true;
}

void showChoices(int who, 
        unsigned short int prefChores[N_PPL][N_CHORES]){
    for (int i=0 ; i<N_CHORES ; i++){
        printPrompt(i);
        cout << CHORES[prefChores[who][i]] << "\n";
    }

}

bool isValid(char a){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (cin.fail()){
        cin.clear();
    }
    if (!( tolower(a) == 'y' || tolower(a) == 'n' )){
        cout << "Please enter a valid character (y/n)\n";
        return false;
    }
  return true;
}
void getPrefChores(unsigned short int prefChores[N_PPL][N_CHORES]){
    for (int i=0; i < N_PPL; i++){
        cout << "Hello, " << ROOMIES[i] << ". Enter the number corresponding to the chore.\n";
        bool correct;
        do{
            printChores();
            for (int j=0; j < N_CHORES; j++){
                int a;
                do{
                    printPrompt(j);
                    cin >> a;

                }while(!(isValid(a) && isAvaliable(a,i,j,prefChores) ));
                prefChores[i][j] = a-1;
            }
            cout << "Here are your choices: \n";
            showChoices(i,prefChores);
            char a;
            do{
                cout << "is this correct (y/n)? ";
                cin >> a;
            }while (!isValid(a));
            if (tolower(a) == 'n'){
                cout << "Okay, let's start over!\n";
                correct = false;
            } else {
                cout << "You're all set!\n\n";
                correct=true;
            }
        }while(!correct);
    }
}

int main(){
    unsigned short int prefChores[N_PPL][N_CHORES];
    getPrefChores(prefChores);
    return 0;
}
