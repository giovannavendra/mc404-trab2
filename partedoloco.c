void busca_parede(motor_cfg_t* motors){
  while(read_sonar(3)>1200 && read_sonar(4)>1200){
    motors[0].speed=16;
    motors[1].speed=16;
    set_motors_speed(&motors[0], &motors[1]);
  }

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
