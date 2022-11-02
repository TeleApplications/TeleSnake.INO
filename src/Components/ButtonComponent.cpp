#include "ButtonComponent.h"
#include <Arduino.h>
#include "Component.h"



namespace Components
{
    #define BUTTON_DELAY 50

    ButtonComponent::ButtonComponent(ButtonAction buttonAction, byte pin) : Component(pin, INPUT_PULLUP)
    {
        action = buttonAction;
    }

    void ButtonComponent::OnLoad()
    {
    }

    void ButtonComponent::OnUpdate(long difference)
    {
        long currentDifference = difference - lastDebounce;
        if(currentDifference > BUTTON_DELAY)
        {
            auto currentState = IsPressed();
            if(currentState != lastButtonState)
            {
                lastButtonState = currentState;
                lastDebounce = currentDifference;
            }
            else
                action(currentState);
        }
    }

    bool ButtonComponent::IsPressed()
    {
        return digitalRead(Pin) == HIGH;
    }
}