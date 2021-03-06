/*
  pin_map.h - Pin mapping configuration file
  Part of Grbl

  Copyright (c) 2013 Sungeun K. Jeon

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

/* The pin_map.h file serves as a central pin mapping settings file for different processor
   types, i.e. AVR 328p or AVR Mega 2560. Grbl officially supports the Arduino Uno, but the 
   other supplied pin mappings are supplied by users, so your results may vary. */

#ifndef pin_map_h
#define pin_map_h

//#ifdef PIN_MAP_ARDUINO_UNO // AVR 328p, Officially supported by Grbl.
//don't care about anything except Sanguinololou
// Serial port pins
#define SERIAL_RX USART0_RX_vect
#define SERIAL_UDRE USART0_UDRE_vect

#define STEPPING_STEP_DDR_X       DDRD
#define STEPPING_STEP_PORT_X      PORTD
#define STEPPING_STEP_X           PD7

#define STEPPING_DIR_DDR_X        DDRC
#define STEPPING_DIR_PORT_X       PORTC
#define STEPPING_DIR_X            PC5

#define STEPPING_STEP_DDR_Y       DDRC
#define STEPPING_STEP_PORT_Y      PORTC
#define STEPPING_STEP_Y           PC6

#define STEPPING_DIR_DDR_Y        DDRC
#define STEPPING_DIR_PORT_Y       PORTC
#define STEPPING_DIR_Y            PC7

#define STEPPING_STEP_DDR_Z       DDRB
#define STEPPING_STEP_PORT_Z      PORTB
#define STEPPING_STEP_Z           PB3

#define STEPPING_DIR_DDR_Z        DDRB
#define STEPPING_DIR_PORT_Z       PORTB
#define STEPPING_DIR_Z            PB2


  //leave these, since there are bit-packed variables in there 
  #define X_STEP_BIT         0  // Uno Digital Pin 2
  #define X_STEP_MASK        (1 << X_STEP_BIT)
  #define Y_STEP_BIT         1  // Uno Digital Pin 3
  #define Y_STEP_MASK        (1 << Y_STEP_BIT) 
  #define Z_STEP_BIT         2  // Uno Digital Pin 4
  #define Z_STEP_MASK        (1 << Z_STEP_BIT)
  #define X_DIRECTION_BIT    3  // Uno Digital Pin 5
  #define X_DIRECTION_MASK   (1 << X_DIRECTION_BIT)
  #define Y_DIRECTION_BIT    4  // Uno Digital Pin 6
  #define Y_DIRECTION_MASK   (1 << Y_DIRECTION_BIT)
  #define Z_DIRECTION_BIT    5  // Uno Digital Pin 7
  #define Z_DIRECTION_MASK   (1 << Z_DIRECTION_BIT)

  #define STEP_MASK ((1<<X_STEP_BIT)|(1<<Y_STEP_BIT)|(1<<Z_STEP_BIT)) // All step bits
  #define DIRECTION_MASK ((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)|(1<<Z_DIRECTION_BIT)) // All direction bits
  #define STEPPING_MASK (STEP_MASK | DIRECTION_MASK) // All stepping-related bits (step/direction)

  #define STEPPERS_DISABLE_DDR    DDRD
  #define STEPPERS_DISABLE_PORT   PORTD
  #define STEPPERS_DISABLE_BIT    PD6
  #define STEPPERS_DISABLE_MASK (1<<STEPPERS_DISABLE_BIT)

  //on Sanguinololu, there are separate STEPPER_EN pin for XY and Z drivers
  #define STEPPERS_DISABLE_Z_DDR    DDRA
  #define STEPPERS_DISABLE_Z_PORT   PORTA
  #define STEPPERS_DISABLE_Z_BIT    PA5
  #define STEPPERS_DISABLE_Z_MASK (1<<STEPPERS_DISABLE_Z_BIT)


  // NOTE: All limit bit pins must be on the same port
  #define LIMIT_DDR       DDRC
  #define LIMIT_PIN       PINC
  #define LIMIT_PORT      PORTC
  #define X_LIMIT_BIT     2  // Uno Digital Pin 9
  #define Y_LIMIT_BIT     3  // Uno Digital Pin 10
  #define Z_LIMIT_BIT     4  // Uno Digital Pin 11
  #define LIMIT_INT       PCIE2  // Pin change interrupt enable pin
  #define LIMIT_INT_vect  PCINT2_vect 
  #define LIMIT_PCMSK     PCMSK2 // Pin change interrupt register
  #define LIMIT_MASK ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)) // All limit bits

  #define SPINDLE_ENABLE_DDR   DDRD
  #define SPINDLE_ENABLE_PORT  PORTD
  #define SPINDLE_ENABLE_BIT   5  // Hotend mosfet output

  #define SPINDLE_DIRECTION_DDR   DDRD
  #define SPINDLE_DIRECTION_PORT  PORTD
  #define SPINDLE_DIRECTION_BIT   4  // Heated bed mosfet output

  #define COOLANT_FLOOD_DDR   DDRD
  #define COOLANT_FLOOD_PORT  PORTD
  #define COOLANT_FLOOD_BIT   4  // Uno Analog Pin 3

  // NOTE: Uno analog pins 4 and 5 are reserved for an i2c interface, and may be installed at
  // a later date if flash and memory space allows.
  // #define ENABLE_M7  // Mist coolant disabled by default. Uncomment to enable.
  #ifdef ENABLE_M7
    #define COOLANT_MIST_DDR   DDRC
    #define COOLANT_MIST_PORT  PORTC
    #define COOLANT_MIST_BIT   4 // Uno Analog Pin 4
  #endif  

  // NOTE: All pinouts pins must be on the same port
  #define PINOUT_DDR       DDRA
  #define PINOUT_PIN       PINA
  #define PINOUT_PORT      PORTA
  #define PIN_RESET        0  // A0
  #define PIN_FEED_HOLD    1  // A1
  #define PIN_CYCLE_START  2  // A2
  #define PINOUT_INT       PCIE0  // Pin change interrupt enable pin
  #define PINOUT_INT_vect  PCINT0_vect
  #define PINOUT_PCMSK     PCMSK0 // Pin change interrupt register
  #define PINOUT_MASK ((1<<PIN_RESET)|(1<<PIN_FEED_HOLD)|(1<<PIN_CYCLE_START))
  
