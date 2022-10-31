#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "RenderManager.h"

#define RESET_PIN -1
#define ONE_FRAME 150 

namespace RenderComponent
{
    RenderManager::RenderManager(RenderComponent::IRenderable *components, DisplayInformation information)
    {
        Serial.println("Render was created");
        this->currentComponenets = components;
        this->currentDisplay = Adafruit_SSD1306(Information.width, Information.height, &Wire, RESET_PIN);
        this->Information = information;

        currentDisplay.begin(SSD1306_SWITCHCAPVCC, Information.address);
    }

    //The returned value is will be changed as
    //soon as possible
    bool RenderManager::StartRender()
    {
        Serial.println("Render had already begun");
        long currentMillis = millis();
        long difference = currentMillis - lastRefresh;

        if(difference >= (ONE_FRAME))
        {
            lastRefresh = currentMillis;
            currentDisplay.clearDisplay();
            RenderComponents(currentComponenets);
            currentDisplay.display();
        }

        return true;
    }

    void RenderManager::RenderComponents(RenderComponent::IRenderable *components)
    {
        //int componentsLength = sizeof(components) / sizeof(IRenderable);
        for (int i = 0; i < 1; i++)
        {
            auto& currentComponent = components[i];
            currentComponent.OnRender(currentDisplay);
        }
    }
}
