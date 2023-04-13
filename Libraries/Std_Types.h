/*
 * Std_Types.h
 *
 *  Created on: Feb 13, 2023
 *      Author: moazo
 */

#ifndef LIBRARIES_STD_TYPES_H_
#define LIBRARIES_STD_TYPES_H_

#pragma once
#include <stdint.h>

#define NULL (void *)0

typedef unsigned char uint8_t;
typedef volatile unsigned char vuint8_t;
typedef unsigned short uint16_t;
typedef volatile unsigned short vuint16_t;

//typedef unsigned int uint32_t;
typedef volatile unsigned int vuint32_t;

typedef volatile unsigned long int vuint64_t;
typedef volatile long double vuf64_t;



#endif /* LIBRARIES_STD_TYPES_H_ */
