#ifndef INCLUDE_HPP
#define INCLUDE_HPP


#include <chrono>
#include <thread>

#include "iostream"

#define NORM    0
#define NES     1

#ifndef SYS
# define SYS NORM
#endif

using BYTE = unsigned char;
using WORD = unsigned short;

using u32 = unsigned int;

// Starting Memory Address
static constexpr WORD START_SP          = 0x0100;
static constexpr WORD START_PC          = 0xFFFC;

// Clock speed
const u32 CLOCK_SPEED                   = 1000000; // 1MHz
const u32 NES_CLOCK_SPEED               = 1789773; // 1.789773 MHz

#if SYS == NORM
    static constexpr long time_expected = 1000000 / CLOCK_SPEED;
#else
    static constexpr long time_expected = 1000000 / NES_CLOCK_SPEED;
#endif

// Operation Code
static constexpr BYTE INS_LDA_IM        = 0xA9;


#endif