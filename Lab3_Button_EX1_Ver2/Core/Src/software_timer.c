/*
 * software_timer.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Lenovo
 */


#include "main.h"
#include "software_timer.h"

#define number_LED 4


//declare timer counter
int counter1;
int counter2;
int counter3;
int counter4;
int counter5;



////variables for 7SEG
//int num;
//
//int seg_index1 = 5;
//int seg_index2 = 3;
//int seg_buffer[9] = {0,1,2,3,4,5,6,7,8,9};



//declare timer flag
int timer_flag1;
int timer_flag2;
int timer_flag3;






//setTimer for Traffic light ngang
void setTimer1(int duration1){
	counter1 = duration1;
	timer_flag1 = 0;
}

//setTimer for Traffic light ngang
void setTimer2(int duration2){
	counter2 = duration2;
	timer_flag2 = 0;
}

//setTimer for 7SEG
void setTimer3(int duration3){
	counter3 = duration3;
	timer_flag3 = 0;
}

////setTImer1 for 7seg1 in NORMAL MODe of RED1
//int seg7_timer_counter1;
//int seg7_timer_flag1;
//void setTimer_7seg_NORMAL1(int timer1_7seg){
//	seg7_timer_counter1 = timer1_7seg;
//	seg7_timer_flag1 = 0;
//}
////setTimer2 for 7seg2 NORMAL MODE of Green1
//int seg7_timer_counter2;
//int seg7_timer_flag2;
//void setTimer_7seg_NORMAL2(int timer2_7seg){
//	seg7_timer_counter2 = timer2_7seg;
//	seg7_timer_flag2 = 0;
//}
//
////setTimer3 for 7seg3 NORMAL MODE of yellow1
//int seg7_timer_counter3;
//int seg7_timer_flag3;
//void setTimer_7seg_NORMAL3(int timer3_7seg){
//	seg7_timer_counter3 = timer3_7seg;
//	seg7_timer_flag3 = 0;
//}
//
////setTimer4 for 7seg4 NORMAL MODE of green2
//int seg7_timer_counter4;
//int seg7_timer_flag4;
//void setTimer_7seg_NORMAL4(int timer4_7seg){
//	seg7_timer_counter4 = timer4_7seg;
//	seg7_timer_flag4 = 0;
//}
//
////setTimer5 for 7seg5 NORMAL MODE
//int seg7_timer_counter5;
//int seg7_timer_flag5;
//void setTimer_7seg_NORMAL5(int timer5_7seg){
//	seg7_timer_counter5 = timer5_7seg;
//	seg7_timer_flag5 = 0;
//}
//
////setTimer6 for 7seg6 NORMAL MODE
//int seg7_timer_counter6;
//int seg7_timer_flag6;
//void setTimer_7seg_NORMAL6(int timer6_7seg){
//	seg7_timer_counter6 = timer6_7seg;
//	seg7_timer_flag6 = 0;
//}


//blink section
int counter_BLINK;
int flag_BLINK;
void setTimer_for_blink(int duration){
	counter_BLINK = duration;
	flag_BLINK = 0;
}





//Led blink in change mode
int RED_BLINK_counter = 0;
int RED_BLINK_flag = 0;
void setTimer_for_RED_blink(int duration){
	RED_BLINK_counter = duration;
	RED_BLINK_flag = 0;
}



int GREEN_BLINK_counter = 0;
int GREEN_BLINK_flag = 0;
void setTimer_for_GREEN_blink(int duration){
	GREEN_BLINK_counter = duration;
	GREEN_BLINK_flag = 0;
}

int YELLOW_BLINK_counter = 0;
int YELLOW_BLINK_flag = 0;
void setTimer_for_YELLOW_blink(int duration){
	YELLOW_BLINK_counter = duration;
	YELLOW_BLINK_flag = 0;
}

//TimerRun for system
void timerRun(){
	if(counter1 > 0){
		counter1--;
	}
	if(counter1 <= 0){
		timer_flag1 = 1;
	}
	if(counter2 > 0){
		counter2--;
	}
	if(counter2 <= 0){
		timer_flag2 = 1;
	}
	if(counter3 > 0){
		counter3--;
	}
	if(counter3 <= 0){
		timer_flag3 = 1;
	}
//	if(counter_BLINK > 0){
//		counter_BLINK--;
//	}
//	if(counter_BLINK <= 0){
//		flag_BLINK = 1;
//	}
	if(RED_BLINK_counter > 0){
		RED_BLINK_counter--;
	}
	if(RED_BLINK_counter <= 0){
		RED_BLINK_flag = 1;
	}
	if(YELLOW_BLINK_counter > 0){
		YELLOW_BLINK_counter--;
	}
	if(YELLOW_BLINK_counter <= 0){
		YELLOW_BLINK_flag = 1;
	}
	if(GREEN_BLINK_counter > 0){
		GREEN_BLINK_counter--;
	}
	if(GREEN_BLINK_counter <= 0){
		GREEN_BLINK_flag = 1;
	}
}


//void timerRun_7seg(){
//	if(seg7_timer_counter1 > 0){
//		seg7_timer_counter1--;
//	}
//	if(seg7_timer_counter1 <= 0){
//		seg7_timer_flag1 = 1;
//	}
//	if(seg7_timer_counter2 > 0){
//			seg7_timer_counter2--;
//	}
//	if(seg7_timer_counter2 <= 0){
//		seg7_timer_flag2 = 1;
//	}
//	if(seg7_timer_counter3 > 0){
//		seg7_timer_counter3--;
//	}
//	if(seg7_timer_counter3 <= 0){
//		seg7_timer_flag3 = 1;
//	}
//	if(seg7_timer_counter4 > 0){
//			seg7_timer_counter4--;
//	}
//	if(seg7_timer_counter4 <= 0){
//		seg7_timer_flag4 = 1;
//	}
//	if(seg7_timer_counter5 > 0){
//		seg7_timer_counter5--;
//	}
//	if(seg7_timer_counter5 <= 0){
//		seg7_timer_flag5 = 1;
//	}
//	if(seg7_timer_counter6 > 0){
//			seg7_timer_counter6--;
//	}
//	if(seg7_timer_counter6 <= 0){
//		seg7_timer_flag6 = 1;
//	}
//}






////Turn ALL LED
//void turnLEDOFF(void){
//	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);//tat den led 2
//	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);//tat den led 3
//	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);//tat den led 4
//	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);//tat den led 1
//}
//
//
//
////change_7SEG_status
//void Change_7SEG(int i){
//	seg_index = (seg_index + 1)%number_LED;
//	num=seg_buffer[seg_index];
//	switch(i){
//	case 0:
//		turnLEDOFF();
//		display7SEG1(num);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
////		clockRun();
//		break;
//	case 1:
//		turnLEDOFF();
//		display7SEG1(num);
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
//		break;
//	case 2:
//		turnLEDOFF();
//		display7SEG1(num);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
//		break;
//	case 3:
//		turnLEDOFF();
//		display7SEG1(num);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
//		break;
//	default:
//		break;
//	}
//}
//
//
