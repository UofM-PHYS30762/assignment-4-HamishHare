// PHYS 30762 Programming in C++
// Implementing the header file for the 'particle' class
// Hamish Hare

#ifndef PARTICLE_H
#define PARTICLE_H

#include <string>
using std::string;

class particle {
private:
  const double speed_of_light = 2.99792458e8; // in m/s, speed of light in vacuum

  string particle_type{"electron"};
  double rest_mass{0.51099895}; // in Mev
  int charge{1}; // multiples of -e
  double velocity{0};
  double beta{velocity/speed_of_light};

  // Validation functions
  void validate_type(); // .. particle type
  void validate_mass(); // .. rest mass
  void validate_charge(); // .. charge
  void validate_velocity(); // .. velocity

public:
  // Constructors
  // .. Default constructor
  particle() = default;
  // .. Parameterised constructor
  particle(const string& type, const double& mass, const int& charge_quanta,
           const double& particle_velocity);
  // Destructor
  ~particle(){}

  // Getter functions
  string get_type() const {return particle_type;}
  string get_name() const; // adapt the particle name if it's an anti-particle
  double get_rest_mass() const {return rest_mass;}
  int get_charge() const {return charge;}
  double get_velocity() const {return velocity;}
  double get_beta() const {return beta;}

  // Setter functions, to change value of data members
  void set_type(const string& type){particle_type = type; validate_type();}
  void set_rest_mass(const double& mass){rest_mass = mass; validate_mass();}
  void set_charge(const int& charge_quanta){charge = charge_quanta; validate_charge();}
  void set_velocity(const double& particle_velocity); // set velocity and beta

  // Function to print info about a particle
  void print_data() const;
};

#endif // PARTICLE_H
