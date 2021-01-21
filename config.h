/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file


*/
#define ORYX_CONFIGURATOR
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC

#undef MOUSEKEY_DELAY 
#undef MOUSEKEY_INTERVAL 
#undef MOUSEKEY_MAX_SPEED 
#undef MOUSEKEY_TIME_TO_MAX 

#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERVAL 50
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_TIME_TO_MAX 20


#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 1

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 80

#define AUTO_SHIFT_TIMEOUT 150
#define TAPPING_TERM 150
