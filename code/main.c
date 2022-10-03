#include <stdio.h>

int main() {
  // creating an array of size 10.
  int memory[10];

  // now trying to access the 11th element.
  printf("%d\n", memory[10]);

  // let's see what happens if we update the 11th element.
  memory[10] = 10;

  // let's see what happens if we access the 11th element again.
  printf("%d\n", memory[10]);

  return 0; 
}
