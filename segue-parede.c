#include "api_robot2.h"
motor_cfg_t motors[2];

void busca_parede(){
  int i = read_sonar(3);
  int j = read_sonar(4);
  motors[0].speed=30;
  motors[1].speed=30;
  set_motors_speed(&motors[0], &motors[1]);

  if(i<600){
    motors[0].speed=0;
    motors[1].speed=0;
    set_motors_speed(&motors[0], &motors[1]);
  }
  while(1);
  // if(read_sonar(3)>read_sonar(4)){
  //   while(read_sonar(4)<1200){
  //     motors[0].speed=5;
  //     motors[1].speed=0;
  //     set_motors_speed(motors[0], motors[1]);
  //   }
  // }

  // else{
    while(read_sonar(3)<1200){
      motors[0].speed=0;
      motors[1].speed=5;
      set_motors_speed(&motors[0], &motors[1]);
    }
  // }

  motors[0].speed=0;
  motors[1].speed=0;
  set_motors_speed(&motors[0], &motors[1]);

  return;
}

void segue_parede(motor_cfg_t* motors){
  while (1){
    if (read_sonar(0)>500 || read_sonar(3)<1200){
      motors[0].speed=3;
      motors[1].speed=0;
      set_motors_speed(&motors[0], &motors[1]);
    }
    else {
      motors[0].speed=5;
      motors[1].speed=5;
      set_motors_speed(&motors[0], &motors[1]);
    }
  }
  return;
}


int _start (){

  motors[0].id=0;
  motors[1].id=1;
  motors[0].speed=30;
  motors[1].speed=30;
  //set_motors_speed(&motors[0], &motors[1]);
  //while(1);
  busca_parede();
  // segue_parede(motors);
  return 0;
}
