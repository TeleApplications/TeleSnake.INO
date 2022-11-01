#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Components\ButtonComponent.h"
#include "RenderComponent\RenderManager.h"
#include "Snake.h"
#include "List.h"

#define ONE_INTERATION 500


RenderComponent::IRenderable *renderComponents[1];
RenderComponent::RenderManager *renderManager;

long lastMilliseconds;

RenderComponent::DisplayInformation displayInformation;
Components::Component *currentComponents[1];

void getTestButtonAction(bool state);

void setup()
{
    Serial.begin(9600);
    //Serial.print("Setup is already done");

    pinMode(13, OUTPUT);


    auto currentSnake = new src::Snake();
    currentSnake->Position.X = 50;
    currentSnake->Position.Y = 50;

    renderComponents[0] = currentSnake;
    currentComponents[0] = new Components::ButtonComponent(getTestButtonAction, 11);

    displayInformation.width = 128;
    displayInformation.height = 64;
    displayInformation.address = 0x3C;

    renderManager = new RenderComponent::RenderManager(*renderComponents, displayInformation);
    for(int i = 0; i < 1; i++)
    {
        auto& currentComponent = *currentComponents[i];
        currentComponent.OnLoad();
    }
} 

void loop()
{ 
    (*renderManager).StartRender();
    long difference = millis() - lastMilliseconds;

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
        //Serial.println("Pressed");
        //digitalWrite(13, HIGH);
    }
    else
        digitalWrite(13, LOW);
}