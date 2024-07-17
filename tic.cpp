#include <iostream>
#include <ctime>
using namespace std;

void drawBoard(char *arr) {
    cout<<endl;

    cout<<"     |     |     "<<endl;
    cout<<"  " << arr[0] << "  |   " << arr[1] << " |   " << arr[2] << "  "<<endl;
    cout<<"_____|_____|_____"<<endl;

    cout<<"     |     |     "<<endl;
    cout<<"  " << arr[3] << "  |   " << arr[4] << " |   " << arr[5] << "  "<<endl;
    cout<<"_____|_____|_____"<<endl;

    cout<<"     |     |     "<<endl;
    cout<<"  " << arr[6] << "  |   " << arr[7] << " |   " << arr[8] << "  "<<endl;

    cout<<endl;
}

void playerMove(char *arr, char user) {
    int n;
    do {
        cout<<"Enter a spot for marker from 1 to 9 : ";
        cin>>n;
        n--;
        if(arr[n] == ' ') {
            arr[n] = user;
            break;
        }
    }while(!n>0  ||  !n < 8);
}

void computerMove(char *arr, char computer) {
    int n;
    srand(time(0));

    while(true) {
        n = rand() % 9;
        if(arr[n] == ' ') {
            arr[n] = computer;
            break;
        }
    }
}

bool Winner(char *arr, char user, char computer) {
    if((arr[0] != ' ') && (arr[0] == arr[1]) && (arr[1] == arr[2])) {
        arr[0] == user ? cout<<"YOU WIN!\n" : cout<<"COMPUTER WIN!\n"; return true;
    }

    else if((arr[3] != ' ') && (arr[3] == arr[4]) && (arr[4] == arr[5])) {
        arr[3] == user ? cout<<"YOU WIN!\n" : cout<<"COMPUTER WIN!\n"; return true;
    }

    else if((arr[6] != ' ') && (arr[6] == arr[7]) && (arr[7] == arr[8])) {
        arr[6] == user ? cout<<"YOU WIN!\n" : cout<<"COMPUTER WIN!\n"; return true;
    }

    else if((arr[0] != ' ') && (arr[0] == arr[3]) && (arr[3] == arr[6])) {
        arr[0] == user ? cout<<"YOU WIN!\n" : cout<<"COMPUTER WIN!\n"; return true;
    }

    else if((arr[1] != ' ') && (arr[1] == arr[4]) && (arr[4] == arr[7])) {
        arr[1] == user ? cout<<"YOU WIN!\n" : cout<<"COMPUTER WIN!\n"; return true;
    }

    else if((arr[2] != ' ') && (arr[2] == arr[5]) && (arr[5] == arr[8])) {
        arr[2] == user ? cout<<"YOU WIN!\n" : cout<<"COMPUTER WIN!\n"; return true;
    }

    else if((arr[0] != ' ') && (arr[0] == arr[4]) && (arr[4] == arr[8])) {
        arr[0] == user ? cout<<"YOU WIN!\n" : cout<<"COMPUTER WIN!\n"; return true;
    }

    else if((arr[2] != ' ') && (arr[2] == arr[4]) && (arr[4] == arr[6])) {
        arr[2] == user ? cout<<"YOU WIN!\n" : cout<<"COMPUTER WIN!\n"; return true;
    }

    else {
        return false;
    }

    return true;
}

bool Tie(char *arr) {
    for(int i = 0; i < 9; i++) {
        if(arr[i] == ' ') {
            return false;
        }
    }

    cout<<"IT IS A TIE\n";
    return true;
}

int main() {
    char arr[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char user = 'X';
    char computer = 'O';
    bool flag = true;

    drawBoard(arr);

    while(flag) {
        playerMove(arr, user);
        drawBoard(arr);
        if(Winner(arr, user, computer)) {
            flag = false;
            break;
        }
        else if(Tie(arr)) {
            flag = false;
            break;
        }

        computerMove(arr, computer);
        drawBoard(arr);
        if(Winner(arr, user, computer)) {
            flag = false;
            break;
        }
        else if(Tie(arr)) {
            flag = false;
            break;
        }
    }

    cout<<"Thanks for playing!!";
    return 0;
}