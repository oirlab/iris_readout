#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "cfitsio/fitsio.h"
#include "iris_readout.h"
/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}

static void first_test(void **state) {
    (void) state; /* unused */
    fitsfile *fptr;  /* FITS file pointer */
	int status = 0;  /* CFITSIO status value MUST be initialized to zero! */
	int bitpix=0;
	int hdutype, naxis, i,j,k,in;
	long naxes[4], totpix, fpixel[4],nelem,nelem_image;
	int *pix;
	int time[4] = {0,4,8,12};
	float *output;
	char *filename = "../data/sample_ramp.fits";
	
	fpixel[0]=1;
	fpixel[1]=1;
	fpixel[2]=1 ;
	fpixel[3]=1 ;
	
	
	fits_open_file(&fptr,filename, READONLY, &status);
	fits_get_img_dim(fptr, &naxis, &status);
	fits_get_img_size(fptr, 4, naxes, &status);
	fits_get_img_type(fptr, &bitpix, &status);
	
	
	printf("Total number of axis %d \n",naxis);  
	printf("Axis 1 %lu \n",naxes[0]);      
	printf("Axis 2 %lu\n",naxes[1]);  
	printf("Axis 3 %lu \n",naxes[2]); 
	printf("Axis 4 %lu \n",naxes[3]); 
	printf("Bits %d \n",bitpix);
	
	
	nelem= naxes[0]*naxes[1]*naxes[2];
	nelem_image= naxes[0]*naxes[1];
	
	
	//pix = (double *) malloc(nelem* sizeof(double));
	pix = (int *) malloc(nelem* sizeof(int));
	
	fits_read_pix(fptr, TINT, fpixel, nelem,0, pix,0, &status); 
	
	output=uptheramp(pix, time, 4, 10, 10 );

    
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(first_test)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
