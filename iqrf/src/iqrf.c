#include "iqrf/template-basic.h"

void APPLICATION() {
	enableSPI();
	setRFmode(_WPE | _RX_STD | _TX_STD);
	toutRF = 1;
   
	while(1) {
		if(checkRF(0)) {
			if(RFRXpacket()) {
				pulseLEDR();
				copyBufferRF2COM();
				startSPI(DLEN);
			}
		}
		if (getStatusSPI()) {
			continue;
		}
		if (_SPIRX) {
			if (_SPICRCok) {
 				DLEN = SPIpacketLength;
				copyBufferCOM2RF();
				PIN = 0;
				RFTXpacket();
				pulseLEDG();
			}
			startSPI(0);
		}
	}
}
