#ifndef foo_h
#define foo_h
#include <iostream>


extern bool getBit(const uint8_t src, const uint32_t bitPosition);
extern uint8_t& setBit(uint8_t& dest, const bool value, const uint32_t bitPosition);
extern uint8_t& setBitL(uint8_t& dest, const uint32_t bitPosition, const uint32_t bitWidth, const uint32_t value);
extern uint8_t& setBitU(uint8_t& dest, const uint32_t bitPosition, const uint32_t bitWidth, const uint32_t value);












#endif