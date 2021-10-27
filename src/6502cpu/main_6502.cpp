#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char; // 8 bit
using World = unsigned short; // 16 bits

using u32 = unsigned int; // 32 bits

struct MEMORY
{

    static constexpr u32 MAX_MEM = 1024 * 64; // max memory
    Byte Data[MAX_MEM]; // array MAX_MEM length

    void Init(){ // initialise memory
        for ( u32 i = 0; i < MAX_MEM; i++ ){ 
            Data[i] = 0; // for every memory addres wtire 0
        }
    }

    Byte operator[] ( u32 Address) const {
        return Data[Address];
    }
};

struct CPU
{

    World PC; // program counter
    World SP; // stack pointer

    Byte AREG, XREG, YREG; // registers


    struct FLAGS // processor status
    {
        Byte N : 1; // negative ( result negative value) flag
        Byte V : 1; // overflow ( result in overflow value ) flag
        Byte B : 1; // break ( wtitten to the stack) flag
        Byte D : 1; // decimal ( 10 )flag
        Byte I : 1; // interrupt (deprecated) flag
        Byte Z : 1; // zero flag
        Byte C : 1; // carry (arithmetic) flag
    };

    FLAGS PS;

    void Reset( MEMORY& MEM){
        PC = 0xFFFC; // reset vector and reset routline addresses
        SP  = 0x0100; // init
        PS.N, PS.V, PS.B, PS.D, PS.I, PS.Z, PS.C = 0; // initialize flags

        AREG, XREG, YREG = 0; // initialize registers

        MEM.Init(); // initialise memory

    }

    Byte FetchByte(u32 CYCLES, MEMORY& MEM){
        Byte Data = MEM[PC];
        PC++;
        CYCLES--;
        return Data;
    }

    void Execute ( u32 CYCLES ,MEMORY& MEM ){
        while( CYCLES > 0){
            Byte INS = FetchByte( CYCLES, MEM);
        }
    }
    
};


int main(){
    MEMORY mem;
    CPU cpu; 
    cpu.Reset( mem );
    cpu.Execute (2, mem );
    return 0;
}