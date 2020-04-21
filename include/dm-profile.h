#ifndef INCLUDE_DM_PROFILE_H_
#define INCLUDE_DM_PROFILE_H_

#include "cgs.h"

class gNFW {
protected:
	const double rho_cr = 9.1e-30 * cgs::gram / cgs::cm3; // WMAP-9
// provided from input
	double m_gamma;
	double m_M_200;
	double m_c;
// derived
	double m_R_200;
	double m_rho_s;
	double m_r_s;

protected:
	void init();

public:
	gNFW(double gamma, double c, double M_200);
	~gNFW() = default;
	double get(const double& r) const;
};

#endif /* INCLUDE_DM_PROFILE_H_ */
