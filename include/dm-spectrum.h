#ifndef INCLUDE_DM_SPECTRUM_H_
#define INCLUDE_DM_SPECTRUM_H_

#include <string>
#include <vector>

#include "cgs.h"

enum Channel {
	e = 2, mu = 5, tau = 8, q = 9, c = 10, b = 11, t = 12, W = 15, Z = 18, h = 21
};

class DM_Spectrum {
protected:
	const std::vector<Channel> DM_channels = { e, tau, q, c, b, t, W, Z, h };
	const std::string m_filename = "AtProduction_gammas.txt";
	Channel m_channel;
	int m_mass;
	double M2C_DM;
	std::vector<std::pair<double, double> > spectrum;

protected:
	void load_table(size_t icol);

public:
	DM_Spectrum(Channel channel, int mass) :
			m_channel(channel), m_mass(mass) {
		load_table((int) m_channel);
		M2C_DM = (double) m_mass * cgs::GeV;
	}

	~DM_Spectrum() = default;

	double get(const double E_gamma) const;

	const double mass() const {
		return M2C_DM;
	}
};

#endif
