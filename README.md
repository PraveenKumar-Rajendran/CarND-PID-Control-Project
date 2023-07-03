# CarND-Controls-PID

This project is part of the Self-Driving Car Engineer Nanodegree Program.

---

## Dependencies

* cmake >= 3.5
 * For installation instructions on all operating systems, [click here](https://cmake.org/install/)
* make >= 4.1 (mac, linux), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [Install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Installation instructions can be found here](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: Same process as make - [Install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: It is recommended to use [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If installing from source, checkout commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download it from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

If the environment you set up for the Sensor Fusion projects does not work for this project, fellow students have put together a [guide to Windows set-up](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) for this project. There's also an experimental patch for Windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repository.
2. Create a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run the program: `./pid`

For tips on setting up your environment, refer to the [Udacity classroom](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d).

## Editor Settings

Editor configuration files have been intentionally kept out of this repository to keep it simple and environment-agnostic. However, we recommend using the following settings:

* Indent using spaces.
* Set tab width to 2 spaces to maintain alignment of matrices in the source code.

## Code Style

Please adhere (to the best of your ability) to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Please note that regardless of the changes you make

, your project must be buildable using cmake and make.

Additional information and instructions are available only to students enrolled in Term 2 of the CarND program. If you are enrolled, refer to [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562) for instructions and the project rubric.



<br/><br/>
<h1 align="center"> Addressing Project Rubric </h1>

[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)
<h2 align="center">Compilation </h2>

<em>The code compiles without errors using cmake and make.</em>

<h2 align="center">Implementation </h2>

<em>The base algorithm follows what is presented in the lessons, and hyperparameter tuning/optimization is done manually.</em>

<h2 align="center">Reflection </h2>
<br/><br/>

<em>Describe the effect of each of the P, I, and D components in your implementation.</em>

A Proportional-Integral-Derivative (PID) controller is a control loop mechanism used in various applications, including industrial control systems. It employs feedback and consists of three terms: proportional (P), integral (I), and derivative (D). The controller continuously calculates an error value by comparing a desired setpoint (SP) to a measured process variable (PV) and applies a correction based on the weighted sum of the three terms. [Source: Wikipedia]

![](./results/PID_en.svg.png)

**Proportional (P)**

The proportional component sets the control input in proportion to the current cross-track error (CTE). However, if the proportional gain is set too high, the system becomes unstable.

**Integral (I)**

The integral component increases the action in relation to both the error and the duration for which it has persisted. This component is effective in eliminating systematic biases.

**Derivative (D)**

The derivative component considers the rate of change of the error and aims to bring this rate to zero. It flattens the error trajectory, reducing overshoot.

<br/><br/>

<em>Describe how the final hyperparameters were chosen.</em>

The parameters were selected through a trial-and-error approach based on an intuitive understanding of the impact of different values. Initially, the gains were set using the values presented in the PID implementation lecture by Sebastian Thrun. These values were then tuned to achieve the desired performance in the simulator environment.

Multiple iterations were performed, and the parameter values were continuously adjusted until the car could successfully and safely complete a lap. The table below shows some of the tested parameter combinations and their results:

| Kp  | Ki | Kd  | Result |
| --- | --- | --- | ------ |
| 0.1 | 0.001 | 1.8 | Fail |
| 0.15 | 0.001 | 1.8 | Fail |
| 0.12 | 0.001 | 1.8 | Fail |
| 0.09 | 0.001 | 1.8 | Pass |
| 0.1 | 0.001 | 1.8 | Pass |
| 0.13 | 0.001 | 1.8 | Good |
| 0.16 | 0.001 | 1.8 | Better |

`Note that the throttle value was modified between 0.18 and 0.3 for the above combinations and finally set to a constant value of 0.18 for stability.`

<h2 align="center">Simulation </h2>

<em>The vehicle successfully drives a lap around the track.</em>

A [simulation video](./results/PID_Final_Result_02.webm) has been recorded and attached in the results directory. The GIF below shows the result for one of the experimented parameter combinations:

![](./results/PID_Final_Result_1.5MB.gif)