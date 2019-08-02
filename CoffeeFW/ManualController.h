#include "Updateable.h"
#include "PinLayout.h"

template <const AnalogPin EnablePin, const AnalogPin ValuePin>
class ManualController : public Updateable
{
  public:
    const bool IsOverrideEnabled() const;
    const unsigned int GetOverrideValue() const;
    void Update() override;

  private:
    bool enabled = false;
    unsigned int value = 0;
};


static ManualController<Pins::kManualControllerEnable, 
                        Pins::kManualControllerValue> g_Controller;
