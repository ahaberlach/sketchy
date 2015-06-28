/*
  Sketchy: A control system for a robotic Etch-a-Sketch

 */
 
 
int  X_DIR_PIN = 13;
int  X_STEP_PIN = 12;
 
int Y_DIR_PIN = 11;
int Y_STEP_PIN = 10;
 
// the setup routine runs once when you press reset:
void setup() {                
  pinMode(X_DIR_PIN, OUTPUT); // HIGH == to the right
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_STEP_PIN, OUTPUT);   
}


void step_motor(boolean dir, int dir_pin, int step_pin) {
  if (dir) {
    digitalWrite(dir_pin, HIGH);
  } else {
    digitalWrite(dir_pin, LOW);
  }
  digitalWrite(step_pin, HIGH);
  delay(1);
  digitalWrite(step_pin, LOW);
  delay(1);
}

void step_x(boolean dir) {
  step_motor(dir, X_DIR_PIN, X_STEP_PIN); 
}

void step_y(boolean dir) {
  step_motor(dir, Y_DIR_PIN, Y_STEP_PIN); 
}

void plot_square(int size) {
  for (int x = 0; x < size; x++) {
    step_x(true);
  }
  for (int x = 0; x < size; x++) {
    step_y(true);
  }
  for (int x = 0; x < size; x++) {
    step_x(false);
  }
  for (int x = 0; x < size; x++) {
    step_y(false);
  }
}

void loop() {
  plot_square(2000);



  while(true);
}
