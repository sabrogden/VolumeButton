#include <RotaryEncoder.h>
#include "OneButton.h"
#include <HID-Project.h>

RotaryEncoder encoder(7, 8);
OneButton button(4, false);
OneButton muteButton(5, false);

int encoderPos = 0;

void setup() 
{  
  button.setClickTicks(250);
  button.attachClick(click);
  button.attachDoubleClick(doubleClick);
  button.attachLongPressStart(click);

  muteButton.setClickTicks(250);
  muteButton.attachClick(click);
  muteButton.attachLongPressStart(click);  

  //Serial.begin(9600);
  Keyboard.begin();
  Consumer.begin();
}

void loop()
{  
  button.tick();
  muteButton.tick();
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
    
    //Serial.print(newPos);
    //Serial.println();
    encoderPos = newPos;
  }
}

void click() 
{
  //Serial.print("click");
  //Serial.println();
      
  //teams toggle mute
 // Keyboard.press(KEY_LEFT_CTRL);
 // Keyboard.press(KEY_LEFT_SHIFT);
 // Keyboard.press('m');

  Keyboard.press(KEY_F13);
  
  delay(100);
  Keyboard.releaseAll();
}

void doubleClick() 
{

}
