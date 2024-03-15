// PHYS 30762 Programming in C++
// Assignment 4
// Implementing the cpp file for the 'particle' class
// Hamish Hare

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include "particle.h"
using std::string;

// Function to convert strings to lowercase
static void to_lowercase(string& input_string)
{
  std::transform(input_string.begin(), input_string.end(), input_string.begin(),
                 [](unsigned char c){return std::tolower(c);});
}

// Validation functions
// .. particle type
// .. check that the particle type is either "electron" or "muon"
void particle::validate_type()
{
  // make particle_type lowercase
  to_lowercase(particle_type);
  // ensure its an acceptable input
  if(!(particle_type=="electron" || particle_type=="muon"))
  {
    std::cout<<"Provided type '"<<particle_type<<"' is not 'electron' or 'muon'";
    throw std::invalid_argument("Invalid particle type.");
  }
}
// .. rest mass
// .. check that the mass is not negative
void particle::validate_mass()
{
  if(rest_mass<=0)
  {
    std::cout<<"Particle masses must be positive. You entered "<<rest_mass;
    throw std::invalid_argument("Invalid particle mass.");
  }
}
// .. charge
// .. check that the charge is either 1 or -1
void particle::validate_charge()
{
  if(std::abs(charge)!=1)
  {
    std::cout<<"Particle charges must be 1 or -1. You entered "<<charge;
    throw std::invalid_argument("Invalid particle charge.");
  }
}
// .. energy
// .. check that the energy is not negative
void particle::validate_energy()
{
  double energy = (*four_momentum_p)[0];
  if(energy<0)
  {
    std::cout<<"Particle energies cannot be negative. You entered "<<energy;
    throw std::invalid_argument("Invalid particle energy.");
  }
}
// .. everything
void particle::validate_all()
{
  validate_type();
  validate_mass();
  validate_charge();
  validate_energy();
}

// Parameterised constructor
particle::particle(const string& type, const double& mass, const int& charge_quanta,
                   const double& energy, const double& px, const double& py,
                   const double& pz) :
                   particle_type{type}, rest_mass{mass}, charge{charge_quanta}
{
  std::cout<<"Calling parameterised constructor"<<std::endl;
  // Assign 4-momenta elements
  delete four_momentum_p;  // delete vector from class definition
  four_momentum_p = new std::vector<double>{energy, px, py, pz};
  validate_all();
}

// Copy constructor
particle::particle(const particle& particle_to_copy)
{
  std::cout<<"Calling copy constructor"<<std::endl;
  particle_type = particle_to_copy.particle_type;
  rest_mass = particle_to_copy.rest_mass;
  charge = particle_to_copy.charge;
  delete four_momentum_p; // delete vector from class definition
  four_momentum_p = new std::vector<double>{*(particle_to_copy.four_momentum_p)};
  validate_all();
}

// Destructor
particle::~particle()
{
  std::cout<<"Calling destructor"<<std::endl;
  delete four_momentum_p;
}

// Getter function for particle name (rest done in header)
// this adapts the particle type if it's an anti-particle
string particle::get_name() const
{
  if(charge < 0) return "anti"+particle_type;
  else return particle_type;
}

// Function to print info about a particle
void particle::print_data() const
{
  std::cout
  <<" -- Type: "<<particle_type<<std::endl
  <<" -- Rest Mass: "<<rest_mass<<" MeV"<<std::endl
  <<" -- Charge: "<<-charge <<" e"<<std::endl
  <<" -- Four momentum: ("<<(*four_momentum_p)[0]<<", "
                          <<(*four_momentum_p)[1]<<", "
                          <<(*four_momentum_p)[2]<<", "
                          <<(*four_momentum_p)[3]<<") MeV/c"<<std::endl;
}
