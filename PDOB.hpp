/*
	Test for the PDOB - Periodic-Disturbance Observer.
	@author: Hisayoshi Muramatsu
	@date: 2020.08.26
*/

#ifndef DEF_PDOB
#define DEF_PDOB

class PDOB{
public:
	PDOB(
		// Sampling time [s]
	    double IN_Tk,
	    // Cutoff frequency for the Q-filter [rad/s]
	    double IN_gp,
	    // Design parameter for the Q-filter
	    double IN_gam,
	    // Fundamental frequency [rad/s]
	    double IN_HatOmega0
	);
	// Q-filter for periodic disturbance estimation
	double Qfilter(double E);

private:
	/*
	* Design parameters
	*/
	// Sampling time [s]
	const double Tk;
	// Cutoff frequency for the Q-filter [rad/s]
	const double gp;
	// Design parameter for the Q-filter
	const double gam;
	// Fundamental frequency of the periodic disturbance [rad/s]
	const double HatOmega;

	/*
	* Variables
	*/
	// Variables for computation
	double LPFQ_InZ1, LPFQ_OutZ1;
	// Variables for the delay
	int DelayCount, DelayNum, DelayCountReset;
	std::vector<double> DelayMemory;

	/*
	* Functions
	*/
	// Low-pass filter for the Q-filter
	double FirstOrderLPFQ(double E);
	//Delay
	double Delay(double HatD, int N);

};

#endif

