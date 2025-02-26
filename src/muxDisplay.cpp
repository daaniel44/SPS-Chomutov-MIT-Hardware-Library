#include "custom_avr.h"

// 8x 7-segment display

volatile uint8_t numbers[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6, 0x01, 0x02}; // 0 - 9; 10->tečka; 11 - mínus
volatile uint8_t realPos[] = {3, 2, 1, 0, 4, 5, 6, 7};
// uint8_t realPos[] = {0, 1, 2, 3, 4, 5, 6, 7};

muxSegmentDisplay::muxSegmentDisplay(connectorType_t connector)
{
  pickPort(connector, port_a, ddr_a, pin_a, port_b, ddr_b, pin_b);
}

void muxSegmentDisplay::Set(uint8_t pos, float number, uint8_t zeros)
{
  this->dispPublicPos = pos;
  this->dispPublicNumber = number;
  this->dispPublicZeros = zeros;
}

void muxSegmentDisplay::Run()
{
  *ddr_b = 0xFF;
  *ddr_a = 0xFF;
  int64_t intCopyNumber = 0;
  float floatCopyNumber = dispPublicNumber;
  uint8_t decimals = 0;
  bool negative = false;

  // Převést záporné číslo na kladné a přiřadit negative flag
  if (floatCopyNumber < 0)
  {
    floatCopyNumber *= -1;
    negative = true;
  }

  // převést float číslo na inteeger i se všemi desetinnými místy a u toho spočítat počet desetinných míst
  while ((uint64_t)floatCopyNumber != floatCopyNumber)
  {
    floatCopyNumber *= 10;
    decimals++;
  }
  intCopyNumber = floatCopyNumber;

  // Zobrazit desetinnou tečku na správné pozici
  if (decimals > 0)
  {
    *port_b = numbers[10];
    *port_a = realPos[8 - dispPublicPos - 1 - decimals];
  }

  for (uint8_t i = 0; i < 8; i++)
  {
    // výpočet poslední číslice
    uint8_t num = intCopyNumber % 10;
    // Zjistit zda zobrazit nulu místo prázdného místa
    if (intCopyNumber != 0 || dispPublicZeros > i)
    {
      *port_b = numbers[num];
      *port_a = realPos[8 - i - dispPublicPos - 1];
    }
    // Zobrazit znaménko mínus pokud je číslo záporné
    else if (negative)
    {
      *port_b = numbers[11];
      *port_a = realPos[8 - dispPublicPos - 1 - i];
      negative = false;
    }
    intCopyNumber /= 10;
  }
  // Reset čísel
  *port_a = 0;
  *port_a = 0;
}
