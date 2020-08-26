/*
	Test for the PDOB - Periodic-Disturbance Observer.
	@author: Hisayoshi Muramatsu
	@date: 2020.08.26
*/

#include <vector>
#include <math.h>

#include "PDOB.hpp"

PDOB::PDOB(
		double IN_Tk,
		double IN_gp,
		double IN_gam,
		double IN_HatOmega
	):Tk(IN_Tk), gp(IN_gp), gam(IN_gam), HatOmega(IN_HatOmega)
{

	LPFQ_InZ1 = 0.0; LPFQ_OutZ1 = 0.0;

	DelayCount = 0; DelayNum = 0; DelayCountReset = (int)(2*M_PI/HatOmega/Tk);
	std::vector<double> IN_DelayMemory((int)((2*M_PI/HatOmega+0.1)/Tk));
	DelayMemory = IN_DelayMemory;
}

double PDOB::Qfilter(double E) {
	double HatD(0.0), HatDp(0.0);
	int N = 0;
	// LPF for disturbance estimation
	HatD = PDOB::FirstOrderLPFQ(E);
	// Discrete delay
	N = (int)((2*M_PI*gp*gam-HatOmega)/(Tk*gp*HatOmega*gam));
	// Periodic-disturbance estimation
	HatDp = HatD - gam*(HatD - Delay(HatD, N));
	// Estimated periodic disturbance
	return HatDp;
}

double PDOB::FirstOrderLPFQ(double E) {
	double LPFQ_In(0.0), LPFQ_Out(0.0);
	double a(0.0), b(0.0), c(0.0), d(0.0);
	// LPF Coefficients
	a = 2 + gp*Tk;
	b = 2 - gp*Tk;
	c = gp*Tk;
	d = gp*Tk;
	// Disturbance error
	LPFQ_In = E;
	// LPF computation
	LPFQ_Out = (b/a)*LPFQ_OutZ1 + (c/a)*LPFQ_In + (d/a)*LPFQ_InZ1;
	LPFQ_InZ1  = LPFQ_In;
	LPFQ_OutZ1 = LPFQ_Out;
	// Estimated disturbance
	return LPFQ_Out;
}

double PDOB::Delay(double HatD, int N) {
	// Storage of estimated disturbance
	DelayMemory[DelayCount] = HatD;
	// Delayed count computation
	DelayNum = DelayCount - N;
	if(DelayNum<0){
		DelayNum = DelayNum + DelayCountReset + 1;
		if(DelayNum<0){
			std::cout<<"Error: The estimated delay (N) exceeded the maximum delay (MaxDelayTime)"<<std::endl;
			exit(1);
		}
	}
	DelayCount++;
	if(DelayCount > DelayCountReset) DelayCount = 0;
	// Delayed estimated disturbance
	return DelayMemory[DelayNum];
}















