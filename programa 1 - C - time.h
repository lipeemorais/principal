#include <stdio.h>
#include <time.h>

int main(){
    
    time_t segundos;
    
    segundos = time(NULL);
    
    printf("Segundos desde 1° de Janeiro de 1970 = %ld\n", segundos);
    
    return 0;
}

