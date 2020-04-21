#include "dm-profile.h"
#include <cmath>
#include <gsl/gsl_integration.h>

static const double f_gNFW(const double& x, const double& gamma) {
	return 1. / std::pow(x, gamma) / std::pow(1 + x, 3 - gamma);
}

gNFW::gNFW(double gamma, double c, double M_200) :
		m_gamma(gamma), m_c(c), m_M_200(M_200) {
	init();
}

double I_func(double x, void * params) {
	double gamma = *(double *) params;
	return x * x * f_gNFW(x, gamma);
}

double I(double c, double gamma) {
	gsl_integration_workspace * w = gsl_integration_workspace_alloc(1000);
	double result, error;
	gsl_function F;
	F.function = &I_func;
	F.params = &gamma;
	gsl_integration_qags(&F, 0, c, 0, 1e-7, 1000, w, &result, &error);
	gsl_integration_workspace_free(w);

	return result;
}

void gNFW::init() {
	m_R_200 = std::pow(3. * m_M_200 / 4. / M_PI / 200. / rho_cr, 1. / 3.); // definition of virial radius at 200 kpc
	m_r_s = m_R_200 / ((2. - m_gamma) * m_c);
	m_rho_s = 200. * rho_cr * std::pow(m_c, 3) / 3. / I(m_c, m_gamma);
}

double gNFW::get(const double& r) const {
	auto x = r / m_r_s;
	return m_rho_s * f_gNFW(x, m_gamma);
}
