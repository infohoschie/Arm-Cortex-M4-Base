/**
 * @file
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * @author Thomas Vogt, thomas@thomas-vogt.de
 *
 * @brief C Main.
 **/

#include "main.h"

#include <stdint.h>

static void setRegister( uint32_t address, uint32_t value );

static uint32_t getRegister( uint32_t address );

void myMain( void )
{
  uint32_t value1 = getRegister( 0x20001000 );
  setRegister( 0x20001000, 0xCAFEAFFE );
  uint32_t value2 = getRegister( 0x20001000 );
}

static void setRegister( uint32_t address, uint32_t value )
{
  uint32_t * const region = (uint32_t*)( address );
  *region = value;
}

static uint32_t getRegister( uint32_t address )
{
  uint32_t const * const region = (uint32_t*)( address );
  return *region;
}
