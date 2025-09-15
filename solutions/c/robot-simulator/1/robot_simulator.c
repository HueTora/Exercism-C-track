#include "robot_simulator.h"
#include <stdio.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    
    robot_status_t robot = {direction, {x,y}};
    
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands) {

    char command;   
    while ((command = *commands) != '\0') {

        if (command == 'R') {
            robot->direction = ((robot->direction + 1) % 4);
        }
        if (command == 'L') {
            robot->direction = ((robot->direction + 3) % 4);
        }
        
        if (command == 'A') {
            switch(robot->direction) {
                case DIRECTION_NORTH:
                    robot->position.y++;
                    break;
                case DIRECTION_EAST:
                    robot->position.x++;
                    break;
                case DIRECTION_SOUTH:
                     robot->position.y--;
                    break;
                case DIRECTION_WEST:
                    robot->position.x--;
                    break;
            }
        }
        commands++;
    }
    
}