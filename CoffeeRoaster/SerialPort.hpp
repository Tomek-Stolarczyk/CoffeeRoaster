#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <string_view>

class SerialPort
{
public:
  SerialPort(std::string_view comPortName);
  ~SerialPort();
  void SetCOMState(DWORD baudRate);

  DWORD Read(void* data, size_t data_size);

private:
  HANDLE serialPort = INVALID_HANDLE_VALUE;
};


