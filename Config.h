#ifndef CONFIG_H
#define CONFIG_H

#if defined(_WIN32)
// Windows setting
#define CONFIG_FPS 30
#define CONFIG_WIDTH 80
#define CONFIG_HEIGHT 64
#define CONFIG_TITLE L"KemonoRogue"

#elif defined(ARDUINO_SAMD_ZERO) && defined(CRYSTALLESS) && defined(USBCON)
// TinyArcade/PocketArcade setting
#define CONFIG_FPS 30

#elif defined(ADAFRUIT_PYBADGE_M4_EXPRESS) || defined(ADAFRUIT_PYGAMER_M4_EXPRESS)
// PyBadge/PyGamer setting
#define CONFIG_FPS 30

#endif
#endif
