#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

#ifdef _OPENMP
#include <omp.h>
#endif

# ifdef _OPENMP
int my_rank = omp_get_thread_num( );
 int thread_count = omp_get_num_threads( );
# else
int my_rank = 0;
int thread_count = 1;
# endif

/**  Giulia Barbieri Quagliano TIA: 42013070
Jenifer Mathias dos Santos TIA: 32092946 */

double Local_trap(double a, double b, int n);

int main(int argc, char *argv[]) {
  double global_result = 0.0;
  double a, b;
  int n;
  int thread_count;

  thread_count = strtol(argv[1], NULL, 10);
  printf("Enter a, b, and n");
  scanf("%lf %lf %d", &a, &b, &n);
# pragma omp parallel num_threads(thread_count) \
    reduction(+ : global_result);
  global_result += Local_trap(a, b, n);

  printf("With n = %d trapezoids, our estimate\n", n);
  return 0;
}

int f(int num) {
    return 2 * num + 3 * num;
}

double Local_trap(double a, double b, int n) {
  double h, x, approx;

  h = (b - a) / n;
  n = n / thread_count;
  a = a + n * h;
  approx = (f(a) + f(b)) / 2.0;
# pragma omp parallel for num_threads(thread_count) \
    reduction(+ : approx)
  for (int i = 1; i <= n - 1; i++)
    approx += f(a + i * h);
  approx = h * approx;

    return approx;
}
