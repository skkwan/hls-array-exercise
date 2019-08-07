/**************************************************************************/
/* importArray_test.c                                                     */
/* Test bench                                                             */
/**************************************************************************/

#include <stdio.h>
#include "importArray.h"

/* Reads numbers from a .txt file and stores them in an array of dimensions
   ROWS x COLS. */ 

int main() 
{
  FILE *inFile;
  FILE *outFile;

  float arrBuffer[NROWS * NCOLS];
  float arr[NROWS][NCOLS];
  int i, r, c;

  inFile = fopen("weights-MINI.txt", "r");
  if (inFile == NULL)
    {
      printf("File not found, exiting.\n");
      return 1;
    }
  
  /* fscanf() reads until it meets the newline character \n. */
  for (r = 0; r < NROWS; r++)
    {
      for (c = 0; c < NCOLS; c++)
	{
	  fscanf(inFile, "%f", &arr[r][c]);
	  // printf("%f", arr[r][c]);
	}
      // printf("\n");
    }

  fclose(inFile);
  printf("Done reading.\n");

  /* Touch the array (placeholder function so we have
     something to synthesize. */
  touchArray(arr);

  /* Now write the array back to another file. */
  outFile = fopen("weights-OUT.txt", "w");
  for (r = 0; r < NROWS; r++)
    {
      for (c = 0; c < NCOLS; c++)
	{
	  fprintf(outFile, "%1.1f ", arr[r][c]);
	}
      fprintf(outFile, "\n");
    }
  fprintf(outFile, "\n");
  fclose(outFile);

  printf("Comparing against the original table: \n");
  if (system("diff -w weights-OUT.txt weights-MINI.txt"))
    {
      fprintf(stdout, "*******************************************\n");
      fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
      fprintf(stdout, "*******************************************\n");
      return 1;
    }
  else
    {
      fprintf(stdout, "*******************************************\n");
      fprintf(stdout, "PASS: The output matches the golden output!\n");
      fprintf(stdout, "*******************************************\n");
      return 0;
    }
}




