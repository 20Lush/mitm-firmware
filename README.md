# mitm-firmware

-> modified hidboot library to allow for more modern report descriptors (btn 4/5 + scroll wheel integration)

-> modified Mouse library to more accurately send spoofed report descriptors

-> confirmed working for logitech superlight bt

-> pass-thru functionality working (btn4/5 still broken)


todo::

  _> get btn4/5 chatter fixed, probably a problem with the outgoing mouse report descriptor
  
  _> serial interfacing with the img processing host
  
  _> bi-lateral integration of serial interface corrective values with pass-thru
  
  _> exception checking
  
  _> humanizer engine
  
  
planned::

  +> port scanner & 1-tap firmware loader
  
  +> soft/hard switch paradigm for selective activation
  
  +> full documentation on serial string format so that I never have to open this repo ever again
  
