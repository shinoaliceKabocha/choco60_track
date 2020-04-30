#ifndef SPLIT_COMM_H
#define SPLIT_COMM_H

#ifndef SERIAL_USE_MULTI_TRANSACTION
/* --- USE Simple API (OLD API, compatible with let's split serial.c) --- */
#include "serial.h"

#else
/* --- USE flexible API (using multi-type transaction function) --- */
// Buffers for master - slave communication
#define SERIAL_SLAVE_BUFFER_LENGTH MATRIX_ROWS/2
#define SERIAL_MASTER_BUFFER_LENGTH MATRIX_ROWS/2

extern volatile uint8_t serial_slave_buffer[SERIAL_SLAVE_BUFFER_LENGTH];
extern volatile uint8_t serial_master_buffer[SERIAL_MASTER_BUFFER_LENGTH];
extern uint8_t slave_buffer_change_count;

#endif

#endif /* SPLIT_COMM_H */