//#endif


#ifdef PIN_MAP_ARDUINO_MEGA_2560 // Working @EliteEng

  // Serial port pins
  #define SERIAL_RX USART0_RX_vect
  #define SERIAL_UDRE USART0_UDRE_vect

  // Increase Buffers to make use of extra SRAM
  #define RX_BUFFER_SIZE 256
  #define TX_BUFFER_SIZE 128
  #define BLOCK_BUFFER_SIZE 36
  #define LINE_BUFFER_SIZE 100

  // NOTE: All step bit and direction pins must be on the same port.
  #define STEPPING_DDR      DDRA
  #define STEPPING_PORT     PORTA
  #define STEPPING_PIN      PINA
  #define X_STEP_BIT        2 // MEGA2560 Digital Pin 24
  #define Y_STEP_BIT        3 // MEGA2560 Digital Pin 25
  #define Z_STEP_BIT        4 // MEGA2560 Digital Pin 26
  #define X_DIRECTION_BIT   5 // MEGA2560 Digital Pin 27
  #define Y_DIRECTION_BIT   6 // MEGA2560 Digital Pin 28
  #define Z_DIRECTION_BIT   7 // MEGA2560 Digital Pin 29
  #define STEP_MASK ((1<<X_STEP_BIT)|(1<<Y_STEP_BIT)|(1<<Z_STEP_BIT)) // All step bits
  #define DIRECTION_MASK ((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)|(1<<Z_DIRECTION_BIT)) // All direction bits
  #define STEPPING_MASK (STEP_MASK | DIRECTION_MASK) // All stepping-related bits (step/direction)

  #define STEPPERS_DISABLE_DDR   DDRB
  #define STEPPERS_DISABLE_PORT  PORTB
  #define STEPPERS_DISABLE_BIT   7 // MEGA2560 Digital Pin 13
  #define STEPPERS_DISABLE_MASK (1<<STEPPERS_DISABLE_BIT)

  // NOTE: All limit bit pins must be on the same port
  #define LIMIT_DDR       DDRB
  #define LIMIT_PORT      PORTB
  #define LIMIT_PIN       PINB
  #define X_LIMIT_BIT     4 // MEGA2560 Digital Pin 10
  #define Y_LIMIT_BIT     5 // MEGA2560 Digital Pin 11
  #define Z_LIMIT_BIT     6 // MEGA2560 Digital Pin 12
  #define LIMIT_INT       PCIE0  // Pin change interrupt enable pin
  #define LIMIT_INT_vect  PCINT0_vect 
  #define LIMIT_PCMSK     PCMSK0 // Pin change interrupt register
  #define LIMIT_MASK ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)) // All limit bits

  #define SPINDLE_ENABLE_DDR   DDRC
  #define SPINDLE_ENABLE_PORT  PORTC
  #define SPINDLE_ENABLE_BIT   2 // MEGA2560 Digital Pin 35

  #define SPINDLE_DIRECTION_DDR   DDRC
  #define SPINDLE_DIRECTION_PORT  PORTC
  #define SPINDLE_DIRECTION_BIT   1 // MEGA2560 Digital Pin 36

  #define COOLANT_FLOOD_DDR   DDRC
  #define COOLANT_FLOOD_PORT  PORTC
  #define COOLANT_FLOOD_BIT   0 // MEGA2560 Digital Pin 37

  // #define ENABLE_M7  // Mist coolant disabled by default. Uncomment to enable.
  #ifdef ENABLE_M7
    #define COOLANT_MIST_DDR   DDRC
    #define COOLANT_MIST_PORT  PORTC
    #define COOLANT_MIST_BIT   3 // MEGA2560 Digital Pin 34
  #endif  

  // NOTE: All pinouts pins must be on the same port
  #define PINOUT_DDR       DDRK
  #define PINOUT_PIN       PINK
  #define PINOUT_PORT      PORTK
  #define PIN_RESET        0  // MEGA2560 Analog Pin 8
  #define PIN_FEED_HOLD    1  // MEGA2560 Analog Pin 9
  #define PIN_CYCLE_START  2  // MEGA2560 Analog Pin 10
  #define PINOUT_INT       PCIE2  // Pin change interrupt enable pin
  #define PINOUT_INT_vect  PCINT2_vect
  #define PINOUT_PCMSK     PCMSK2 // Pin change interrupt register
  #define PINOUT_MASK ((1<<PIN_RESET)|(1<<PIN_FEED_HOLD)|(1<<PIN_CYCLE_START))

#endif

/* 
#ifdef PIN_MAP_CUSTOM_PROC
  // For a custom pin map or different processor, copy and paste one of the default pin map
  // settings above and modify it to your needs. Then, make sure the defined name is also
  // changed in the config.h file.
#endif
*/

#endif
