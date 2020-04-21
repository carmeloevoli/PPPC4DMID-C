#ifndef INCLUDE_CGS_H_
#define INCLUDE_CGS_H_

namespace cgs {

// CGS UNITS
static constexpr double second = 1;
static constexpr double centimeter = 1.;
static constexpr double gram = 1;
static constexpr double erg = gram * centimeter * centimeter / second / second;
static constexpr double kelvin = 1;
static constexpr double sr = 1;
static constexpr double gauss = 1;
static constexpr double esu = 1;
static constexpr double statvolt = erg / esu;
static constexpr double steradiant = 1;

// TIME UNITS
static constexpr double msec = 1e-3 * second;
static constexpr double year = 3.154e+7 * second;
static constexpr double kiloyear = 1e3 * year;
static constexpr double Megayear = 1e6 * year;
static constexpr double Gigayear = 1e9 * year;

// LENGTH UNITS
static constexpr double meter = 1e2 * centimeter;
static constexpr double kilometer = 1e3 * meter;
static constexpr double parsec = 3.086e16 * meter;
static constexpr double kiloparsec = 1e3 * parsec;
static constexpr double fm = 1e-13 * centimeter;

// MASS UNITS
static constexpr double mgram = 1e-3 * gram;
static constexpr double kilogram = 1e3 * gram;

// ENERGY UNITS
static constexpr double joule = 1e7 * erg;
static constexpr double electronvolt = 1.60217657e-19 * joule;
static constexpr double kiloelectronvolt = 1e3 * electronvolt;
static constexpr double megaelectronvolt = 1e6 * electronvolt;
static constexpr double gigaelectronvolt = 1e9 * electronvolt;
static constexpr double teraelectronvolt = 1e12 * electronvolt;
static constexpr double petaelectronvolt = 1e15 * electronvolt;

// em derived units
static constexpr double microgauss = 1e-6 * gauss;
static constexpr double milligauss = 1e-3 * gauss;
static constexpr double nanogauss = 1e-9 * gauss;
static constexpr double volt = statvolt / 299.792458;

// ABBREVIATION
static constexpr double sec = second;
static constexpr double km = kilometer;
static constexpr double kyr = kiloyear;
static constexpr double Myr = Megayear;
static constexpr double Gyr = Gigayear;
static constexpr double pc = parsec;
static constexpr double kpc = kiloparsec;
static constexpr double eV = electronvolt;
static constexpr double keV = kiloelectronvolt;
static constexpr double MeV = megaelectronvolt;
static constexpr double GeV = gigaelectronvolt;
static constexpr double TeV = teraelectronvolt;
static constexpr double PeV = petaelectronvolt;
static constexpr double cm = centimeter;
static constexpr double cm2 = cm * cm;
static constexpr double cm3 = cm * cm * cm;
static constexpr double m2 = meter * meter;
static constexpr double K = kelvin;

// PHYSICAL CONSTANTS
static constexpr double c_light = 2.99792458e10 * centimeter / second;
static constexpr double c_2 = c_light * c_light;
static constexpr double c_3 = c_light * c_light * c_light;
static constexpr double proton_mass = 1.67262158e-24 * gram;
static constexpr double proton_mass_c2 = proton_mass * c_2;
static constexpr double neutron_mass = 1.67492735e-24 * gram;
static constexpr double neutron_mass_c2 = neutron_mass * c_2;
static constexpr double electron_mass = 9.10938291e-28 * gram;
static constexpr double electron_mass_c2 = electron_mass * c_2;
static constexpr double sun_mass = 1.989e33 * gram;
static constexpr double h_planck = 6.62607015e-34 * joule * second;
static constexpr double k_boltzmann = 1.3806488e-23 * joule / kelvin;
static constexpr double electron_radius = 2.8179403227e-15 * meter;
static constexpr double elementary_charge = 4.80320427e-10;
static constexpr double sigma_th = 6.6524e-25 * cm2;
static constexpr double barn = 1e-24 * cm2;
static constexpr double mbarn = 1e-3 * barn;

} /* namespace cgs */

#endif /* INCLUDE_CGS_H_ */
