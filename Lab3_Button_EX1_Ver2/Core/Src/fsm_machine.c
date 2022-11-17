/*
 * fsm_machine.c
 *
 *  Created on: Nov 13, 2022
 *      Author: Lenovo
 */


#include "main.h"
#include "fsm_machine.h"
#include "software_timer.h"
#include "seg7_display.h"
#include "global.h"

int status_traffic1 = 1;
int status_traffic2 = 1;
//int seg_index1 = 5;
//int seg_index2 = 3;
//int seg = 0;
void TRAFFIC_NORMAL1(){
//	while(status_BUTTONS == 0){
	switch(status_traffic1){

	case 1:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, SET);

//		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
//		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
//		HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, SET);
		if(timer_flag1 == 1){
			status_traffic1 = 2;
			setTimer1(300);      //green
		}
		break;
	case 2:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
		HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, SET);
//		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
//		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
//		HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, RESET);
		if(timer_flag1 == 1){
			status_traffic1 = 3;
			setTimer1(200);     //purple1
		}
		break;

	case 3:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, RESET);
//		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
//		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
//		HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, SET);
		if(timer_flag1 == 1){
			setTimer1(500);
			status_traffic1 = 1;
		}
		break;
//	case 4:
//		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
//		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
//		HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, RESET);
//		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
//		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
//		HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, SET);
//		if(timer_flag1 == 1){
//			setTimer1(300);
//			status_traffic = 1;
//				}
//		break;
	default:
		break;
	}
//	}
}

void TRAFFIC_NORMAL2(){
	switch(status_traffic2){

	case 1:
//		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
//		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
//		HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
		HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, SET);
		if(timer_flag2 == 1){
			status_traffic2 = 2;
			setTimer2(200);//yellow
		}
		break;
	case 2:
//		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
//		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
//		HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, RESET);
		if(timer_flag2 == 1){
			status_traffic2 = 3;
			setTimer2(500);//red1
		}
		break;

	case 3:
//		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
//		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
//		HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, SET);
		if(timer_flag2 == 1){
			setTimer2(300);
			status_traffic2 = 1;
		}
		break;
//	case 4:
//		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
//		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
//		HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, RESET);
//		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
//		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
//		HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, SET);
//		if(timer_flag1 == 1){
//			setTimer1(300);
//			status_traffic = 1;
//				}
		break;
	default:
		break;
	}
	return;
}

void OFF_ALL_LED2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 1);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 1);
	HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, 1);
}

void OFF_ALL_LED1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 1);
	HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, 1);
}


void ON_ALL_LED2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 0);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 0);
	HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, 0);
}

void ON_ALL_LED1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 0);
	HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, 0);
}

//void SEG_MODE1_DISPLAY(int num){
//	switch(num){
//	case 1:
//
//		break;
//	case 2:
//
//		break;
//	case 3:
//		display7SEG1(0);
//		break;
//	case 4:
//		display7SEG1(2);
//		break;
//	default:
//		break;
//	}
//}
//



//void fsm_status(){
//	switch(status_BUTTONS){
//	case 0:
//		TRAFFIC_NORMAL1();
//		TRAFFIC_NORMAL2();
//		to_do_7SEG();
////		if(is_SELECT_Pressed() == 1){
////			status_BUTTONS = 1;
////			OFF_ALL_LED1();
////			OFF_ALL_LED2();
////			setTimer_for_blink(250);
////		}
////		if(is_MODIFY_Pressed() == 1){
////			status_BUTTONS = 1;
////		}
//		break;
//	case 1:
////		if(flag_BLINK == 1){
////			setTimer_for_blink(250);
////			HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
////			HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
////		}
//
//		break;
//	case 2:
//
//		break;
//	case 3:
//
//		break;
//	default:
//		break;
//	}
//}


void fsm_Suy_Exercise(){
	switch(status_BUTTONS){
	case 0:
		TRAFFIC_NORMAL1();
		TRAFFIC_NORMAL2();
		to_do_7SEG();
//		if(is_SELECT_PRESSED() == 1){
//			status_BUTTONS = 1;
//		}
		if(is_MODIFY_PRESSED() == 1){
			status_BUTTONS = 1;
		}
		break;
	case 1:
		ON_ALL_LED1();
		ON_ALL_LED2();
//		if(is_SELECT_PRESSED() == 1){
//					status_BUTTONS = 2;
//				}
//		if(is_SELECT_PRESSED() == 1){
//			OFF_ALL_LED1();
//			OFF_ALL_LED2();
//		}
		if(is_MODIFY_PRESSED() == 1){
				status_BUTTONS = 2;
			}
		break;
	case 2:
		HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
		if(is_SELECT_PRESSED() == 1){
					status_BUTTONS = 3;
				}
		break;
	case 3:
		if(is_SELECT_PRESSED() == 1){
					status_BUTTONS = 4;
				}
		break;
	default:
		break;
	}
	return;
}
