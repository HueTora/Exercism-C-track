#include "queen_attack.h"
#include <stdio.h>



attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    

    position_t queen_temp_1 = queen_1;
    
    if (queen_1.row > 7 || queen_1.column > 7) return INVALID_POSITION;
    if (queen_2.row > 7 || queen_2.column > 7) return INVALID_POSITION;
    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column) return INVALID_POSITION;

    
    // THIRD diagonal
    while (queen_temp_1.row < 8 && queen_temp_1.column < 8) {
        // white queen right up diagonal
        queen_temp_1.row--;
        queen_temp_1.column--;
        if (queen_temp_1.row == queen_2.row && queen_temp_1.column == queen_2.column) return CAN_ATTACK;
    }
    
    // resetting structure
    queen_temp_1 = queen_1;


    // FIRST diagonal
    while (queen_temp_1.row < 8 && queen_temp_1.column < 8) {
        queen_temp_1.row--;
        queen_temp_1.column++;
        if (queen_temp_1.row == queen_2.row && queen_temp_1.column == queen_2.column) return CAN_ATTACK;
    }

     while (queen_temp_1.row < 8 && queen_temp_1.column < 8) {
        queen_temp_1.row++;
        queen_temp_1.column++;
        if (queen_temp_1.row == queen_2.row && queen_temp_1.column == queen_2.column) return CAN_ATTACK;
    }

    // resetting structure
    queen_temp_1 = queen_1;

    // SECOND diagonal
    printf("%u\n", queen_temp_1.row);
    while (queen_temp_1.row < 8 && queen_temp_1.column < 8) {
        queen_temp_1.row++;
        queen_temp_1.column--;
        if (queen_temp_1.row == queen_2.row && queen_temp_1.column == queen_2.column) return CAN_ATTACK;
    }
    
    if (queen_1.row == queen_2.row || queen_1.column == queen_2.column) return CAN_ATTACK;

    else return CAN_NOT_ATTACK;
}