#ifndef MBIT_MORE_DEVICE_H
#define MBIT_MORE_DEVICE_H

#include "pxt.h"

#if MICROBIT_CODAL

#include "MicroBitConfig.h"

#if CONFIG_ENABLED(DEVICE_BLE)

#include "MbitMoreCommon.h"
#include "MbitMoreService.h"
#include "MicroBit.h"

class MbitMoreService;

/**
 * Class definition for the Scratch basic Service.
 * Provides a BLE service for default extension of micro:bit in Scratch3.
 */
class MbitMoreDevice {
private:
  /**
   * Constructor.
   * Create a representation of default extension for Scratch3.
   * @param _uBit The instance of a MicroBit runtime.
   */
  MbitMoreDevice(MicroBit &_uBit);

  /**
   * @brief Destroy the MbitMoreDevice object
   *
   */
  ~MbitMoreDevice();

public:
  MbitMoreDevice(const MbitMoreDevice &) = delete;
  MbitMoreDevice &operator=(const MbitMoreDevice &) = delete;
  MbitMoreDevice(MbitMoreDevice &&) = delete;
  MbitMoreDevice &operator=(MbitMoreDevice &&) = delete;

  static MbitMoreDevice &getInstance() {
    static MbitMoreDevice instance(pxt::uBit);
    return instance;
  }

  MicroBit &uBit;

  /**
   * @brief BLE service for basic micro:bit extension.
   *
   */
  MbitMoreService *basicService;

  /**
   * @brief BLE service for Microbit More extension.
   *
   */
  MbitMoreService *moreService;

  // Sending data to Scratch3.
  uint8_t txBuffer[20];

  // Recieving buffer from Scratch3.
  uint8_t rxBuffer[10];

  // Config buffer set by Scratch.
  uint8_t eventBuffer[20];

  // Sending data of IO to Scratch.
  uint8_t ioBuffer[4];

  // Sending data of analog input to Scratch.
  uint8_t analogInBuffer[20];

  // Sending data of all sensors to Scratch.
  uint8_t sensorsBuffer[20];

  // Shared data with Scratch.
  uint8_t sharedBuffer[20];

  // ---------------------

  // Button events for Scratch.
  uint8_t buttonEvent[6];

  /**
   * Hold gesture state until next nofification.
   */
  int gesture;

  /**
   * Save the last accelerometer values to conpaire current for detecting
   * moving.
   */
  int lastAcc[3];

  /**
   * Heading angle of compass.
   */
  int compassHeading;

  uint32_t digitalValues;

  uint16_t analogValues[6];

  /**
   * Light level value from 0 to 255.
   */
  int lightLevel;

  // Duration for sensing of light level.
  int lightSensingDuration;

  /**
   * Acceleration value [x, y, z] in milli-g.
   */
  int acceleration[6];

  /**
   * Rotation value [pitch, roll] in radians.
   */
  float rotation[2];

  /**
   * Magnetic force [x, y, z] in 1000 * micro-teslas.
   */
  int magneticForce[3];

  /**
   * Shared data
   */
  int16_t sharedData[4];

  /**
   * Protocol of microbit more.
   */
  int mbitMoreProtocol;

  /**
   * Current mode of all pins.
   */
  PullMode pullMode[21];

  void initConfiguration();

  /**
   * @brief Layer pattern on LED.
   *
   * @param pattern Matrix to display 5 columns x 5 rows.
   * @param brightness Brightness level (0-255) of this layer.
   */
  void layerPattern(uint8_t *pattern, uint8_t brightness);

  /**
   * @brief Display symbol on LED.
   *
   * @param pattern Matrix to display 5 columns x 5 rows.
   */
  void displayPattern(uint8_t *pattern);

  /**
   * @brief Display text on LED.
   *
   * @param text Contents to display with null termination.
   * @param delay The time to delay between characters, in milliseconds.
   */
  void displayText(char *text, int delay);

  /**
   * Set value to Slots.
   */
  void setSharedData(int index, int value);

  /**
   * Get value to Slots.
   */
  int getSharedData(int index);

  void onBLEConnected(MicroBitEvent _e);

  void onBLEDisconnected(MicroBitEvent _e);

  /**
   * Callback. Invoked when a pin event sent.
   */
  void onPinEvent(MicroBitEvent evt);

  void update();

  void updateDigitalValues();
  void updateAnalogValues();
  void updateLightSensor();
  void updateAccelerometer();
  void updateMagnetometer();

  void notifySharedData();
  void notifyBasicData();
  void notify();

  void writeAnalogIn();
  void writeSensors();
  void writeSharedData();

  void displayFriendlyName();

private:
  void listenPinEventOn(int pinIndex, int eventType);
  void setPullMode(int pinIndex, PullMode pull);
  void setDigitalValue(int pinIndex, int value);
  void setAnalogValue(int pinIndex, int value);
  void setServoValue(int pinIndex, int angle, int range, int center);
  void setPinModeTouch(int pinIndex);
  void setLightSensingDuration(int duration);
  void composeBasicData(uint8_t *buff);

  void onButtonChanged(MicroBitEvent);
  void onGestureChanged(MicroBitEvent);

  void updateGesture(void);
  void resetGesture(void);

  int normalizeCompassHeading(int heading);
  int convertToTilt(float radians);
};

#endif // CONFIG_ENABLED(DEVICE_BLE)
#endif // MICROBIT_CODAL
#endif // MBIT_MORE_DEVICE_H