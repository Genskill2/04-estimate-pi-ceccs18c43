#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int);

int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}
float mc_pi(int dart) {
  float x, y, dist, p_circle=0;
  for (int i=0; i<dart; i++) {
    x = frandom(i);
    y = frandom(i);
    dist = pow((pow(x, 2) + pow(y, 2)), 0.5);
    if(dist < 1) {
      p_circle++;
    }
  }
  return 4 * (p_circle / dart);
}


