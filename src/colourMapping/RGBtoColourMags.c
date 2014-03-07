#include "RGBtoColourMags.h" 
#include <math.h>

void rgbToColourMags(
		double * white, double * black, double * grey,
		double * green, double * red, 
		double * blue, double * yellow,
		int r, int g, int b
		) {
	
	// get CIELUV values from rgb
	double l, u, v;
	Rgb2Luv(&l, &u, &v, r, g, b);

	// calculate CIE chroma
	double cieChroma = sqrt((u * u) + (v * v));

	// calculate colour magnitudes
	*white = pow(l, 4) / 100000000;
	*black = pow(l - 100, 4) / 100000000;

	*red = MIN(u / 100, 1);
	*green = MAX(0, MIN(u * -1.0 / 80, 1));

	*blue = MIN((v * -1.0) / 15, 1);
	*yellow = MIN(v / 100, 1);

	*grey = pow((l * (l - 100.0) / 1000.0) / 2.5, 4)
		* pow((180 - cieChroma) / 180, 4);

	// reduce values that are too low to 0
	*white = MIN(*white, WHITE_CUTOFF);	
	*black = MIN(*black, BLACK_CUTOFF);	
	*red = MIN(*red, RED_CUTOFF);	
	*green = MIN(*green, GREEN_CUTOFF);	
	*blue = MIN(*blue, BLUE_CUTOFF);
	*yellow = MIN(*yellow, YELLOW_CUTOFF);
	*grey = MIN(*grey, GREY_CUTOFF);
}
