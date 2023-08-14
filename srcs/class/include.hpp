#ifndef INCLUDE_HPP
#define INCLUDE_HPP


#include <chrono>
#include <thread>
#include <vector>

#include "iostream"

#define NORM    0
#define NES     1

#ifndef SYS
# define SYS NORM
#endif

using BYTE = unsigned char;
using WORD = unsigned short;
using Adress = WORD;

using u32 = unsigned int;

// Starting Memory Address
const WORD START_SP                     = 0x01FD; // 0x01FF - 0x0100 ( 0x01FF not included, 0x01FD )
const WORD START_PC                     = 0xFFFC;
const Adress START_RESET                = 0x01FF;

// Clock speed
const u32 CLOCK_SPEED                   = 1000000; // 1MHz
const u32 NES_CLOCK_SPEED               = 1789773; // 1.789773 MHz

#if SYS == NORM
    static constexpr long time_expected = 1000000 / CLOCK_SPEED;
#else
    static constexpr long time_expected = 1000000 / NES_CLOCK_SPEED;
#endif

// Operation Code
const BYTE INS_LDA_IM                   = 0xA9;
const BYTE INS_JMP_ABS                  = 0x4C;
const BYTE INS_JMP_IND                  = 0x6C;
const BYTE INS_JSR_ABS                  = 0x20;


// Special Operation Code
// L'instruction sert a passer (fake) les 7 premiers cycles du reset puis de jump a 0xFFFC étant donner qu'il est compliquer d'émuler cela
// L'addresse 0x02 est normalement prohiber d'utilisation, mais je fais se que je veux merde !
const BYTE INS_PASS_TIME                = 0x02;
 

class CPU;

// Instruction Management
void putIns(CPU &CPU, Adress Index, unsigned char ins);

// Memory Management
void putAdress(CPU &CPU, Adress Index, Adress adress);
Adress getAdress(CPU &CPU);
BYTE getLow(Adress adress);
BYTE getHigh(Adress adress);

// debug fonc
void printHexDebug(std::string msg, u32 hex);
void printHexDebug( u32 hex );
void printHex(std::string msg, u32 hex );
void printHex(u32 hex );


#endif