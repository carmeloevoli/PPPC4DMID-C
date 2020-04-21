#include "dm-profile.h"
#include "dm-spectrum.h"
#include "cgs.h"

#include <cmath>
#include <iostream>

int main() { 	// CGS UNITS

	std::shared_ptr<gNFW> nfw;
	{
		double M_200 = 0.7 * 8e11 * cgs::sun_mass; // Battaglia et al., 2005, MNRAS, 364 (converted to M_200)
		double c = 18; // Battaglia et al., 2005, MNRAS, 364
		double gamma_slope = 1.; // NFW

		nfw = std::make_shared<gNFW>(gamma_slope, c, M_200);
	}

	std::shared_ptr<DM_Spectrum> spectrum;
	{
		Channel channel = Channel::mu;
		double MC2_DM = 100 * cgs::GeV;
		spectrum = std::make_shared<DM_Spectrum>(channel, (int) (MC2_DM / cgs::GeV));
	}

	double emissivity = 0;
	{
		double sigma_v = 3e26 * cgs::cm3 / cgs::sec;
		double E_gamma = 10. * cgs::GeV;
		double position = 8.1 * cgs::kpc;

		emissivity = 0.5 * sigma_v * std::pow(cgs::c_light, 4) / std::pow(spectrum->mass(), 2.);
		emissivity *= spectrum->get(E_gamma);
		emissivity *= std::pow(nfw->get(position), 2.);
	}

	double units = 1. / cgs::GeV / cgs::cm3 / cgs::sec; // sr!
	std::cout << emissivity / units << "\n";
	return 0;
}

