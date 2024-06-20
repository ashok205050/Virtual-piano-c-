#include <iostream>
#include <windows.h> // For Sleep function
#include <conio.h>  // For _kbhit and _getch functions

class piano {
public:
    int BIGKEY, MIDKEY, back, border;
    piano() {
        BIGKEY = 15;
        MIDKEY = 1;
        back = 7;
        border = 15;
    }
};

piano color;

void setupscreen();
void check_keys(int x, int y);

float freq[7] = { 130.81, 146.83, 164.81, 174.61, 196, 220, 246.94 };
int a = 4, backcolor = 2, exitcode = 1;

int main() {
    int x, y, key;
    char ch;
    setupscreen();
    exitcode = 1;
    while (exitcode) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) break;  // ESC key to exit
            if (ch == 75) a--;    // Left arrow key
            if (ch == 77) a++;    // Right arrow key
            check_keys(x, y);
            switch (ch) {
                case 'a': case 'A': key = 0; break;
                case 's': case 'S': key = 1; break;
                case 'd': case 'D': key = 2; break;
                case 'f': case 'F': key = 3; break;
                case 'j': case 'J': key = 4; break;
                case 'k': case 'K': key = 5; break;
                case 'l': case 'L': key = 6; break;
                default: key = -1; break;
            }
            if (key != -1) {
                Beep(static_cast<DWORD>(freq[key] * a), 500);  // Beep with a frequency
                Sleep(500);  // Delay for half a second
            }
        }
    }
    return 0;
}

void setupscreen() {
    system("cls");  // Clear console screen (Windows specific)
    std::cout << "   Range\n\n";
    std::cout << "    " << a << "\n\n";
    std::cout << "    VIRTUAL PIANO\n";
}

void check_keys(int x, int y) {
    if (x == 7 && y == 4) a++;
    if (x == 3 && y == 4) a--;
    if (a < 1) a = 1;
    else if (a > 30) a = 30;
    system("cls");  // Clear console screen (Windows specific)
    std::cout << "   Range\n\n";
    std::cout << "    " << a << "\n\n";
    std::cout << "    VIRTUAL PIANO\n";
    if (x >= 69 && y >= 4 && x <= 74 && y <= 4) exitcode = 0;
}
