
#ifndef _DRONE_MSG_HANDLER_H   
#define _DRONE_MSG_HANDLER_H
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef enum {
	DRONE_MSG_HANDLER_STATE_MSG_START,
	DRONE_MSG_HANDLER_STATE_MSG_RECEIVE
}DRONE_MSG_HANDLER_STATE;

typedef enum {
	DRONE_MSG_TYPE_NONE,
	DRONE_MSG_TYPE_UPDATE_SETPOINTS,
	DRONE_MSG_TYPE_MANUAL_CONTROL,
	DRONE_MSG_TYPE_KILL_MOTORS
} DRONE_MSG_TYPE;

typedef struct {
	float yaw;
	float pitch;
	float roll;
	float height;	
} DRONE_MSG_DATA_UPDATE_SETPOINTS;

typedef struct {
	float bottomLeftMotor;
	float bottomRightMotor;
	float topLeftMotor;
	float topRightMotor;	
} DRONE_MSG_DATA_MANUAL_CONTROL;

void DRONE_MSG_HANDLER_INITIALIZE();

void DRONE_MSG_HANDLER_UPDATE();

DRONE_MSG_TYPE DRONE_MSG_HANDLER_LAST_MSG_TYPE();

DRONE_MSG_DATA_UPDATE_SETPOINTS DRONE_MSG_HANDLER_DATA_UPDATE_SETPOINTS();

DRONE_MSG_DATA_MANUAL_CONTROL DRONE_MSG_HANDLER_DATA_MANUAL_CONTROL();

bool DRONE_MSG_HANDLER_NEW_MSG_AVAILABLE();


#endif 
