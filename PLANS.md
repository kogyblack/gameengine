Game Engine
===========

- Main Loop
- Video Rendering
- Handle Inputs
- Audio Mixer
- Logging / Debug IO
- 2D Physics
- Networking
- Threading

Main Loop
---------

WHILE running
  handleInputs
  gameUpdate
  renderVideo

Video Rendering
---------------

- Sprite
- Particle System
- Camera

Handle Inputs
-------------

- Keyboard and Mouse
- Controller/Joystick Support

Physics
-------

- AABB (Axis-Aligned Bounding Box)
- Circular Collision

Networking
----------

- UDP based connection

PACKET:
[uint32 protocol id]
[uint32 sequence number]
[uint32 ack]
[uint32 ack bitfield]
(packet data...)

See Gaffer on Games tutorials to understand:
http://gafferongames.com/networking-for-game-programmers/reliability-and-flow-control/

