# Rescue Project

🎥 Videos of the robot : https://drive.google.com/drive/folders/1nuJETroWs8m9KIOfO9hq21NwZyQXgBga?usp=sharing
## Session 1 - Thursday, February 20

**Power supply changes:**
The motor driver is now powered by a bench power supply, which supplies both motors and the Arduino board via its integrated 5V regulator. The chosen voltage is 9V to power the motors.

After this new wiring, both motors spin, and we can unplug the short Arduino cable which was limiting the robot’s movements. However, the motors do not spin at the same speed. The solution is to increase in the program the speed of the slower motor until both speeds balance. The robot can now move straight and also turn right and left.

**Motor testing:**

* Code snippet to control the two motors.

**Next session:**
Make the new sensor work and wire the ENA and ENB pins of the motor driver.

---

## Session 2

**Sensor setup:**
The sensor works but the robot reacts unpredictably. It can follow a straight line but turns randomly when it needs to adjust to stay on the line.

**Next session:**
Modify the program so the robot can readjust itself on the line when it loses it.

---

## Session 3

After program modifications, the robot works sometimes. It can follow straight lines and curves, but after turning off and on the power without changes, it fails to follow the line. Also, on a dashed line, it cannot follow straight.

**Current program:**

* \[Link to code]

**Next session:**
Make the robot consistently follow at least straight lines, maybe by changing sensor placement, lighting, or program.

---

## April 3rd Report

After some program adjustments, the robot can follow straight and curved lines but not tight turns.

**Current program:**

* \[Link to code]

**Next session:**

* Add a new sensor
* Use an Arduino Mega to add the new sensor
* Modify program and wiring accordingly

---

## May 15th Report

Reorganized robot cables: everything is now tidy and fixed on the robot.

**Upcoming modifications:**

* Add a "lost mode" in the program:

  * If the robot turns right or left, start a timer.
  * If timer > threshold, switch to lost mode (threshold to be defined after tests).
* The goal is to detect when lost mode should activate.
* Define lost mode behavior: stop, spin on the spot, etc.
* When the line is found again, revert to default line-following mode.

---

## May 22nd Report

Program rewritten as a state machine.
Tests and bug fixes done.
Robot works in state machine mode on straight lines and curves but not on sharp right-angle turns.

---

## Project Overview

This document describes the development stages of a robotics project aimed at creating a robot capable of autonomous movement by following a black line. It details the technological choices, methodology, and software used.

---

## 1. Reflective Analysis on the Choices

### 1.1 Chosen Components

* **Arduino Uno:** Easy to use with a large support community.
* **MotoDriver 2:** Robust control for two motors with flexible handling.
* **Motors:** Unknown model.

### 1.2 Methodology

Iterative approach:

1. Initial version development to validate concepts.
2. Adjustments based on observed performance.
3. Continuous improvements from feedback and analysis.

This ensures an optimized and robust final system.

---

## 2. Robot Programming

Divided into two main parts:

### 2.1 Move and Turn the Robot

**Responsible:** Marius
**Goal:** Enable the robot to move forward and turn.

**Hardware Assembly:**

* Arduino Uno
* MotoDriver 2 motor driver
* 2 motors

**Wiring:**

* Arduino to motor driver with 4 male-female cables.
* Motor driver to motors with male-male cables.
* Power supply: 9V battery connected to an Arduino breadboard powering all components.

Notes:

* MotoDriver 2 includes a 5V regulator.
* Wiring follows manufacturer manual with sample code.

**Programming:**
Arduino code controls wheel speed and direction.

**Test results:**

* First try: LEDs power on but motors don’t spin.
* After battery change, one motor runs but drains battery fast.
* Second try with wall adapter: motors run but movement is weak due to track friction.
* Using a computer power supply improved motor power.

---

### 2.2 Sensor Part (Sagesse) – Line Following

**Goal:** Create a robot that follows a black line using a color sensor.

**Steps:**

* Use TCS34725 RGB color sensor connected to Arduino.
* Test sensor output and calibrate for line detection.
* Use Adafruit library for sensor, installed via Arduino Library Manager.

**Challenges:**

* Library missing initially (fixed by installation).
* Lighting variations cause detection issues (solved with calibration and automatic threshold adjustment).

**Movement Logic:**

* If line detected center, move forward.
* If line detected left/right, slow one wheel and speed the other to turn.

**Improvement:**

* Add two side sensors to distinguish left/right line positions.

**Testing:**

* Used different tape colors and sizes.

---

## 3. Additional Problems and Solutions

* Losing the line: implemented automatic line search mode.
* Oscillations: tuned proportional (Kp) and derivative (Kd) factors to smooth movement.

---

## 4. Reflective Analysis

* Modular development helped solve problems efficiently.
* Real environment challenges: light variation and mechanical precision required continuous adjustments.
* Algorithmic approach showed importance of simple mathematical models.
* Teamwork was key: Sagesse handled sensors, Marius handled motor control.

---

## 5. Future Improvements

* Add more sensors for intersections or obstacles detection.
* Auto-tune parameters based on conditions.
* Improve power supply for longer autonomy.

---

## Conclusion

This project combines hardware and software to design an autonomous robot capable of efficient navigation. An iterative methodological approach allows continuous optimization and ensures project success.

---

