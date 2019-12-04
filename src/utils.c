#include "os.h"
#include "cx.h"
#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"
#include "menu.h"

int addResponseCode(unsigned char* buffer, int buffer_length, int response_code) {
    if (buffer_length < 2) {
        PRINTF("Output buffer is too small");
        THROW(0x6000);
    }
    buffer[0] = (response_code >> 8) & 0xFF;
    buffer[1] = response_code & 0xFF;
    return 2;
}

unsigned int ui_prepro(const bagl_element_t *element) {
    unsigned int display = 1;
    PRINTF("ui_prepro for element at %x of type %d\n", element, element->component.type);
    if (element->component.userid > 0) {
        display = (ux_step == element->component.userid - 1);
        if (display) {
            if (element->component.userid == 1) {
                UX_CALLBACK_SET_INTERVAL(2000);
            }
            else {
            //    UX_CALLBACK_SET_INTERVAL(MAX(3000, 1000 + bagl_label_roundtrip_duration_ms(element, 7)));
            }
        }
    }
    return display;
}
