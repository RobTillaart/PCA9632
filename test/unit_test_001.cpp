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
  assertEqual(PCA9632_OK         , 0x00);
  assertEqual(PCA9632_ERROR      , 0xFF);
  assertEqual(PCA9632_ERR_WRITE  , 0xFE);
  assertEqual(PCA9632_ERR_CHAN   , 0xFD);
  assertEqual(PCA9632_ERR_MODE   , 0xFC);
  assertEqual(PCA9632_ERR_REG    , 0xFB);
  assertEqual(PCA9632_ERR_I2C    , 0xFA);
}


unittest(test_constructor_pca9632)
{
  PCA9632 RGBW(0x60);

  Wire.begin();

  assertTrue(RGBW.begin());
  assertTrue(RGBW.isConnected());
}


unittest(test_constructor_pca9633)
{
  PCA9633 RGBW(0x60);

  Wire.begin();

  assertTrue(RGBW.begin());
  assertTrue(RGBW.isConnected());
}


unittest_main()


//  -- END OF FILE --
