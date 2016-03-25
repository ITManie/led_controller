#include "iqrf/template.h"

void APPLICATION() {
	enableSPI();

	while (TRUE) {
		if (RFRXpacket()) {
			pulseLEDR();
			copyBufferRF2COM();
			startSPI(DLEN);
		}
	}
}
