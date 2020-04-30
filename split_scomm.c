#ifdef USE_SERIAL
#ifdef SERIAL_USE_MULTI_TRANSACTION
/* --- USE flexible API (using multi-type transaction function) --- */

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <split_scomm.h>
#include "serial.h"
#ifdef CONSOLE_ENABLE
  #include <print.h>
#endif

uint8_t volatile serial_slave_buffer[SERIAL_SLAVE_BUFFER_LENGTH] = {0};
uint8_t volatile serial_master_buffer[SERIAL_MASTER_BUFFER_LENGTH] = {0};
uint8_t volatile status_com = 0;
uint8_t volatile status1 = 0;
uint8_t slave_buffer_change_count = 0;
uint8_t s_change_old = 0xff;
uint8_t s_change_new = 0xff;

SSTD_t transactions[] = {
#define GET_SLAVE_STATUS 0
    /* master buffer not changed, only recive slave_buffer_change_count */
    { (uint8_t *)&status_com,
      0, NULL,
      sizeof(slave_buffer_change_count), &slave_buffer_change_count,
    },
#define PUT_MASTER_GET_SLAVE_STATUS 1
    /* master buffer changed need send, and recive slave_buffer_change_count  */
    { (uint8_t *)&status_com,
      sizeof(serial_master_buffer), (uint8_t *)serial_master_buffer,
      sizeof(slave_buffer_change_count), &slave_buffer_change_count,
    },
#define GET_SLAVE_BUFFER 2
    /* recive serial_slave_buffer */
    { (uint8_t *)&status1,
      0, NULL,
      sizeof(serial_slave_buffer), (uint8_t *)serial_slave_buffer
    }
};

#endif // SERIAL_USE_MULTI_TRANSACTION
#endif /* USE_SERIAL */
