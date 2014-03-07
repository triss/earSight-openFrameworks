#ifndef _RGB_TO_COLOUR_MAGS
#define _RGB_TO_COLOUR_MAGS

#define WHITE_CUTOFF 	0 
#define BLACK_CUTOFF 	0 
#define BLUE_CUTOFF  	0.2 
#define YELLOW_CUTOFF 	0.2
#define RED_CUTOFF 		0 
#define GREEN_CUTOFF  	0 
#define GREY_CUTOFF  	0 

#include "colorspace.h"

#ifndef MIN
	#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#endif

#ifndef MAX
	#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#endif

void rgbToColourMags(
		double * white, double * black, double * grey,
		double * green, double * red, double * blue, double * yellow,
		int r, int g, int b
); 

#endif
