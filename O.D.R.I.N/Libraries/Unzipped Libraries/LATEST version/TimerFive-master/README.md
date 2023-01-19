TimerFive
=========

Interrupt and PWM utilities for 16 bit Timer 5 on ATmega1280.

The code was simply taken from the http://ebrequad.googlecode.com/ project:    
http://ebrequad.googlecode.com/svn/trunk/TestSWs/Balancer/TimerFive.h    
http://ebrequad.googlecode.com/svn/trunk/TestSWs/Balancer/TimerFive.cpp

I spent some time looking for this library since it was not bundled in a single library.
So I simply copied it into a single library in the hope it would be easier for people to
find it. An alternative to this library is the Timer5 library found in:    
https://github.com/carlosrafaelgn/ArduinoTimer

It's an adaptation of the TimerOne and TimerThree libraries available here:    
http://playground.arduino.cc/code/timer1    
http://www.pjrc.com/teensy/td_libs_TimerOne.html

Original code by Jesse Tane for http://labs.ideo.com August 2008    
Modified March 2009 by Jérôme Despatis and Jesse Tane for ATmega328 support    
Modified June 2009 by Michael Polli and Jesse Tane to fix a bug in setPeriod() which caused the timer to stop    
Modified March 2010 by Albert Sanz to make compatible with Arduino Mega Timer5
