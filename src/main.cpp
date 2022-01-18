#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "AccurateSonar.h"
#include "OrgasmState.h"
#include "util.h"

#define NUMBER_OF_EXCITED_SOUND 11
#define NUMBER_OF_ALMOST_SOUND 8
#define NUMBER_OF_CUMMING_SOUND 7

#define BAUD_SPEED 9600

#define DELAY 1500

SoftwareSerial mp3Serial(11, 10);
DFRobotDFPlayerMini mp3;
AccurateSonar sonar = AccurateSonar(2,3);

void initialize_df_player() {
  mp3Serial.begin(BAUD_SPEED);
  Serial.println("Booting up... (May take 3~5 seconds)");
  if (!mp3.begin(mp3Serial)) {
    Serial.println("Error during initialization.");
    while(true);
  }
  Serial.println("Sensuali di Parcheggio is now online.");
}

void setup() {
  Serial.begin(BAUD_SPEED);
  Serial.println("Sensuali di Parcheggio");
  initialize_df_player();
}

void loop() {
  int d = sonar.distance();
  if(d > 0) {
    OrgasmState s = map_from_distance(d);
    int file_name = random_orgasm(
      s,
      NUMBER_OF_EXCITED_SOUND,
      NUMBER_OF_ALMOST_SOUND,
      NUMBER_OF_CUMMING_SOUND
    );
    mp3.volume(orgasm_as_volume(s));
    mp3.play(file_name);
  }
  delay(DELAY);
}

