#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int file1len =30; 

char file1[file1len][255];

const int file2len =10846; 

char file2[file2len][255];

int i, j, m, n, LCS_table[255][255];
char b[255][255];

int max = 0;

int tab[30];


void lcsAlgo(char * S1, char * S2, int tocos, int tocos2) {
  m = strlen(S1);
  n = strlen(S2);
  int k = 0;

  for (i = 0; i <= m; i++)
    LCS_table[i][0] = 0;
  for (i = 0; i <= n; i++)
    LCS_table[0][i] = 0;

  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) {
      if (S1[i - 1] == S2[j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j];
      } else {
        LCS_table[i][j] = LCS_table[i][j - 1];
      }
    }

  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
      k++;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }

  if(k > max)
  {
    max = k;
    tab[tocos2] = tocos;
  }
}

void koniec(char * S1, char * S2, int z) {
  m = 200;
  n = 200;

  for (i = 0; i <= m; i++)
    LCS_table[i][0] = 0;
  for (i = 0; i <= n; i++)
    LCS_table[0][i] = 0;

  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) {
      if (S1[i - 1] == S2[j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j];
      } else {
        LCS_table[i][j] = LCS_table[i][j - 1];
      }
    }

  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }

  if(strlen(lcsAlgo)>0)
  {
    z = z+1;
  printf("Correction %d: %s \nPan Tadeusz: %s \n", z, S1, S2);
  printf("LCS: %s\n", lcsAlgo);
  }
  // Printing the sub sequences
  
}

void readfile1()
{
  
  FILE* filePointer;
  int bufferLength = 255;
  char buffer[bufferLength];
  int i = 0; 

  filePointer = fopen("corrections.txt", "r");


  while(fgets(buffer, bufferLength, filePointer)) {
    
    strcpy(file1[i],buffer);
    ++i;
  }
  
  fclose(filePointer);
}

void readfile2()
{
  
  FILE* filePointer;
  int bufferLength = 255;
  char buffer[bufferLength];
  int i = 0; 

  filePointer = fopen("pan-tadeusz.txt", "r");


  while(fgets(buffer, bufferLength, filePointer)) {
    
    strcpy(file2[i],buffer);
    ++i;
  }
  
  fclose(filePointer);
}

int main() {

char S1[255] = "", S2[255] = "";

readfile1();
readfile2();

for(int j = 0; j<file1len; j++)
{
  max = 0;
for(int i = 0; i<file2len; i++)
{
  lcsAlgo(file1[j],file2[i],i,j);
}
i = tab[j];
koniec(file1[j],file2[i],j);
}

}