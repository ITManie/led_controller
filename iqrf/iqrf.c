/**
 * Copyright (C) 2016 Roman Ondráček
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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
