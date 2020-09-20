/* srand example */
#include <iostream>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <windows.h>

int real_rand(){
    return rand()%20;
}

int main ()
{
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0;i<5;i++) std::cout << real_rand() << std::endl;
    return 0;
}

