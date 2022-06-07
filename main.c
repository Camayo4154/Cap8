/*
 * main.c
 *
 *  Created on: 19 Ara 2021
 *      Author: Ali
 */

#include <sys/ioctl.h>
#include <i2c-lcd.h>

int fd;

int row=0;
int col=0;

int main() {
	fd = open(I2C_DEVICE_FILE_PATH,O_RDWR);

    if ( fd < 0) {
        perror("No se pudo abrir el archivo.\n");
        return -1;
    }

    /*set the I2C slave address  */
    if (ioctl(fd,I2C_SLAVE,SLAVE_ADDRESS_LCD) < 0) {
            perror("Fallo en i2c esclavo.\n");
            close(fd);
            return -1;
    }

    lcd1602_init();

    lcd1602_sendString("Hola");
    sleep(1);
    lcd1602_setCursorPosition(1, 0);
    lcd1602_sendString("Andres Cano");


	return 0;
}
