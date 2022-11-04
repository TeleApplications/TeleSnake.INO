#include "Component.h"


namespace Components
{

    class ButtonComponent : public Component
    {
        typedef void (*ButtonAction) (bool state, ButtonComponent* component);

        private: long lastDebounce = 0;
        private: bool lastButtonState = 0;
        private: ButtonAction action;

        public: ButtonComponent(ButtonAction buttonAction, byte pin);

        public: void OnLoad() override;

        public: void OnUpdate(long difference) override;

        public: bool IsPressed();
    };

}