# led-controller

[![Build Status](https://travis-ci.org/Roman3349/led-controller.svg?branch=master)](https://travis-ci.org/Roman3349/led-controller)
[![Build Status](https://drone.io/github.com/Roman3349/led-controller/status.png)](https://drone.io/github.com/Roman3349/led-controller/latest)
[![wercker status](https://app.wercker.com/status/6b206508930a2a129e1ea5bb58755907/s "wercker status")](https://app.wercker.com/project/bykey/6b206508930a2a129e1ea5bb58755907)
[![Gitter](https://badges.gitter.im/Roman3349/led-controller.svg)](https://gitter.im/Roman3349/led-controller?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
[![GPLv3](http://img.shields.io/badge/license-GPLv3-blue.svg)](LICENSE)

Arduino project to control RGB LED strip

## Arduino libraries

 * [IQRF](https://github.com/ITManie/IQRF_library)
 * [MsTimer2](https://github.com/PaulStoffregen/MsTimer2)

## Packets

### Ping
<table>
<tr>
<th>0-FF</th>
<th>100-1FF</th>
<th>200-2FF</th>
<th>300-3FF</th>
<th>400-4FF</th>
<th>500-5FF</th>
</tr>
<tr>
<td>version</td>
<td>type</td>
<td colspan="4">address</td>
</tr>
<tr>
<td>0</td>
<td>0</td>
<td>0-FF</td>
<td>0-FF</td>
<td>0-FF</td>
<td>0-FF</td>
</tr>
</table>

### Pong
<table>
<tr>
<th>0-FF</th>
<th>100-1FF</th>
<th>200-2FF</th>
<th>300-3FF</th>
<th>400-4FF</th>
<th>500-5FF</th>
</tr>
<tr>
<td>version</td>
<td>type</td>
<td colspan="4">address</td>
</tr>
<tr>
<td>0</td>
<td>1</td>
<td>0-FF</td>
<td>0-FF</td>
<td>0-FF</td>
<td>0-FF</td>
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
<tr>
<td>0</td>
<td>2</td>
<td>0-FF</td>
<td>0-FF</td>
<td>0-FF</td>
<td>0-FF</td>
<td>0-FF</td>
<td>0-FF</td>
<td>0-FF</td>
<td>0-1</td>
</tr>
</table>
