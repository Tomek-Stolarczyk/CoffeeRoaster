#ifndef MANUALCONTROLLER_H
#define MANUALCONTROLLER_H

#include "PinLayout.hpp"
#include "Updateable.hpp"

Updateable* CreateManualController();

template <AnalogPin EnablePin, AnalogPin ValuePin>
class ManualController : public Updateable
{
  public:
    ManualController() = default;
    virtual ~ManualController() = default;
    
    bool const IsOverrideEnabled() const;
    uint32_t const GetOverrideValue() const;
    void Update() noexcept override;

  private:
    bool m_enabled{ false };
    uint32_t m_value{ 0 };
};

#endif