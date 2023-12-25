#include "LED_Bar.h"

LED_Bar::LED_Bar(PinName pinClk, PinName pinDta) : __pinClk(pinClk), __pinDta(pinDta)
{
    __led_state = 0x00;
}

void LED_Bar::latchData()
{
    __pinDta = 0;
    wait_us(10);

    for(int i=0; i<4; i++) {
        __pinDta = 1;
        __pinDta = 0;
    }

}

void LED_Bar::send16bitData(unsigned int data)
{
    for(int i=0; i<16; i++) {
        unsigned int state = data & 0x8000 ? 1 : 0;
        __pinDta = state;

        state = __pinClk ? 0 : 1;
        __pinClk = state;

        data <<= 1;
    }
}

void LED_Bar::ledIndexBit(unsigned int index_bits)
{

    send16bitData(CMDMODE);

    for (int i=0; i<12; i++) {
        unsigned int state = (index_bits&0x0001) ? ON : SHUT;
        send16bitData(state);

        index_bits = index_bits>>1;
    }

    latchData();
}

void LED_Bar::setLevel(int level)
{

    if(level>10)return;

    send16bitData(CMDMODE);

    for(int i=0; i<12; i++) {
        unsigned int state1 = (i<level) ? ON : SHUT;

        send16bitData(state1);
    }

    latchData();
}

void LED_Bar::setSingleLed(int num, int st)
{
    if(num>10)return;
    __led_state = st ? (__led_state | (0x01<<num)) : (__led_state & ~(0x01<<num));
    ledIndexBit(__led_state);

}