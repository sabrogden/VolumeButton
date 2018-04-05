#include <RotaryEncoder.h>
#include "OneButton.h"
#include <HID-Project.h>

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
  button.attachDoubleClick(doubleClick);

  Serial.begin(9600);
  Keyboard.begin();
  Consumer.begin();
}

void loop()
{
  button.tick();
  encoder.tick();

  int newPos = encoder.getPosition();
  if (encoderPos != newPos) 
  {  
    if(encoderPos > newPos)
    { 
       Consumer.write(MEDIA_VOLUME_UP);
    }
    else
    {  
       Consumer.write(MEDIA_VOLUME_DOWN);
    }

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

  if(micMuted == 1)
  {  
      Keyboard.write(KEY_F13);
  }
  else
  {
      Keyboard.press(KEY_F14);
  }

  delay(100);
  Keyboard.releaseAll();
}

void doubleClick() 
{
  Serial.print("double click");
  Serial.println();
  
  volumeMuted = !volumeMuted;
  
  digitalWrite(5, volumeMuted);

  if(volumeMuted == 1)
  {
      Keyboard.write(KEY_F15);;

      Serial.print("sending mute volume, shift-f15");
      Serial.println();
  }
  else
  {       
      Keyboard.write(KEY_F16);

      Serial.print("sending mute volume, shift-f16");
      Serial.println();
  }

  delay(100);
  Keyboard.releaseAll();
}
