
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver pwm3 = Adafruit_PWMServoDriver(0x42);
Adafruit_PWMServoDriver pwm4 = Adafruit_PWMServoDriver(0x44);

int arr[7][7][2]={
  {{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{2,3}},
  {{1,3},{1,4},{1,5},{2,4},{2,5},{2,6},{2,7}},
  {{1,6},{1,7},{1,8},{2,8},{2,9},{2,10},{2,11}},
  {{4,0},{4,1},{4,2},{3,0},{3,1},{3,2},{3,3}},
  {{4,3},{4,4},{4,5},{3,4},{3,5},{3,6},{3,7}},
  {{4,6},{4,7},{4,8},{3,8},{3,9},{3,10},{3,11}},
  {{4,9},{4,10},{4,11},{3,12},{3,13},{3,14},{3,15}}
};


#define SERVOMIN  180 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  250 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// our servo # counter
uint8_t servonum = 0;


// column wave..........................
void rotatecolumn(int spin){
  for(int i = 0; i<7 ;i++){
  if(arr[i][0][0] == 1){
    pwm1.setPWM(arr[i][0][1],0,spin);
    }
   else if(arr[i][0][0] == 4){
    pwm4.setPWM(arr[i][0][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[i][1][0] == 1){
    pwm1.setPWM(arr[i][1][1],0,spin);
    }
   else if(arr[i][1][0] == 4){
    pwm4.setPWM(arr[i][1][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[i][2][0] == 1){
    pwm1.setPWM(arr[i][2][1],0,spin);
    }
   else if(arr[i][2][0] == 4){
    pwm4.setPWM(arr[i][2][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[i][3][0] == 2){
    pwm2.setPWM(arr[i][3][1],0,spin);
    }
   else if(arr[i][3][0] == 3){
    pwm3.setPWM(arr[i][3][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[i][4][0] == 2){
    pwm2.setPWM(arr[i][4][1],0,spin);
    }
   else if(arr[i][4][0] == 3){
    pwm3.setPWM(arr[i][4][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[i][5][0] == 2){
    pwm2.setPWM(arr[i][5][1],0,spin);
    }
   else if(arr[i][5][0] == 3){
    pwm3.setPWM(arr[i][5][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[i][6][0] == 2){
    pwm2.setPWM(arr[i][6][1],0,spin);
    }
   else if(arr[i][6][0] == 3){
    pwm3.setPWM(arr[i][6][1],0,spin);
    } 
     delay(15);
  }
  }
// circle loop.......................................
void circleloop(int spin){
  //part1
  pwm3.setPWM(arr[3][3][1],0,spin);
  delay(100);
  for(int i=2;i<5;i++){
    if(arr[i][4][0]==2){
    pwm2.setPWM(arr[i][4][1],0,spin);  
    }
    else if(arr[i][4][0]==3){
    pwm3.setPWM(arr[i][4][1],0,spin);  
    }
  }
  delay(100);
  for(int i=4;i>1;i--){
    if(arr[4][i][0]==3){
    pwm3.setPWM(arr[4][i][1],0,spin);  
    }
    else if(arr[4][i][0]==4){
    pwm4.setPWM(arr[4][i][1],0,spin);  
    }
  }
  delay(100);
  for(int i=4;i>1;i--){
    if(arr[i][2][0]==4){
    pwm4.setPWM(arr[i][2][1],0,spin);  
    }
    else if(arr[i][2][0]==1){
    pwm1.setPWM(arr[i][2][1],0,spin);  
    }
  }
  delay(100);
  for(int i=2;i<5;i++){
    if(arr[2][i][0]==1){
    pwm1.setPWM(arr[2][i][1],0,spin);  
    }
    else if(arr[2][i][0]==2){
    pwm2.setPWM(arr[2][i][1],0,spin);  
    }
  }
  delay(100);
//part2
  for(int i=1;i<6;i++){
    if(arr[i][5][0]==2){
    pwm2.setPWM(arr[i][5][1],0,spin);  
    }
    else if(arr[i][5][0]==3){
    pwm3.setPWM(arr[i][5][1],0,spin);  
    }
  }
  delay(100);
  for(int i=5;i>0;i--){
    if(arr[5][i][0]==3){
    pwm3.setPWM(arr[5][i][1],0,spin);  
    }
    else if(arr[5][i][0]==4){
    pwm4.setPWM(arr[5][i][1],0,spin);  
    }
  }
  delay(100);
  for(int i=5;i>0;i--){
    if(arr[i][1][0]==4){
    pwm4.setPWM(arr[i][1][1],0,spin);  
    }
    else if(arr[i][1][0]==1){
    pwm1.setPWM(arr[i][1][1],0,spin);  
    }
  }
  delay(100);
  for(int i=1;i<6;i++){
    if(arr[1][i][0]==1){
    pwm1.setPWM(arr[1][i][1],0,spin);  
    }
    else if(arr[1][i][0]==2){
    pwm2.setPWM(arr[1][i][1],0,spin);  
    }
  }
  delay(100);
//part3
  for(int i=0;i<7;i++){
    if(arr[i][6][0]==2){
    pwm2.setPWM(arr[i][6][1],0,spin);  
    }
    else if(arr[i][6][0]==3){
    pwm3.setPWM(arr[i][6][1],0,spin);  
    }
  }
  delay(100);
  for(int i=6;i>=0;i--){
    if(arr[6][i][0]==3){
    pwm3.setPWM(arr[6][i][1],0,spin);  
    }
    else if(arr[6][i][0]==4){
    pwm4.setPWM(arr[6][i][1],0,spin);  
    }
  }
  delay(100);
  for(int i=6;i>=0;i--){
    if(arr[i][0][0]==4){
    pwm4.setPWM(arr[i][0][1],0,spin);  
    }
    else if(arr[i][0][0]==1){
    pwm1.setPWM(arr[i][0][1],0,spin);  
    }
  }
  delay(100);
  for(int i=0;i<7;i++){
    if(arr[0][i][0]==1){
    pwm1.setPWM(arr[0][i][1],0,spin);  
    }
    else if(arr[0][i][0]==2){
    pwm2.setPWM(arr[0][i][1],0,spin);  
    }
  }
  delay(100);
}

// circle loop inverse..................................................

void circleloopinv(int spin){
  //part1
  for(int i=6;i>=0;i--){
    if(arr[0][i][0]==2){
    pwm2.setPWM(arr[0][i][1],0,spin);  
    }
    else if(arr[0][i][0]==1){
    pwm1.setPWM(arr[0][i][1],0,spin);  
    }
  }
  delay(100);
  for(int i=0;i<7;i++){
    if(arr[i][0][0]==1){
    pwm1.setPWM(arr[i][0][1],0,spin);  
    }
    else if(arr[i][0][0]==4){
    pwm4.setPWM(arr[i][0][1],0,spin);  
    }
  }
  delay(100);
  for(int i=0;i<7;i++){
    if(arr[6][i][0]==4){
    pwm4.setPWM(arr[6][i][1],0,spin);  
    }
    else if(arr[6][i][0]==3){
    pwm3.setPWM(arr[6][i][1],0,spin);  
    }
  }
  delay(100);
  for(int i=6;i>=0;i--){
    if(arr[i][6][0]==3){
    pwm3.setPWM(arr[i][6][1],0,spin);  
    }
    else if(arr[i][6][0]==2){
    pwm2.setPWM(arr[i][6][1],0,spin);  
    }
  }
  delay(100);
  
  
  
//part2

  for(int i=5;i>0;i--){
    if(arr[1][i][0]==2){
    pwm2.setPWM(arr[1][i][1],0,spin);  
    }
    else if(arr[1][i][0]==1){
    pwm1.setPWM(arr[1][i][1],0,spin);  
    }
  }
  delay(100);
  for(int i=1;i<6;i++){
    if(arr[i][1][0]==1){
    pwm1.setPWM(arr[i][1][1],0,spin);  
    }
    else if(arr[i][1][0]==4){
    pwm4.setPWM(arr[i][1][1],0,spin);  
    }
  }
  delay(100);
  for(int i=1;i<6;i++){
    if(arr[5][i][0]==4){
    pwm4.setPWM(arr[5][i][1],0,spin);  
    }
    else if(arr[5][i][0]==3){
    pwm3.setPWM(arr[5][i][1],0,spin);  
    }
  }
  delay(100);
  for(int i=5;i>0;i--){
    if(arr[i][5][0]==3){
    pwm3.setPWM(arr[i][5][1],0,spin);  
    }
    else if(arr[i][5][0]==2){
    pwm2.setPWM(arr[i][5][1],0,spin);  
    }
  }
  delay(100);

  
  

  //part3
  
  for(int i=4;i>1;i--){
    if(arr[2][i][0]==2){
    pwm2.setPWM(arr[2][i][1],0,spin);  
    }
    else if(arr[2][i][0]==1){
    pwm1.setPWM(arr[2][i][1],0,spin);  
    }
  }
  delay(100);
  for(int i=2;i<5;i++){
    if(arr[i][2][0]==1){
    pwm1.setPWM(arr[i][2][1],0,spin);  
    }
    else if(arr[i][2][0]==4){
    pwm4.setPWM(arr[i][2][1],0,spin);  
    }
  }
  delay(100);
  for(int i=2;i<5;i++){
    if(arr[4][i][0]==4){
    pwm4.setPWM(arr[4][i][1],0,spin);  
    }
    else if(arr[4][i][0]==3){
    pwm3.setPWM(arr[4][i][1],0,spin);  
    }
  }
  delay(100);
 for(int i=4;i>1;i++){
    if(arr[i][4][0]==3){
    pwm3.setPWM(arr[i][4][1],0,spin);  
    }
    else if(arr[i][4][0]==2){
    pwm2.setPWM(arr[i][4][1],0,spin);  
    }
  }
  delay(100);
  pwm3.setPWM(arr[3][3][1],0,spin);
  delay(100);
}

// row wave..............................................................
void rotaterow(int spin){
  for(int i = 0; i<7 ;i++){
  if(arr[0][i][0] == 1){
    pwm1.setPWM(arr[0][i][1],0,spin);
    }
   else if(arr[0][i][0] == 2){
    pwm2.setPWM(arr[0][i][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[1][i][0] == 1){
    pwm1.setPWM(arr[1][i][1],0,spin);
    }
   else if(arr[1][i][0] == 2){
    pwm2.setPWM(arr[1][i][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[2][i][0] == 1){
    pwm1.setPWM(arr[2][i][1],0,spin);
    }
   else if(arr[2][i][0] == 2){
    pwm2.setPWM(arr[2][i][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[3][i][0] == 4){
    pwm4.setPWM(arr[3][i][1],0,spin);
    }
   else if(arr[3][i][0] == 3){
    pwm3.setPWM(arr[3][i][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[4][i][0] == 4){
    pwm4.setPWM(arr[4][i][1],0,spin);
    }
   else if(arr[4][i][0] == 3){
    pwm3.setPWM(arr[4][i][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[5][i][0] == 4){
    pwm4.setPWM(arr[5][i][1],0,spin);
    }
   else if(arr[5][i][0] == 3){
    pwm3.setPWM(arr[5][i][1],0,spin);
    } 
     delay(15);
  }
  for(int i = 0; i<7 ;i++){
  if(arr[6][i][0] == 4){
    pwm4.setPWM(arr[6][i][1],0,spin);
    }
   else if(arr[6][i][0] == 3){
    pwm3.setPWM(arr[6][i][1],0,spin);
    } 
     delay(15);
  }
  }
// diagonal wave..............................................
void wave(int s1, int s2){
  int i,j ;
  for(i=0;i<7;i++){
    for(j=0;j<7;j++){
        if(i==j){
          if(i==0 && j==0){
            pwm1.setPWM(arr[0][0][1],0,s1);
            delay(75);
            pwm1.setPWM(arr[0][0][1],0,s2);
            delay(75);
          }
          else if(i==1 && j==1){
            pwm1.setPWM(arr[2][0][1],0,s1);
            pwm1.setPWM(arr[1][1][1],0,s1);
            pwm1.setPWM(arr[0][2][1],0,s1);
            delay(75);
            pwm1.setPWM(arr[2][0][1],0,s2);
            pwm1.setPWM(arr[1][1][1],0,s2);
            pwm1.setPWM(arr[0][2][1],0,s2);
            delay(75);
          }
          else if(i==2 && j==2){
            pwm4.setPWM(arr[4][0][1],0,s1);
            pwm4.setPWM(arr[3][1][1],0,s1);
            pwm1.setPWM(arr[2][2][1],0,s1);
            pwm2.setPWM(arr[1][3][1],0,s1);
            pwm2.setPWM(arr[0][4][1],0,s1);
           delay(75);
            pwm4.setPWM(arr[4][0][1],0,s2);
            pwm4.setPWM(arr[3][1][1],0,s2);
            pwm1.setPWM(arr[2][2][1],0,s2);
            pwm2.setPWM(arr[1][3][1],0,s2);
            pwm2.setPWM(arr[0][4][1],0,s2);
            delay(75);
            
          }
          else if(i==3 && j==3){
            pwm4.setPWM(arr[6][0][1],0,s1);
            pwm4.setPWM(arr[5][1][1],0,s1);
            pwm4.setPWM(arr[4][2][1],0,s1);
            pwm3.setPWM(arr[3][3][1],0,s1);
            pwm2.setPWM(arr[2][4][1],0,s1);
            pwm2.setPWM(arr[1][5][1],0,s1);
            pwm2.setPWM(arr[0][6][1],0,s1);
            delay(75);
            pwm4.setPWM(arr[6][0][1],0,s2);
            pwm4.setPWM(arr[5][1][1],0,s2);
            pwm4.setPWM(arr[4][2][1],0,s2);
            pwm3.setPWM(arr[3][3][1],0,s2);
            pwm2.setPWM(arr[2][4][1],0,s2);
            pwm2.setPWM(arr[1][5][1],0,s2);
            pwm2.setPWM(arr[0][6][1],0,s2);
            delay(75);
          }
          else if(i==4 && j==4){
            pwm4.setPWM(arr[6][2][1],0,s1);
            pwm3.setPWM(arr[5][3][1],0,s1);
            pwm3.setPWM(arr[4][4][1],0,s1);
            pwm3.setPWM(arr[3][5][1],0,s1);
            pwm2.setPWM(arr[2][6][1],0,s1);
            delay(75);
            pwm4.setPWM(arr[6][2][1],0,s2);
            pwm3.setPWM(arr[5][3][1],0,s2);
            pwm3.setPWM(arr[4][4][1],0,s2);
            pwm3.setPWM(arr[3][5][1],0,s2);
            pwm2.setPWM(arr[2][6][1],0,s2);
            delay(75);
          }
          else if(i==5 && j==5){
            pwm3.setPWM(arr[6][4][1],0,s1);
            pwm3.setPWM(arr[5][5][1],0,s1);
            pwm3.setPWM(arr[4][6][1],0,s1);
            delay(75);
            pwm3.setPWM(arr[6][4][1],0,s2);
            pwm3.setPWM(arr[5][5][1],0,s2);
            pwm3.setPWM(arr[4][6][1],0,s2);
            delay(75);
          }
          else if(i==6 && j==6){
            pwm3.setPWM(arr[6][6][1],0,s1);
           delay(75);
            pwm3.setPWM(arr[6][6][1],0,s2);
            delay(75);
          }
    }
    else if (i!=j){
      if(i==0 && j==1){
        pwm1.setPWM(arr[0][1][1],0,s1);
        pwm1.setPWM(arr[1][0][1],0,s1);
        delay(75);
        pwm1.setPWM(arr[0][1][1],0,s2);
        pwm1.setPWM(arr[1][0][1],0,s2);
        delay(75); 
      }
      else if(i==1 && j==2){
        pwm4.setPWM(arr[3][0][1],0,s1);
        pwm1.setPWM(arr[2][1][1],0,s1);
        pwm1.setPWM(arr[1][2][1],0,s1);
        pwm2.setPWM(arr[0][3][1],0,s1);
        delay(75);
        pwm4.setPWM(arr[3][0][1],0,s2);
        pwm1.setPWM(arr[2][1][1],0,s2);
        pwm1.setPWM(arr[1][2][1],0,s2);
        pwm2.setPWM(arr[0][3][1],0,s2);
        delay(75); 
      }
      else if(i==2 && j==3){
        pwm4.setPWM(arr[5][0][1],0,s1);
        pwm4.setPWM(arr[4][1][1],0,s1);
        pwm4.setPWM(arr[3][2][1],0,s1);
        pwm2.setPWM(arr[2][3][1],0,s1);
        pwm2.setPWM(arr[1][4][1],0,s1);
        pwm2.setPWM(arr[0][5][1],0,s1);
        delay(75);
        pwm4.setPWM(arr[5][0][1],0,s2);
        pwm4.setPWM(arr[4][1][1],0,s2);
        pwm4.setPWM(arr[3][2][1],0,s2);
        pwm2.setPWM(arr[2][3][1],0,s2);
        pwm2.setPWM(arr[1][4][1],0,s2);
        pwm2.setPWM(arr[0][5][1],0,s2);
        delay(75);
      }
      else if(i==3 && j==4){
        pwm4.setPWM(arr[6][1][1],0,s1);
        pwm4.setPWM(arr[5][2][1],0,s1);
        pwm3.setPWM(arr[4][3][1],0,s1);
        pwm3.setPWM(arr[3][4][1],0,s1);
        pwm2.setPWM(arr[2][5][1],0,s1);
        pwm2.setPWM(arr[1][6][1],0,s1);
        delay(75);
        pwm4.setPWM(arr[6][1][1],0,s2);
        pwm4.setPWM(arr[5][2][1],0,s2);
        pwm3.setPWM(arr[4][3][1],0,s2);
        pwm3.setPWM(arr[3][4][1],0,s2);
        pwm2.setPWM(arr[2][5][1],0,s2);
        pwm2.setPWM(arr[1][6][1],0,s2);
        delay(75); 
      } 
      else if(i==4 && j==5){
        pwm4.setPWM(arr[6][3][1],0,s1);
        pwm3.setPWM(arr[5][4][1],0,s1);
        pwm3.setPWM(arr[4][5][1],0,s1);
        pwm2.setPWM(arr[3][6][1],0,s1);
        delay(75);
        pwm4.setPWM(arr[6][3][1],0,s2);
        pwm3.setPWM(arr[5][4][1],0,s2);
        pwm3.setPWM(arr[4][5][1],0,s2);
        pwm2.setPWM(arr[3][6][1],0,s2);
        delay(75);
      }
      else if(i==5 && j==6){
        pwm3.setPWM(arr[6][5][1],0,s1);
        pwm3.setPWM(arr[5][6][1],0,s1);
        delay(75);
        pwm3.setPWM(arr[6][5][1],0,s2);
        pwm3.setPWM(arr[5][6][1],0,s2);
        delay(75); 
      }

    }
  }

}
}

// inverse diagonal wave.......................................
void invwave(int s1, int s2){
  int i,j ;
  for(i=6;i>=0;i--){
    for(j=6;j>=0;j--){
        if(i==j){
          if(i==0 && j==0){
            pwm1.setPWM(arr[0][0][1],0,s1);
            delay(75);
            pwm1.setPWM(arr[0][0][1],0,s2);
            delay(75);
          }
          else if(i==1 && j==1){
            pwm1.setPWM(arr[2][0][1],0,s1);
            pwm1.setPWM(arr[1][1][1],0,s1);
            pwm1.setPWM(arr[0][2][1],0,s1);
            delay(75);
            pwm1.setPWM(arr[2][0][1],0,s2);
            pwm1.setPWM(arr[1][1][1],0,s2);
            pwm1.setPWM(arr[0][2][1],0,s2);
            delay(75);
          }
          else if(i==2 && j==2){
            pwm4.setPWM(arr[4][0][1],0,s1);
            pwm4.setPWM(arr[3][1][1],0,s1);
            pwm1.setPWM(arr[2][2][1],0,s1);
            pwm2.setPWM(arr[1][3][1],0,s1);
            pwm2.setPWM(arr[0][4][1],0,s1);
           delay(75);
            pwm4.setPWM(arr[4][0][1],0,s2);
            pwm4.setPWM(arr[3][1][1],0,s2);
            pwm1.setPWM(arr[2][2][1],0,s2);
            pwm2.setPWM(arr[1][3][1],0,s2);
            pwm2.setPWM(arr[0][4][1],0,s2);
            delay(75);
            
          }
          else if(i==3 && j==3){
            pwm4.setPWM(arr[6][0][1],0,s1);
            pwm4.setPWM(arr[5][1][1],0,s1);
            pwm4.setPWM(arr[4][2][1],0,s1);
            pwm3.setPWM(arr[3][3][1],0,s1);
            pwm2.setPWM(arr[2][4][1],0,s1);
            pwm2.setPWM(arr[1][5][1],0,s1);
            pwm2.setPWM(arr[0][6][1],0,s1);
            delay(75);
            pwm4.setPWM(arr[6][0][1],0,s2);
            pwm4.setPWM(arr[5][1][1],0,s2);
            pwm4.setPWM(arr[4][2][1],0,s2);
            pwm3.setPWM(arr[3][3][1],0,s2);
            pwm2.setPWM(arr[2][4][1],0,s2);
            pwm2.setPWM(arr[1][5][1],0,s2);
            pwm2.setPWM(arr[0][6][1],0,s2);
            delay(75);
          }
          else if(i==4 && j==4){
            pwm4.setPWM(arr[6][2][1],0,s1);
            pwm3.setPWM(arr[5][3][1],0,s1);
            pwm3.setPWM(arr[4][4][1],0,s1);
            pwm3.setPWM(arr[3][5][1],0,s1);
            pwm2.setPWM(arr[2][6][1],0,s1);
            delay(75);
            pwm4.setPWM(arr[6][2][1],0,s2);
            pwm3.setPWM(arr[5][3][1],0,s2);
            pwm3.setPWM(arr[4][4][1],0,s2);
            pwm3.setPWM(arr[3][5][1],0,s2);
            pwm2.setPWM(arr[2][6][1],0,s2);
            delay(75);
          }
          else if(i==5 && j==5){
            pwm3.setPWM(arr[6][4][1],0,s1);
            pwm3.setPWM(arr[5][5][1],0,s1);
            pwm3.setPWM(arr[4][6][1],0,s1);
            delay(75);
            pwm3.setPWM(arr[6][4][1],0,s2);
            pwm3.setPWM(arr[5][5][1],0,s2);
            pwm3.setPWM(arr[4][6][1],0,s2);
            delay(75);
          }
          
    }
    else if (i!=j){
      if(i==0 && j==1){
        pwm1.setPWM(arr[0][1][1],0,s1);
        pwm1.setPWM(arr[1][0][1],0,s1);
        delay(75);
        pwm1.setPWM(arr[0][1][1],0,s2);
        pwm1.setPWM(arr[1][0][1],0,s2);
        delay(75); 
      }
      else if(i==1 && j==2){
        pwm4.setPWM(arr[3][0][1],0,s1);
        pwm1.setPWM(arr[2][1][1],0,s1);
        pwm1.setPWM(arr[1][2][1],0,s1);
        pwm2.setPWM(arr[0][3][1],0,s1);
        delay(75);
        pwm4.setPWM(arr[3][0][1],0,s2);
        pwm1.setPWM(arr[2][1][1],0,s2);
        pwm1.setPWM(arr[1][2][1],0,s2);
        pwm2.setPWM(arr[0][3][1],0,s2);
        delay(75); 
      }
      else if(i==2 && j==3){
        pwm4.setPWM(arr[5][0][1],0,s1);
        pwm4.setPWM(arr[4][1][1],0,s1);
        pwm4.setPWM(arr[3][2][1],0,s1);
        pwm2.setPWM(arr[2][3][1],0,s1);
        pwm2.setPWM(arr[1][4][1],0,s1);
        pwm2.setPWM(arr[0][5][1],0,s1);
        delay(75);
        pwm4.setPWM(arr[5][0][1],0,s2);
        pwm4.setPWM(arr[4][1][1],0,s2);
        pwm4.setPWM(arr[3][2][1],0,s2);
        pwm2.setPWM(arr[2][3][1],0,s2);
        pwm2.setPWM(arr[1][4][1],0,s2);
        pwm2.setPWM(arr[0][5][1],0,s2);
        delay(75);
      }
      else if(i==3 && j==4){
        pwm4.setPWM(arr[6][1][1],0,s1);
        pwm4.setPWM(arr[5][2][1],0,s1);
        pwm3.setPWM(arr[4][3][1],0,s1);
        pwm3.setPWM(arr[3][4][1],0,s1);
        pwm2.setPWM(arr[2][5][1],0,s1);
        pwm2.setPWM(arr[1][6][1],0,s1);
        delay(75);
        pwm4.setPWM(arr[6][1][1],0,s2);
        pwm4.setPWM(arr[5][2][1],0,s2);
        pwm3.setPWM(arr[4][3][1],0,s2);
        pwm3.setPWM(arr[3][4][1],0,s2);
        pwm2.setPWM(arr[2][5][1],0,s2);
        pwm2.setPWM(arr[1][6][1],0,s2);
        delay(75); 
      } 
      else if(i==4 && j==5){
        pwm4.setPWM(arr[6][3][1],0,s1);
        pwm3.setPWM(arr[5][4][1],0,s1);
        pwm3.setPWM(arr[4][5][1],0,s1);
        pwm2.setPWM(arr[3][6][1],0,s1);
        delay(75);
        pwm4.setPWM(arr[6][3][1],0,s2);
        pwm3.setPWM(arr[5][4][1],0,s2);
        pwm3.setPWM(arr[4][5][1],0,s2);
        pwm2.setPWM(arr[3][6][1],0,s2);
        delay(75);
      }
      else if(i==5 && j==6){
        pwm3.setPWM(arr[6][5][1],0,s1);
        pwm3.setPWM(arr[5][6][1],0,s1);
        delay(75);
        pwm3.setPWM(arr[6][5][1],0,s2);
        pwm3.setPWM(arr[5][6][1],0,s2);
        delay(75); 
      }

    }
  }

}
}

// PIR initialization.............
int ir = 8;
int irvalue;

void setup(){
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm1.begin();
  pwm2.begin();
  pwm3.begin();
  pwm4.begin();
  pinMode(ir,INPUT);
  /*
   * In theory the internal oscillator (clock) is 25MHz but it really isn't
   * that precise. You can 'calibrate' this by tweaking this number until
   * you get the PWM update frequency you're expecting!
   * The int.osc. for the PCA9685 chip is a range between about 23-27MHz and
   * is used for calculating things like writeMicroseconds()
   * Analog servos run at ~50 Hz updates, It is importaint to use an
   * oscilloscope in setting the int.osc frequency for the I2C PCA9685 chip.
   * 1) Attach the oscilloscope to one of the PWM signal pins and ground on
   *    the I2C PCA9685 chip you are setting the value for.
   * 2) Adjust setOscillatorFrequency() until the PWM update frequency is the
   *    expected value (50Hz for most ESCs)
   * Setting the value here is specific to each individual I2C PCA9685 chip and
   * affects the calculations for the PWM update frequency. 
   * Failure to correctly set the int.osc value will cause unexpected PWM results
   */
  pwm1.setOscillatorFrequency(27000000);
  pwm1.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  pwm2.setOscillatorFrequency(27000000);
  pwm2.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  pwm3.setOscillatorFrequency(27000000);
  pwm3.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  pwm4.setOscillatorFrequency(27000000);
  pwm4.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
}

// You can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. It's not precise!


void loop() {

  irvalue=digitalRead(ir);
  Serial.println(irvalue);
  if (irvalue==0){
    wave(245,220);
    delay(200);
    invwave(195,220);
    delay(200);
    rotaterow(195);
    delay(200);
    rotatecolumn(245);
    delay(200);
    wave(245,220);
    delay(200);
    invwave(195,220);
    delay(200);

    rotaterow(195);
    delay(200);
    circleloop(245);
    delay(200);

    rotatecolumn(195);
    delay(200);
    
  }
  else if (irvalue==1){
    rotaterow(220);
    delay(200);
  }
  irvalue=1;
  delay(10);
  }
