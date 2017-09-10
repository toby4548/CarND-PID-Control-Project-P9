#include "PID.h"
#include <iostream>
#include <math.h>

using namespace std;

PID::PID(){}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	this -> Kp = Kp; //initialize proportional gain
	this -> Ki = Ki; //initialize integral gain
	this -> Kd = Kd; //initialize differential gain

}

void PID::UpdateError(double cte) {

	d_error = cte - p_error;
	p_error = cte;
	i_error = i_error + cte;

}

double PID::TotalError() {

	double total_error =- Kp * p_error - Kd * d_error - Ki * i_error;

	if (fabs(total_error) > 1.0) {
		if (total_error > 0) {
			total_error = 1.0;
		} else {
			total_error = -1.0;
		}
	}

	return total_error;

}


