#include <Windows.h>
#include <stdio.h>

#include "Window.hpp"
#include "SerialPort.hpp"

#define COFFEE_FOLDER "C:\\Users\\GLaDOS\\Desktop\\coffee_data\\"

int main()
{
  SDK::Window::Window newWindow;
  //newWindow.Create(L"coffee roaster", 200, 100);
 
  SYSTEMTIME myTime;
  GetSystemTime(&myTime);
 
  char Date[256];
  sprintf_s(Date, "%02d-%02d-%d-%02d_%02d_%02d", myTime.wMonth, myTime.wDay, myTime.wYear, myTime.wHour, myTime.wMinute, myTime.wSecond);
  
  char Variety[] = "Eteopia";

  char Filename[MAX_PATH];
  sprintf_s(Filename, "%s%s-%s", COFFEE_FOLDER, Variety, Date);

#ifndef _DEBUG
  HANDLE outFile = CreateFile(Filename, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, 0, 0);
#endif// _DEBUG
  DWORD last_err = GetLastError();
  SerialPort comPort("COM3");
  comPort.SetCOMState(CBR_19200);
  
  const int numDegrees = 10;
  char buffer[8 * numDegrees + 1] = {};
  do {
    DWORD numBytesRead = comPort.Read(buffer, sizeof(buffer) - 1);
    if (numBytesRead > 0)
    {
      printf("%s", buffer);
#ifndef _DEBUG
      WriteFile(outFile, buffer, numBytesRead, nullptr, nullptr);
#endif
    }
  } while (TRUE);
}
