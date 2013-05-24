/*
 ******************************************************************
 * HISTORY
 * 15-Oct-94  Jeff Shufelt (js), Carnegie Mellon University
 *      Prepared for 15-681, Fall 1994.
 *
 ******************************************************************
 */

#include <stdio.h>
#include <pgmimage.h>
#include <backprop.h>

extern void exit();

#define TARGET_HIGH 0.9
#define TARGET_LOW 0.1


/*** This is the target output encoding for a network with one output unit.
     It scans the image name, and if it's an image of me (js) then
     it sets the target unit to HIGH; otherwise it sets it to LOW.
     Remember, units are indexed starting at 1, so target unit 1
     is the one to change....
 ***/

/*** Change for assignment Part I:
     If the image name describe a person wearing sunglasses, then
     it sets the target unit to HIGH; otherwise it sets it to LOW.
 ***/

load_target(img, net)
IMAGE *img;
BPNN *net;
{
  int scale;
  char userid[40], head[40], expression[40], eyes[40], photo[40];

  userid[0] = head[0] = expression[0] = eyes[0] = photo[0] = '\0';

  /*** scan in the image features ***/
  sscanf(NAME(img), "%[^_]_%[^_]_%[^_]_%[^_]_%d.%[^_]",
    userid, head, expression, eyes, &scale, photo);

  /*
   *  Initial project target:
   *  We want the network to recognize image with userid "glickman"
   */
  //if (!strcmp(userid, "glickman")) {
  //  net->target[1] = TARGET_HIGH;  /* it's me, set target to HIGH */
  //} else {
  //  net->target[1] = TARGET_LOW;   /* not me, set it to LOW */
  //}

  /*
   * Assignment Part I - "sunglasses" recognizer target:
   * We want the network to recognize images where people wear sunglasses
   */
  //  if (!strcmp(eyes, "sunglasses")) {
  //	  net->target[1] = TARGET_HIGH;   /* he's wearing sunglasses, set target to HIGH */
  //  } else {
  //	  net->target[1] = TARGET_LOW;    /* he's not wearing sunglasses, set target to LOW */
  //  }

  /*
   * Assignment Part I - 1-20 face recognizer target:
   * We want the network to recognize images of 20 different people
   */
//  if (strcmp(userid, "an2i") == 0) {
//	  net->target[1] = TARGET_HIGH;
//  } else {
//	  net->target[1] = TARGET_LOW;
//  }
//  if (strcmp(userid, "at33") == 0) {
//  	  net->target[2] = TARGET_HIGH;
//    } else {
//  	  net->target[2] = TARGET_LOW;
//    }
//  if (strcmp(userid, "boland") == 0) {
//  	  net->target[3] = TARGET_HIGH;
//    } else {
//  	  net->target[3] = TARGET_LOW;
//    }
//  if (strcmp(userid, "bpm") == 0) {
//  	  net->target[4] = TARGET_HIGH;
//    } else {
//  	  net->target[4] = TARGET_LOW;
//    }
//  if (strcmp(userid, "ch4f") == 0) {
//  	  net->target[5] = TARGET_HIGH;
//    } else {
//  	  net->target[5] = TARGET_LOW;
//    }
//  if (strcmp(userid, "cheyer") == 0) {
//  	  net->target[6] = TARGET_HIGH;
//    } else {
//  	  net->target[6] = TARGET_LOW;
//    }
//  if (strcmp(userid, "choon") == 0) {
//  	  net->target[7] = TARGET_HIGH;
//    } else {
//  	  net->target[7] = TARGET_LOW;
//    }
//  if (strcmp(userid, "danieln") == 0) {
//  	  net->target[8] = TARGET_HIGH;
//    } else {
//  	  net->target[8] = TARGET_LOW;
//    }
//  if (strcmp(userid, "glickman") == 0) {
//  	  net->target[9] = TARGET_HIGH;
//    } else {
//  	  net->target[9] = TARGET_LOW;
//    }
//  if (strcmp(userid, "karyadi") == 0) {
//  	  net->target[10] = TARGET_HIGH;
//    } else {
//  	  net->target[10] = TARGET_LOW;
//    }
//  if (strcmp(userid, "kawamura") == 0) {
//  	  net->target[11] = TARGET_HIGH;
//    } else {
//  	  net->target[11] = TARGET_LOW;
//    }
//  if (strcmp(userid, "kk49") == 0) {
//  	  net->target[12] = TARGET_HIGH;
//    } else {
//  	  net->target[12] = TARGET_LOW;
//    }
//  if (strcmp(userid, "megak") == 0) {
//  	  net->target[13] = TARGET_HIGH;
//    } else {
//  	  net->target[13] = TARGET_LOW;
//    }
//  if (strcmp(userid, "mitchell") == 0) {
//  	  net->target[14] = TARGET_HIGH;
//    } else {
//  	  net->target[14] = TARGET_LOW;
//    }
//  if (strcmp(userid, "night") == 0) {
//  	  net->target[15] = TARGET_HIGH;
//    } else {
//  	  net->target[15] = TARGET_LOW;
//    }
//  if (strcmp(userid, "phoebe") == 0) {
//  	  net->target[16] = TARGET_HIGH;
//    } else {
//  	  net->target[16] = TARGET_LOW;
//    }
//  if (strcmp(userid, "saavik") == 0) {
//  	  net->target[17] = TARGET_HIGH;
//    } else {
//  	  net->target[17] = TARGET_LOW;
//    }
//  if (strcmp(userid, "steffi") == 0) {
//  	  net->target[18] = TARGET_HIGH;
//    } else {
//  	  net->target[18] = TARGET_LOW;
//    }
//  if (strcmp(userid, "sz24") == 0) {
//  	  net->target[19] = TARGET_HIGH;
//    } else {
//  	  net->target[19] = TARGET_LOW;
//    }
//  if (strcmp(userid, "tammo") == 0) {
//  	  net->target[20] = TARGET_HIGH;
//    } else {
//  	  net->target[20] = TARGET_LOW;
//    }

  /*
   * Assignment Part I - Pose recognizer
   */
  if (strcmp(head, "straight") == 0) {
	  net->target[1] = TARGET_HIGH;
  } else {
	  net->target[1] = TARGET_LOW;
  }
  if (strcmp(head, "left") == 0) {
  	  net->target[2] = TARGET_HIGH;
    } else {
  	  net->target[2] = TARGET_LOW;
    }
  if (strcmp(head, "right") == 0) {
  	  net->target[3] = TARGET_HIGH;
    } else {
  	  net->target[3] = TARGET_LOW;
    }
  if (strcmp(head, "up") == 0) {
  	  net->target[4] = TARGET_HIGH;
    } else {
  	  net->target[4] = TARGET_LOW;
    }
}


/***********************************************************************/
/********* You shouldn't need to change any of the code below.   *******/
/***********************************************************************/

load_input_with_image(img, net)
IMAGE *img;
BPNN *net;
{
  double *units;
  int nr, nc, imgsize, i, j, k;

  nr = ROWS(img);
  nc = COLS(img);
  imgsize = nr * nc;;
  if (imgsize != net->input_n) {
    printf("LOAD_INPUT_WITH_IMAGE: This image has %d pixels,\n", imgsize);
    printf("   but your net has %d input units.  I give up.\n", net->input_n);
    exit (-1);
  }

  units = net->input_units;
  k = 1;
  for (i = 0; i < nr; i++) {
    for (j = 0; j < nc; j++) {
      units[k] = ((double) img_getpixel(img, i, j)) / 255.0;
      k++;
    }
  }
}
