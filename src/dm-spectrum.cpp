#include "dm-spectrum.h"
#include <cmath>
#include <fstream>
#include <iostream>

bool file_exists(const std::string& name) {
	std::ifstream f(name.c_str());
	return f.good();
}

void DM_Spectrum::load_table(size_t icol) {
	if (file_exists(m_filename)) {
		std::fstream file_to_read(m_filename);
		const int max_num_of_char_in_a_line = 512;
		file_to_read.ignore(max_num_of_char_in_a_line, '\n');
		size_t mDM_size = 62;
		size_t log10x_size = 179;
		int mDM;
		double log10x, spec[28];
		for (size_t i = 0; i < mDM_size; i++) {
			for (size_t j = 0; j < log10x_size; j++) {
				file_to_read >> mDM >> log10x;
				for (size_t k = 0; k < 28; k++)
					file_to_read >> spec[k];
				if (mDM == m_mass)
					spectrum.push_back(std::pair<double, double>(log10x, spec[icol]));
			}
		}
		if (spectrum.size() != log10x_size)
			throw std::runtime_error("mass value not found");
	} else {
		throw std::runtime_error("file for Dark Matter spectrum cannot be found.");
	}
}

double DM_Spectrum::get(const double E_gamma) const {

	auto lgx = std::log10(E_gamma / M2C_DM);

	if (lgx <= -8. || lgx >= 1.) {
		return 0;
	} else {
		auto lessThan = [](const std::pair<double, double>& point, double x)
		{	return point.first < x;};

		auto iter = std::lower_bound(spectrum.cbegin(), spectrum.cend(), lgx, lessThan);

		double upperX { iter->first };
		double upperY { iter->second };
		double lowerX { (iter - 1)->first };
		double lowerY { (iter - 1)->second };

		double deltaY { upperY - lowerY };
		double deltaX { upperX - lowerX };

		double dNdlog10x = lowerY + ((lgx - lowerX) / deltaX) * deltaY;
		return dNdlog10x / M_LN10 / E_gamma;
	}
}
