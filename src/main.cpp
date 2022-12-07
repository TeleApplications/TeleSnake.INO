#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Components\ButtonComponent.h"
#include "RenderComponent\RenderManager.h"
#include "RenderComponent\Components\Snake\Snake.h"
#include "RenderComponent\Components\Food\Food.h"
#include "Vector2.h"

#define ONE_INTERATION 500
long lastMilliseconds;


RenderComponent::IRenderable *renderComponents[1];
RenderComponent::RenderManager *renderManager;

RenderComponent::DisplayInformation displayInformation = RenderComponent::DisplayInformation(128, 64, 0x3C);

Components::Component *currentComponents[4];
src::Snake *currentSnake = new src::Snake();

void getTestButtonAction(bool state, Components::ButtonComponent* component);

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);

    currentSnake->Position.X = 50;
    currentSnake->Position.Y = 50;
    renderComponents[0] = currentSnake;

    currentComponents[0] = new Components::ButtonComponent(getTestButtonAction, 3);
    currentComponents[1] = new Components::ButtonComponent(getTestButtonAction, 4);
    currentComponents[2] = new Components::ButtonComponent(getTestButtonAction, 6);
    currentComponents[3] = new Components::ButtonComponent(getTestButtonAction, 8);

    renderManager = new RenderComponent::RenderManager(*renderComponents, displayInformation);
    for(int i = 0; i < 4; i++)
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

    for(int i = 0; i < 4; i++)
    {
        auto& currentComponent = *currentComponents[i];
        currentComponent.OnUpdate(difference);
    }
        digitalWrite(13, LOW);
} 

void getTestButtonAction(bool state, Components::ButtonComponent* component)
{
    if(component->Pin == 3 && state)
    {
        digitalWrite(13, HIGH);
        currentSnake->Direction = src::Vector2::Left();
        Serial.println("Left");
    }

    if(component->Pin == 6 && !state)
    {
        digitalWrite(13, HIGH);
        currentSnake->Direction = src::Vector2::Down();
        Serial.println("Down");
    }

    if(component->Pin == 4 && !state)
    {
        digitalWrite(13, HIGH);
        currentSnake->Direction = src::Vector2::Up();
        Serial.println("Up");
    }

    if(component->Pin == 8 && state)
    {
        digitalWrite(13, HIGH);
        currentSnake->Direction = src::Vector2::Right();
        Serial.println("Right");
    }
}