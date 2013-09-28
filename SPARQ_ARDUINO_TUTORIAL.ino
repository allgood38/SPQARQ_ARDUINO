/** Reaction time competition.
 *
 * Arduino is connected to two buttons, one for each player.
 */

#define PLAYER_ONE_BUTTON 2
#define PLAYER_ONE_LIGHT 8

#define PLAYER_TWO_BUTTON 3
#define PLAYER_TWO_LIGHT 10

#define BUTTON_PRESSED 0
#define GAME_LIGHT 9

#define MAX_WAIT_TIME 5000
#define MIN_WAIT_TIME 1000

uint8_t winner = 0;

void setup() {
    Serial.begin(9600);
    pinMode( PLAYER_ONE_BUTTON, INPUT );
    pinMode( PLAYER_TWO_BUTTON, INPUT );

    pinMode( PLAYER_ONE_LIGHT, OUTPUT );
    pinMode( PLAYER_TWO_LIGHT, OUTPUT );
    pinMode( GAME_LIGHT, OUTPUT );

    randomSeed( analogRead( A0 ) );
//    digitalWrite(8, HIGH);
//    digitalWrite(9, HIGH);
//    digitalWrite(10, HIGH);
//    while( 1 ) Serial.println(digitalRead(2));
}

void loop() {

    /* Initial wait time of three seconds for players to get ready */
    for( uint8_t i = 0; i < 3; i++ ) {
        digitalWrite( GAME_LIGHT, HIGH );
        delay( 500 );
        digitalWrite( GAME_LIGHT, LOW );
        delay( 500 );
    }

    delay( random( MIN_WAIT_TIME, MAX_WAIT_TIME ) );
    digitalWrite( GAME_LIGHT, HIGH );

    while( winner == 0 ) {
        if( digitalRead(PLAYER_ONE_BUTTON) == BUTTON_PRESSED ) {
            winner = PLAYER_ONE_LIGHT;
        } else if( digitalRead( PLAYER_TWO_BUTTON ) == BUTTON_PRESSED ) {
            winner = PLAYER_TWO_LIGHT;
        }
    }

//    digitalWrite( GAME_LIGHT, LOW );
//    Serial.print("WINNER: ");
//    Serial.println(winner)
    while( 1 ) {
        digitalWrite( winner, HIGH );
        delay( 500 );
        digitalWrite( winner, LOW );
        delay( 500 );
    }
}
