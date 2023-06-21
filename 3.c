#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fact(int n) {
if (n == 0) {
return 1;
} else {
return n * fact(n - 1);
}
}

int fib(int n) {
if (n <= 0) {
return 0;
} else if (n == 1) {
return 1;
} else {
return fib(n - 1) + fib(n - 2);
}
}


int main(int argc, char* argv[]) {
int n = atoi(argv[1]);
pid_t pid = fork();
if (pid == -1) {
printf("Error");
} else if (pid == 0) {
printf("Child <%d> with parent <%d>:\nFactorial of %d is %d\n", (int)getpid(), (int)getppid(), n, fact(n));
} else {
printf("Parent process <%d>:\nFibonacci of %d is %d\n", (int)getpid(), n, fib(n));
}
return 0;
}
