#include "PinLayout.h"
#include "Updateable.h"

#include "max6675.h"

template<const DigitalPin SO, const DigitalPWNPin CS, const DigitalPWNPin CLK>
class Thermocouple : public Updateable
{
  public:
    Thermocouple();
    const double GetTempurature() const;
    void Update() override;

  private:
    MAX6675 sensor;
    double tempurature = 0;
};
