# led_controller

[![Build Status](https://travis-ci.org/ITManie/led_controller.svg?branch=master)](https://travis-ci.org/ITManie/led_controller)
[![Build Status](https://drone.io/github.com/ITManie/led_controller/status.png)](https://drone.io/github.com/ITManie/led_controller/latest)
[![wercker status](https://app.wercker.com/status/6b206508930a2a129e1ea5bb58755907/s "wercker status")](https://app.wercker.com/project/bykey/6b206508930a2a129e1ea5bb58755907)
[![GPLv3](http://img.shields.io/badge/license-GPLv3-blue.svg)](LICENSE)

Arduino project to control RGB LED strip

## Libraries

 * [IQRF](https://github.com/ITManie/IQRF_library)
 * [MsTimer2](https://github.com/PaulStoffregen/MsTimer2)

## Packets

### Echo controller
<table>
<tr>
<th>00-FF</th>
<th>100-1FF</th>
<th>200-2FF</th>
<th>300-3FF</th>
<th>400-4FF</th>
<th>500-5FF</th>
<th>600-6FF</th>
</tr>
<tr>
<td>version</td>
<td>type</td>
<td colspan="4">address</td>
<td>status</td>
</tr>
</table>

### Set color
<table>
<tr>
<th>00-FF</th>
<th>100-1FF</th>
<th>200-2FF</th>
<th>300-3FF</th>
<th>400-4FF</th>
<th>500-5FF</th>
<th>600-6FF</th>
<th>700-7FF</th>
<th>800-8FF</th>
<th>900-9FF</th>
</tr>
<tr>
<td>version</td>
<td>type</td>
<td colspan="4">address</td>
<td>red</td>
<td>green</td>
<td>blue</td>
<td>alpha</td>
</tr>
</table>
