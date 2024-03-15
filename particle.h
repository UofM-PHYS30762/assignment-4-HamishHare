// PHYS 30762 Programming in C++
// Assignment 4
// Implementing the header file for the 'particle' class
// Hamish Hare

#ifndef PARTICLE_H
#define PARTICLE_H

#include <string>
#include <vector>
using std::string;

class particle {
private:
  const double speed_of_light = 2.99792458e8; // in m/s, speed of light in vacuum

  string particle_type{"electron"};
  double rest_mass{0.51099895}; // in Mev
  int charge{1}; // multiples of -e
  std::vector<double> *four_momentum_p = new std::vector<double>{0.0, 0.0, 0.0, 0.0};

  // Validation functions
  void validate_type(); // .. particle type
  void validate_mass(); // .. rest mass
  void validate_charge(); // .. charge
  void validate_energy(); // .. 4-momentum energy
  void validate_all(); // .. all the above

public:
  // Constructors
  // .. Default constructor
  particle() = default;
  // .. Parameterised constructor
  particle(const string& type, const double& mass, const int& charge_quanta,
           const double& energy, const double& px, const double& py, const double& pz);
  // Copy constructor
  particle(const particle& particle_to_copy);
  // Destructor
  ~particle();

  // Getter functions
  string get_type() const {return particle_type;}
  string get_name() const; // adapt the particle name if it's an anti-particle
  double get_rest_mass() const {return rest_mass;}
  int get_charge() const {return charge;}
  double get_energy() const {return (*four_momentum_p)[0];}
  double get_px() const {return (*four_momentum_p)[1];}
  double get_py() const {return (*four_momentum_p)[2];}
  double get_pz() const {return (*four_momentum_p)[3];}

  // Setter functions, to change value of data members
  void set_type(const string& type){particle_type = type; validate_type();}
  void set_rest_mass(const double& mass){rest_mass = mass; validate_mass();}
  void set_charge(const int& charge_quanta){charge = charge_quanta; validate_charge();}
  void set_energy(const double& energy){(*four_momentum_p)[0]=energy; validate_energy();}
  void set_px(const double& px){(*four_momentum_p)[1]=px;}
  void set_py(const double& py){(*four_momentum_p)[2]=py;}
  void set_pz(const double& pz){(*four_momentum_p)[3]=pz;}

  // Functions to print info about a particle
  // .. full information
  void print_data() const;
  // .. just four momenta
  void print_four_momentum() const;

  // Addition operator overload
// .. returns a new particle with the summed four momenta of this
// .. particle with that of a given other particle
  particle operator+(const particle &other_particle) const;

  // Dot product
  // .. returns a double with the dot_product of this particle's four
  // .. momenta with that of a given other particle (doesn't set anything)
  double dot_product(const particle &other_particle) const;
};

#endif // PARTICLE_H
