# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

Author: Yuan-Yao Huang

The PID control project is my 9th project for Udacity's Self-Driving Car Engineer Nanodegree Program. You can find more information from the [original repository](https://github.com/udacity/CarND-PID-Control-Project/).

---

## 1. Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## 2. Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

---


## 3. Project Reflections

### 3.1 Overview

In this project, a PID controller for steering control is implemented in C++. For each time step, the simulator provides **speed**, **steering angle**, and **cross track error**. The cross track error (CTE) is the error from our desired position in the track. **The steering angle should be between -1 and 1.** The angle of the wheel is between -25 and 25. The following conditional statement is used to keep the steering angle output in the range.

```c++

	if (fabs(total_error) > 1.0) {
		if (total_error > 0) {
			total_error = 1.0;
		} else {
			total_error = -1.0;
		}
	}

```

### 3.2 Control Gain Description

The effect of each parameter and the tuning rule is described below.

* **P (proportional gain)**

This gain directly reflect how many error we have. If this parameter is too large, the system tends to have big overshoot, oscillations or even become unstable. If it's too small, it will take a longer time to get to the desired set point.

* **I (integral gain)**

The parameter that sets how much we take into consideration the cumulative error over time. This is often used when we have steady state errors. If the value is too large, the system tends to oscillate more. Here we use a very small value(even 0 is perfectly okay here) because it seems that there is no apparent drift.

* **D (derivative gain)**

This parameter considers the rate of change in the error. If the error is rapidly approaching zero, this parameter will attempt to slow things down to avoid overshooting. If this is too large, it will take longer to reach the desired goal.

### 3.3 Parameter Tuning

The final hyper parameters:
**Kp = 0.24**
**Ki = 0.001**
**Kd = 4**

The final hyper parameters were chosen by trial and error, but the parameter tuning follows the following some basic rules. We start from P value, the other values are set to be zeros. The P gain is increase untill the system resposes fast enough. If there are too much oscillations, either the proportional gain was reduced a bit or the derivative gain was increased until it behaves well. Then we increase integral gain a little bit till the steady state error is eliminated. In the future, a twiddle algorithm can be implemented to automate the tunung process. Adding another controller for the pedal is also possible.


