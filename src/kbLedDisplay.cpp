#include "custom_avr.h"

// klávesnice s 4x4 maticí
volatile uint8_t nums[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xFF};
//                0       1      2     3   4     5      6     7    8     9    nic

kbLedDisp::kbLedDisp(connectorType_t connector)
{
  pickPort(connector, port_a, ddr_a, pin_a, port_b, ddr_b, pin_b);
}

void kbLedDisp::kbLedDisp_Show(uint32_t num)
{
  *ddr_a = 0xFF;
  *port_b |= (1 << 4); // zapnuti displeje

  uint8_t pos = 0;

  while (1)
  {
    uint8_t showNum = num % 10;
    *port_b |= 0x0C;
    *port_b &= ~(pos << 2);

    *port_a = nums[showNum];
    _delay_ms(1);
    *port_a = 0xFF;

    pos++;
    num /= 10;
    if (!num || pos >= 4)
      break;
  }

  _delay_ms(1);
  *port_a = 0xFF;
  *port_b &= ~(1 << 4);
}

uint8_t kbLedDisp::kbLedDisp_KeytoNumber(keytype_t key)
{

  uint8_t kb_chars[] = {0, 1, 2, 3, 10, 4, 5, 6, 11, 7, 8, 9, 12, 13, 0, 15, 16};
  return kb_chars[key];
}

uint8_t kbLedDisp::kbLedDispl_scan()
{
  *ddr_a = 0x0F;
  uint8_t row = 0;
  uint8_t col = 0;
  for (col = 0; col < 4; col++)
  {
    *port_a &= ~(0x0F);
    *port_a |= (~(1 << col) & 0x0F);
    _delay_us(5);
    for (row = 4; row < 8; row++)
    {
      if ((*pin_a & 0xF0) == (~(1 << row) & 0xF0))
      {
        *ddr_a = 0xFF;
        *port_a = 0xFF;
        return (((row - 4) * 4) + col + 1);
      }
    }
  }
  return (KEY_NOTHING);
}

uint32_t kbLedDisp::kbLedDisp_readNumber()
{
  uint8_t kb = 0;
  uint8_t pKb = 0;
  uint32_t finalNum = 0;
  ;
  while (1)
  {
    kb = kbLedDispl_scan();
    if (kb == KEY_ENTER)
      break;
    if (kb == KEY_ESC)
      finalNum = 0;

    if (kb != KEY_NOTHING && kb != pKb && kbLedDisp_KeytoNumber((keytype_t)kb) < 10)
    {
      finalNum *= 10;
      finalNum += (uint32_t)kbLedDisp_KeytoNumber((keytype_t)kb);
    }
    pKb = kb;
    kbLedDisp_Show(finalNum);
  }

  while (kbLedDispl_scan() != KEY_NOTHING)
  {
  }
  return (finalNum);
}

keytype_t kbLedDisp::kbLedDisp_readDigit()
{
  uint8_t value = 0;
  while (1)
  {
    value = kbLedDispl_scan();
    if (value != 0)
      break;
  }
  while (kbLedDispl_scan() != 0);
  return (keytype_t)value;
}