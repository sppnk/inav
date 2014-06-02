/*
 * drv_softserial.h
 *
 *  Created on: 23 Aug 2013
 *      Author: Hydra
 */

#pragma once

#define SOFT_SERIAL_BUFFER_SIZE 256

typedef enum {
    SOFTSERIAL1 = 0,
    SOFTSERIAL2
} softSerialPortIndex_e;

typedef struct softSerial_s {
    serialPort_t     port;

    const timerHardware_t *rxTimerHardware;
    volatile uint8_t rxBuffer[SOFT_SERIAL_BUFFER_SIZE];

    const timerHardware_t *txTimerHardware;
    volatile uint8_t txBuffer[SOFT_SERIAL_BUFFER_SIZE];
    
    uint8_t          isSearchingForStartBit;
    uint8_t          rxBitIndex;
    uint8_t          rxLastLeadingEdgeAtBitIndex;
    uint8_t          rxEdge;

    uint8_t          isTransmittingData;
    int8_t           bitsLeftToTransmit;

    uint16_t         internalTxBuffer;  // includes start and stop bits
    uint16_t         internalRxBuffer;  // includes start and stop bits

    uint16_t         transmissionErrors;
    uint16_t         receiveErrors;

    uint8_t          softSerialPortIndex;
} softSerial_t;

extern timerHardware_t* serialTimerHardware;
extern softSerial_t softSerialPorts[];

extern const struct serialPortVTable softSerialVTable[];

serialPort_t *openSoftSerial(softSerialPortIndex_e portIndex, serialReceiveCallbackPtr callback, uint32_t baud, serialInversion_e inversion);

// serialPort API
void softSerialWriteByte(serialPort_t *instance, uint8_t ch);
uint8_t softSerialTotalBytesWaiting(serialPort_t *instance);
uint8_t softSerialReadByte(serialPort_t *instance);
void softSerialSetBaudRate(serialPort_t *s, uint32_t baudRate);
bool isSoftSerialTransmitBufferEmpty(serialPort_t *s);
