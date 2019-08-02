#include "SerialPort.hpp"

#include <assert.h>
#include <stdio.h>

namespace
{
  void PrintCommState(DCB dcb)
  {
    //  Print some of the DCB structure values
    printf("BaudRate = %d, ByteSize = %d, Parity = %d, StopBits = %d\r\n",
      dcb.BaudRate,
      dcb.ByteSize,
      dcb.Parity,
      dcb.StopBits);
  }
}

SerialPort::SerialPort(std::string_view comPortName)
{
  serialPort = CreateFileA(comPortName.data(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0);
  if (serialPort == INVALID_HANDLE_VALUE)
  {
    DWORD err = GetLastError();
    assert(err == 0);
  }
}

SerialPort::~SerialPort()
{
  if (INVALID_HANDLE_VALUE != serialPort)
  {
    CloseHandle(serialPort);
  }
}

void SerialPort::SetCOMState(DWORD baudRate)
{
  DCB dcb;
  SecureZeroMemory(&dcb, sizeof(DCB));
  dcb.DCBlength = sizeof(DCB);

  GetCommState(serialPort, &dcb);

  dcb.BaudRate = baudRate;
  dcb.ByteSize = 8;             //  data size, xmit and rcv
  dcb.Parity = NOPARITY;      //  parity bit
  dcb.StopBits = ONESTOPBIT;    //  stop bit
  SetCommState(serialPort, &dcb);

  DCB dcb2;
  GetCommState(serialPort, &dcb2);
  //assert(0 == memcmp(&dcb, &dcb2, sizeof(DCB)));
}

DWORD SerialPort::Read(void* data, size_t data_size)
{
  OVERLAPPED ov = {};
  DWORD numBytesRead = 0;
  BOOL errOccurred = FALSE;
  memset(data, 0, data_size);
  BOOL ret = ReadFile(serialPort, data, static_cast<DWORD>(data_size), nullptr, &ov);
  if (ret != TRUE)
  {
    DWORD err = GetLastError();
    assert(err == ERROR_IO_PENDING);
  }
  GetOverlappedResult(serialPort, &ov, &numBytesRead, TRUE);
  
  DWORD err = GetLastError();
  assert(err == 0);

  return numBytesRead;
}
