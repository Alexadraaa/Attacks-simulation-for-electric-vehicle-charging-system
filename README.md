# Integrated Master's Thesis: “Interventions in Electric Vehicle Charging: System Development for Attacks Simulation”
In this thesis, an embedded system is designed and developed that achieves the simulation of the
operation of an electric vehicle charger, the implementation of hardware attacks in the form of a
malicious circuit that is introduced as an extension to the charging cable, and the implementation
of the electric vehicle that receives the respective attack. The research objective is to highlight the
needs for upgrading the security of electric vehicle charging. This implementation is carried out
through the Arduino UNO R3 microcontroller in combination with a set of sensors and tools for
controlling the system. The choice of the specific microcontroller is due to the need for simplicity
of design of the overall system. Also, since charging using a cable is studied, there was no need to
use wireless communication. An online platform was used to simulate the system at both hardware
and software levels. Through this and based on this specific simulation, proper operation control
procedures are carried out, the system performance is evaluated and a comparison is made with
similar implementations of attacks on electric vehicle charging. Furthermore, a personal computer
was used both for graphical visualization of the system and for writing the control code of the
microcontrollers used.
Explanatory, the proposed system that was developed consists of three main subsystems.
Initially, the central subsystem consists of an Arduino Uno microcontroller, which is responsible
for introducing the malicious circuit into the charging process, controlling the individual attacks,
as well as the temperature control subsystem. The Arduino Uno also contributes to smooth
communication between the subsystems. The proposed system includes two other main subsystems,
which are a charger simulation and a vehicle simulation. These actively participate in the charging
simulation process and demonstrate the operation of the basic subsystem and are also based on
two different Arduino Uno.
The charger simulation subsystem is represented in a simple way. Specifically, it consists of
an external 0-12V direct current voltage source, resistors and a RGB LED to display the charger
state. All of the above are controlled by an Arduino Uno.
The electric vehicle simulation subsystem is represented in a simple way to display the results
for the needs of the research. It consists of resistors, PN diodes, SPDT relays and light emitting
diodes (LEDs) to display the state.
The attack subsystem is inserted between the charger and vehicle subsystems, forming a
connecting link and simulating the attacks at the hardware level. The attack circuit also includes
the charging process without an attack since it is necessary for the continuity of the overall circuit
and the switching between attacks. The subsystem consists of NPN Transistors, resistors, diodes
PN and SPDT relays and aims to implement the state switching attack (SS attack) by manipulating
the charging voltage and the fake load attack by manipulating the duty cycle that comes from a
digital pin of the microcontroller and replaces the CP signal.
