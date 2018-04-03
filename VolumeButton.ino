#include <RotaryEncoder.h>
#include "Keyboard.h"
#include "OneButton.h"

RotaryEncoder encoder(8, 9);
OneButton button(4, false);

int micMuted = 0;
int volumeMuted = 0;
int encoderPos = 0;

void setup() 
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  button.setClickTicks(500);
  button.attachClick(click);
  button.attachDoubleClick(doubleclick);

  Serial.begin(9600);

  Keyboard.begin();
}

void loop()
{
  button.tick();
  encoder.tick();

  int newPos = encoder.getPosition();
  if (encoderPos != newPos) 
  {
    Keyboard.press(KEY_LEFT_SHIFT);     
    Keyboard.press(KEY_LEFT_CTRL);     
    Keyboard.press(KEY_LEFT_ALT);   
  
    if(encoderPos > newPos)
    { 
      Keyboard.press(KEY_F1);
    }
    else
    {  
      Keyboard.press(KEY_F2);      
    }

    delay(100);
    Keyboard.releaseAll();

    // changing the volume un mutes
    volumeMuted = 0;  
    digitalWrite(5, volumeMuted);
    
    Serial.print(newPos);
    Serial.println();
    encoderPos = newPos;
  }
}

void click() 
{
  Serial.print("click");
  Serial.println();
  
  micMuted = !micMuted;
  
  digitalWrite(6, micMuted);

  Keyboard.press(KEY_LEFT_SHIFT);     
  Keyboard.press(KEY_LEFT_CTRL);     
  Keyboard.press(KEY_LEFT_ALT);     

  if(micMuted == 1)
  {  
      Keyboard.press(KEY_F3);
  }
  else
  {
      Keyboard.press(KEY_F4);
  }

  delay(100);
  Keyboard.releaseAll();
}

void doubleclick() 
{
  Serial.print("double click");
  Serial.println();
  
  volumeMuted = !volumeMuted;
  
  digitalWrite(5, volumeMuted);

  Keyboard.press(KEY_LEFT_SHIFT);     
  Keyboard.press(KEY_LEFT_CTRL);     
  Keyboard.press(KEY_LEFT_ALT);   

  if(volumeMuted == 1)
  {
      Keyboard.press(KEY_F5);

      Serial.print("sending mute volume, shift-f3");
      Serial.println();
  }
  else
  {   
      Keyboard.press(KEY_F6);

      Serial.print("sending mute volume, shift-f3");
      Serial.println();
  }

  delay(100);
  Keyboard.releaseAll();
}
