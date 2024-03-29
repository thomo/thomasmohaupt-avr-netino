/* Arduino SdFat Library
 * Copyright (C) 2010 by William Greiman
 *
 * This file is part of the Arduino SdFat Library
 *
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Arduino SdFat Library.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * 2011-01-07	removed redundant definition of pins and using those of
 *		pins_arduino.c by M.Maassen <mic.maassen@gmail.com>
 */
// Warning this file was generated by a program.
#ifndef Sd2PinMap_h
#define Sd2PinMap_h
// this file contains all we need
#if ARDUINO < 100
#include <pins_arduino.h>
#else
#include <Arduino.h>
#endif
// Two Wire (aka I2C) ports
//uint8_t const SDA_PIN = 20;
//uint8_t const SCL_PIN = 21;

// SPI port
uint8_t const SS_PIN = SS;
uint8_t const MOSI_PIN = MOSI;
uint8_t const MISO_PIN = MISO;
uint8_t const SCK_PIN = SCK;
//------------------------------------------------------------------------------
#if defined(NUM_DIGITAL_PINS)		/* arduino >= 1.0 */
static const uint8_t digitalPinCount = NUM_DIGITAL_PINS;
#elif defined(BOARD_DEF)		/* avrnetio core */
static const uint8_t digitalPinCount = NOT_A_PIN;
#else
static const uint8_t digitalPinCount = (
	(digital_pin_to_timer_PGM-digital_pin_to_bit_mask_PGM) == 
	(digital_pin_to_bit_mask_PGM-digital_pin_to_port_PGM) ? 
	(digital_pin_to_bit_mask_PGM-digital_pin_to_port_PGM) : 0);
#endif
uint8_t badPinNumber(void)
  __attribute__((error("Pin number is too large or not a constant")));

static inline __attribute__((always_inline))
  uint8_t getPinMode(uint8_t pin) {
  if (__builtin_constant_p(pin) && pin < digitalPinCount) {
    //return (*digitalPinMap[pin].ddr >> digitalPinMap[pin].bit) & 1;
    return (*(portModeRegister(digitalPinToPort(pin))) & digitalPinToBitMask(pin)) ? 1 : 0;
  } else {
    return badPinNumber();
  }
}
static inline __attribute__((always_inline))
  void setPinMode(uint8_t pin, uint8_t mode) {
  if (__builtin_constant_p(pin) && pin < digitalPinCount) {
    if (mode) {
      //*digitalPinMap[pin].ddr |= 1 << digitalPinMap[pin].bit;
      *(portModeRegister(digitalPinToPort(pin))) |= digitalPinToBitMask(pin);
    } else {
      //*digitalPinMap[pin].ddr &= ~(1 << digitalPinMap[pin].bit);
      *(portModeRegister(digitalPinToPort(pin))) &= ~digitalPinToBitMask(pin);
    }
  } else {
    badPinNumber();
  }
}
static inline __attribute__((always_inline))
  uint8_t fastDigitalRead(uint8_t pin) {
  if (__builtin_constant_p(pin) && pin < digitalPinCount) {
    //return (*digitalPinMap[pin].pin >> digitalPinMap[pin].bit) & 1;
    return (*(portInputRegister(digitalPinToPort(pin))) & digitalPinToBitMask(pin)) ? 1 : 0;
  } else {
    return badPinNumber();
  }
}
static inline __attribute__((always_inline))
  void fastDigitalWrite(uint8_t pin, uint8_t value) {
  if (__builtin_constant_p(pin) && pin < digitalPinCount) {
    if (value) {
      //*digitalPinMap[pin].port |= 1 << digitalPinMap[pin].bit;
      *(portOutputRegister(digitalPinToPort(pin))) |= digitalPinToBitMask(pin);
    } else {
      //*digitalPinMap[pin].port &= ~(1 << digitalPinMap[pin].bit);
      *(portOutputRegister(digitalPinToPort(pin))) &= ~digitalPinToBitMask(pin);
    }
  } else {
    badPinNumber();
  }
}
#endif  // Sd2PinMap_h
