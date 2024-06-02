#include "env.h"

void clear_console() {
    system("clear");
}

void sleep_time(int time){
    usleep(time * 1000);  // usleep은 마이크로초 단위, 1초 = 1000밀리초 = 1000000마이크로초
}