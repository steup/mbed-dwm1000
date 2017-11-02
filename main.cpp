#include "mbed.h"

PwmOut led1(LED1);
DigitalOut led2(LED2);
SPI spi(SPI_MISO, SPI_MOSI, SPI_SCK);
DigitalOut cs(SPI_CS);


// main() runs in its own thread in the OS
int main() {
	printf("Hello World!\n");
	// delselect chip (nSS = high)
	cs = 1;
	// set up SPI for mode 0
	spi.format(8, 0);
	spi.frequency(1000000);
	
	// start transmission
	cs = 0;
	uint32_t answer = 0;
	// answer should contain the device id
	answer +=  spi.write(0x0) << (3*8);
	answer += spi.write(0x0) << (2*8);
	answer += spi.write(0x0) << (1*8);
	answer += spi.write(0x0);
	cs = 1;
	printf("%lx\n", (unsigned long int) answer);

	if(answer != 0) {
		led2 != led2;
	}


	led1.period(2.0f);
	led1.write(0.3f);
    while (true) {
    }
}
