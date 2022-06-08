#include "ReportParser.h"

USB Usb;
USBHub  Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_MOUSE> HidMouse(&Usb);

udef_MRP prs;

void setup()
{
  prs.InitButtons();

  Serial.begin( 115200 );

  #if !defined(__MIPSEL__)
      while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  #endif

  Serial.println("[STATUS] Serial monitoring starting");

  if (Usb.Init() == -1)
      Serial.println("[ERROR] USB shield failed to init. Check device is not drawing too much power!");

  delay( 200 );

  HidMouse.SetReportParser(0, &prs);
  Mouse.begin();
}

void loop()
{

  prs.dx = 0;
  prs.dy = 0;
  prs.dz = 0;

  Usb.Task();

  Mouse.move(prs.dx, prs.dy, prs.dz);

  prs.ParseButtons();
  

}

