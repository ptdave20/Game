#include "config.h"
#include <iostream>
#include "MainEngine.h"
using namespace std;

int main(int argc, char* argv[]) {
    cout << "Version " << game_VERSION_MAJOR << "." << game_VERSION_MINOR << endl;
    MainEngine game;
    game.run();
    return 0;
}
