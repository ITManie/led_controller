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

#define RX_FILTER 0

void APPLICATION() {
	// Enable SPI
	enableSPI();
	setRFmode(_WPE | _RX_STD | _TX_STD);
	// Wait Packed End active so the toutRF can be set to minimum
	toutRF = 1;

	// Main cycle (perpetually repeated)
	while(1) {
		// RF signal detection (takes cca 1ms)
		if(checkRF(RX_FILTER)) {
			// If anything was received
			if(RFRXpacket()) {
				// LED indication
				pulseLEDR();
				// Copy received RF data from bufferRF to bufferCOM
				copyBufferRF2COM();
				// Data dend via SPI
				startSPI(DLEN);
			}
		}

		// Update SPIstatus, check SPI busy
		if (getStatusSPI()) {
			// Wait until message is picked up
			continue;
		}

		// Anything received?
		if (_SPIRX) {
			// CRCM matched?
			if (_SPICRCok) {
				// Data lenght
				DLEN = SPIpacketLength;
				// Copy received SPI data from bufferCOM to bufferRF
				copyBufferCOM2RF();
				PIN = 0;
				// Transmit the message
				RFTXpacket();
				// LED indication
				pulseLEDG();
			}
			// Restart SPI communication
			startSPI(0);
		}
	}
}
