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
Components::Component *currentComponents[2];
src::Snake *currentSnake;

void getTestButtonAction(bool state, Components::ButtonComponent* component);

void setup()
{
    Serial.begin(9600);
    //Serial.print("Setup is already done");

    pinMode(13, OUTPUT);


    currentSnake = new src::Snake();
    currentSnake->Position.X = 50;
    currentSnake->Position.Y = 50;

    renderComponents[0] = currentSnake;
    currentComponents[0] = new Components::ButtonComponent(getTestButtonAction, 11);
    currentComponents[1] = new Components::ButtonComponent(getTestButtonAction, 10);

    displayInformation.width = 128;
    displayInformation.height = 64;
    displayInformation.address = 0x3C;

    renderManager = new RenderComponent::RenderManager(*renderComponents, displayInformation);
    for(int i = 0; i < 2; i++)
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

    for(int i = 0; i < 2; i++)
    {
        auto& currentComponent = *currentComponents[i];
        currentComponent.OnUpdate(difference);
    }
} 

void getTestButtonAction(bool state, Components::ButtonComponent* component)
{
    if(component->Pin == 10 && state)
    {
        digitalWrite(13, LOW);
        currentSnake->Direction = src::Vector2::Down();
    }
    if(component->Pin == 11 && state)
    {
        digitalWrite(13, HIGH);
        currentSnake->Direction = src::Vector2::Right();
    }
    if(component->Pin == 9 && state)
    {
        currentSnake->Direction = src::Vector2::Up();
    }
    if(component->Pin == 8 && state)
    {
        currentSnake->Direction = src::Vector2::Down();
    }
}