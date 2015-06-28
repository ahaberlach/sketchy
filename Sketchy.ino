/*
  Sketchy: A control system for a robotic Etch-a-Sketch

 */
 
 
int  X_DIR_PIN = 13;
int  X_STEP_PIN = 12;
 
int Y_DIR_PIN = 11;
int Y_STEP_PIN = 10;

char inbuffer[200];

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(19200);
  
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

void move_left(int count) {
  for (int i = 0; i < count; i++) {
    step_x(false);
  }
}

void move_right(int count) {
  for (int i = 0; i < count; i++) {
    step_x(true);
  }
}

void move_up(int count) {
  for (int i = 0; i < count; i++) {
    step_y(true);
  }
}

void move_down(int count) {
  for (int i = 0; i < count; i++) {
    step_y(false);
  }
}

void plot_square(int size) {
  move_up(size);
  move_right(size);
  move_down(size);
  move_left(size);
}

void loop() {
  if (Serial.available()) {
    byte size = Serial.readBytes(inbuffer, 200);
    // Note: this assume we got a carriage-return terminated string
    inbuffer[size-1] = 0;
    Serial.print("Buffer: ");
    Serial.println(inbuffer);
    char* command = strtok(inbuffer, " ");
    while (command != 0) {
      if (0 == strcmp(command, "xm")) {
        int count = atoi(strtok(0, " "));
        Serial.println("Going left");
        move_left(count);
      } else if (0 == strcmp(command, "xp")) {
        int count = atoi(strtok(0, " "));
        Serial.println("Going right");
        move_right(count);
      } else if (0 == strcmp(command, "yp")) {
        int count = atoi(strtok(0, " "));
        Serial.println("Going up");
        move_up(count);
      } else if (0 == strcmp(command, "ym")) {
        int count = atoi(strtok(0, " "));
        Serial.println("Going down");
        move_down(count);
      } else {
        Serial.print("Unknown command: \"");
        Serial.print(command);
        Serial.println("\"");
      }
      
      
      command = strtok(0, " ");
    }
  }
}
