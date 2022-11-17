/*
 * fsm_machine.h
 *
 *  Created on: Nov 13, 2022
 *      Author: Lenovo
 */

#ifndef INC_FSM_MACHINE_H_
#define INC_FSM_MACHINE_H_
#include "main.h"
#include "global.h"
#include "software_timer.h"

void TRAFFIC_NORMAL1();
void TRAFFIC_NORMAL2();
void to_do_7SEG();
void fsm_Suy_Exercise();
void fsm_status(void);
void OFF_ALL_LED1();
void OFF_ALL_LED2();
void ON_ALL_LED1();
void ON_ALL_LED2();
extern int seg ;

extern int status_BUTTONS;
extern int ex;


#endif /* INC_FSM_MACHINE_H_ */
