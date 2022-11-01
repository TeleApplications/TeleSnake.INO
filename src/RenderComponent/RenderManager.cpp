#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "RenderManager.h"

#define RESET_PIN -1
#define ONE_FRAME 450 

namespace RenderComponent
{
    RenderManager::RenderManager(RenderComponent::IRenderable components[], DisplayInformation information)
    {
        Serial.println("Render was created");
        int componentsLength = sizeof(components);
        Serial.println(componentsLength);
        this->currentComponenets = components;
        this->currentDisplay = Adafruit_SSD1306(Information.width, Information.height, &Wire, RESET_PIN);
        this->Information = information;

        currentDisplay.begin(SSD1306_SWITCHCAPVCC, Information.address);
    }

    //The returned value is will be changed as
    //soon as possible
    bool RenderManager::StartRender()
    {
        long currentMillis = millis();
        long difference = currentMillis - lastRefresh;

        //Serial.println(difference);
        if(difference >= (ONE_FRAME))
        {
            lastRefresh = currentMillis;
            currentDisplay.clearDisplay();

            Serial.println("Render was created");
            (&currentComponenets)[0]->OnRender(currentDisplay);
            //RenderComponents(currentComponenets);
            currentDisplay.display();
        }

        return true;
    }

    void RenderManager::RenderComponents(RenderComponent::IRenderable components[])
    {
        for (int i = 0; i < 2; i++)
        {
            auto& currentComponent = components[i];
            currentComponent.OnRender(currentDisplay);
        }
    }
}
