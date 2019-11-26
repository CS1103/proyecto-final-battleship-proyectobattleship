#include "game_setup.h"
#include "handshakephase.h"

int main() {
    string username, input_directory, output_directory, temp_directory;

    //pre-setup
    game_setup(username, input_directory, output_directory, temp_directory);

    //program begins
    //handshake phase
    handshake(username, input_directory, output_directory, temp_directory);

    //if handshake successful, begin placefleet phase
    placefleet();

    //when placefleet completes, proceed to attack phase until win, loss or tie

    attackuntilend();


}