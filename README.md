# GSM arduino Card Software
The Project is based on Arduino nano with SIM900A GSM module, which are connected to a batter, and keeps listening to the pump input, if the pump is turned off on purpose or the power is cut off form the source, they send a message to the defined number. 
A first order low pass filter is implemented to the input after that a schmitt trigger is applied to make the signal robust to noise.
