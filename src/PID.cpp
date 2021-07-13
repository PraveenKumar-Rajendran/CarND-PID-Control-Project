#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  
  // Initialize coeffs with the passing arguments
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  // Initializing PID Errors to zero
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0; 

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

  // Differential error.
  d_error = cte - p_error;  // difference in the Cross track error between current and previous time
  // Proportional error
  p_error = cte;            // Cross track error at a given time
  // Integral error
  i_error += cte;           // Cross track error accumlated over the entire time

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */

  return p_error * Kp + i_error * Ki + d_error * Kd;  // TODO: Add your total error calc here!
}

double PID::ControlInput() {
  /**
   * TODO: Calculate control input for steering using PID
   */
  
  double control_input = - TotalError();
// steering value must be between [-1, 1]
  control_input = control_input < -1 ? -1 : control_input;  // For the lower limit
  control_input = control_input > 1 ? 1 : control_input; // For the upper limit
 
  return control_input;  // TODO: Add your total error calc here!
}