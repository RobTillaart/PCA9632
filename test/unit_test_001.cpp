//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2024-11-25
// PURPOSE: unit tests for the PCA9632 I2C LED driver
//          https://github.com/RobTillaart/PCA9632
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)


#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "PCA9632.h"


unittest_setup()
{
  fprintf(stderr, "PCA9632_LIB_VERSION: %s\n", (char *) PCA9632_LIB_VERSION);
}


unittest_teardown()
{
}


unittest(test_constants)
{
  fprintf(stderr, "\nerrorcodes");
  assertEqual(PCA963X_OK         , 0x00);
  assertEqual(PCA963X_ERROR      , 0xFF);
  assertEqual(PCA963X_ERR_WRITE  , 0xFE);
  assertEqual(PCA963X_ERR_CHAN   , 0xFD);
  assertEqual(PCA963X_ERR_MODE   , 0xFC);
  assertEqual(PCA963X_ERR_REG    , 0xFB);
  assertEqual(PCA963X_ERR_I2C    , 0xFA);
}


unittest(test_constructor)
{
  PCA9632 RGBW(0x20);

  Wire.begin();

  assertTrue(RGBW.begin());
  assertTrue(RGBW.isConnected());
}


unittest_main()


//  -- END OF FILE --
