#ifndef MBIT_MORE_COMMON_H
#define MBIT_MORE_COMMON_H

enum ScratchBLECommand
{
  CMD_PIN_CONFIG = 0x80,
  CMD_DISPLAY_TEXT = 0x81,
  CMD_DISPLAY_LED = 0x82,
  CMD_PROTOCOL = 0x90,
  CMD_PIN = 0x91,
  CMD_SHARED_DATA = 0x92,
  CMD_LIGHT_SENSING = 0x93
};

enum MbitMorePinCommand
{
  SET_OUTPUT = 0x01,
  SET_PWM = 0x02,
  SET_SERVO = 0x03,
  SET_PULL = 0x04,
  SET_EVENT = 0x05,
  SET_TOUCH = 0x06,
};

enum MbitMorePinMode
{
  MbitMorePullNone = 0,
  MbitMorePullUp = 1,
  MbitMorePullDown = 2,
};

enum MbitMoreDataFormat
{
  MIX_01 = 0x01,
  MIX_02 = 0x02,
  MIX_03 = 0x03,
  BUTTON_EVENT = 0x11,
  EVENT = 0x12,
  SHARED_DATA = 0x13
};

enum MMButtonEvent
{
  DOWN = 1,
  UP = 2,
  CLICK = 3,
  LONG_CLICK = 4,
  HOLD = 5,
  DOUBLE_CLICK = 6
};

enum MbitMorePinEventType
{
  NONE = 0,
  ON_EDGE = 1,
  ON_PULSE = 2,
  ON_TOUCH = 3
};

#endif // MBIT_MORE_COMMON_H