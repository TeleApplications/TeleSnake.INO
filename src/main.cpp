#include <Arduino.h>
#include "Components\ButtonComponent.h"


#define ONE_INTERATION 500
Components::Component *currentComponents[1];
long lastMilliseconds;

void getTestButtonAction(bool state);


void setup()
{
    Serial.begin(9400);
    Serial.print("Setup is already done");

    pinMode(13, OUTPUT);
    currentComponents[0] = new Components::ButtonComponent(getTestButtonAction, 7);

    for(int i = 0; i < 1; i++)
    {
        auto& currentComponent = *currentComponents[i];
        currentComponent.OnLoad();
    }
} 

void loop()
{ 
    long difference = millis() - lastMilliseconds;
    Serial.write(difference);

    if(difference > ONE_INTERATION)
        lastMilliseconds = millis();

    for(int i = 0; i < 1; i++)
    {
        auto& currentComponent = *currentComponents[i];
        currentComponent.OnUpdate(difference);
    }
} 

void getTestButtonAction(bool state)
{
    if(state)
    {
        Serial.println("Pressed");
        digitalWrite(13, HIGH);
    }
    else
        digitalWrite(13, LOW);
}