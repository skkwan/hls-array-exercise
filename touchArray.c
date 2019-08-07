/**************************************************************************/
/* touchArray.c                                                           */
/* Synthesis target                                                       */
/**************************************************************************/

#include "importArray.h"

void touchArray(float myArray[NROWS][NCOLS])
{
  int r, c;
  
  /* Touch the array by adding 0 to each element. */
  touchArray_label0:for (r = 0; r < NROWS; r++)
    {
      touchArray_label1:for (c = 0; c < NCOLS; c++)
	{
	  myArray[r][c] += 0.0;
	}
    }

}
