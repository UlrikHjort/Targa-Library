#include <stdio.h>
#include "targa.h"


int main() {

  int i,j;
  int height = 0;
  int width  = 0;

  BYTE buf[100][100][3];


  printf("*** Test 1: Draw white diagonal line on black background\n");
  /* Fill buffer with "Black": */
 for (i=0 ; i < 100; i++) {
    for (j=0 ; j < 100; j++) {
       buf[i][j][0] = 0;
       buf[i][j][1] = 0;
       buf[i][j][2] = 0;
    }
 }

 
 for (i=0 ; i < 100; i++) {
       buf[i][i][0] = 255;
       buf[i][i][1] = 255;
       buf[i][i][2] = 255;
 }
 
 save_targa("Test1.tga", buf,100,100);

  printf("*** Test 2: Draw blue diagonal line on black background\n");
  /* Fill buffer with "Black": */
 for (i=0 ; i < 100; i++) {
    for (j=0 ; j < 100; j++) {
       buf[i][j][0] = 0;
       buf[i][j][1] = 0;
       buf[i][j][2] = 0;
    }
 }

 for (i=0 ; i < 100; i++) {
       *buf[i][i] = 0x0000FF;
 }

 save_targa("Test2.tga", buf,100,100);

 return 0;
}
