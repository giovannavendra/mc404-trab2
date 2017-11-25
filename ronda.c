void ronda(){

}

void gira(){
  int i=0;
  motors[0].speed=0;
  motors[1].speed=5;
  set_motors_speed(motors[0], motors[1]);

  while(i<100){
    i++;
  }

  motors[0].speed=0;
  motors[1].speed=0;
  set_motors_speed(motors[0], motors[1]);
  return;
}

int main (){
  int contador;
}
