/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef _UART_CLASS_TWO_
#define _UART_CLASS_TWO_

#include "HardwareSerial.h"
#include "RingBuffer.h"

class UARTClassTwo : public HardwareSerial {
    public:
        //UARTClassTwo(int dwIrq, RingBuffer* pRx_buffer);
        UARTClassTwo(RingBuffer* pRx_buffer);
        void begin(const uint32_t dwBaudRate) { begin(dwBaudRate, SERIAL_8N1); }
        void begin(const uint32_t dwBaudRate, uint8_t serial_config_value);
        void end(void);
        int available(void);
        int peek(void);
        int read(void);
        void flush(void);
        size_t write(const uint8_t c);
        void IrqHandler(void);
        using Print::write; // pull in write(str) and write(buf, size) from Print
        operator bool() { return true; }; // UART always active

    protected:
        void init(const uint32_t dwBaudRate, const uint32_t config);
        RingBuffer *_rx_buffer;
        int _dwIrq;

    private:
        friend bool Serial2_available();
};

#if defined(BOARD_AITHINKER_BW16)
extern UARTClassTwo Serial1;
#else
extern UARTClassTwo Serial2;
#endif
#endif // _LOGUART_CLASS_
