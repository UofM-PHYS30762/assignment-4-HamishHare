// PHYS 30762 Programming in C++
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
void particle::validate_type()
{
  // make particle_type lowercase
  to_lowercase(particle_type);
  // ensure its an acceptable input
  if(!(particle_type=="electron" || particle_type=="muon"))
  {
    std::cout<<"Provided type "<<particle_type<<" is not 'electron' or 'muon'";
    throw std::invalid_argument("Invalid particle type.");
  }
}
// .. rest mass
void particle::validate_mass()
{
  if(rest_mass<=0)
  {
    std::cout<<"Particle masses must be positive. You entered "<<rest_mass;
    throw std::invalid_argument("Invalid particle mass.");
  }
}
// .. charge
void particle::validate_charge()
{
  if(std::abs(charge)!=1)
  {
    std::cout<<"Particle charges must be 1 or -1. You entered "<<charge;
    throw std::invalid_argument("Invalid particle charge.");
  }
}
// .. velocity
void particle::validate_velocity()
{
  if(std::abs(velocity)>speed_of_light)
  {
    std::cout<<"Particle velocity "<<velocity<<" m/s exceeds the speed of light";
    throw std::invalid_argument("Invalid particle velocity.");
  }
}

// Parameterised constructor
particle::particle(const string& type, const double& mass, const int& charge_quanta,
                   const double& particle_velocity) :
                   particle_type{type}, rest_mass{mass}, charge{charge_quanta},
                   velocity{particle_velocity}, beta{particle_velocity/speed_of_light}
{
  // Validation
  // .. check that the particle type is either "electron" or "muon"
  validate_type();
  // .. check that the particle speed doesn't exceed the speed of light
  validate_velocity();
  // .. check that the mass is not negative
  validate_mass();
  // .. check that the charge is either 1 or -1
  validate_charge();
}

// Getter function for particle name (rest done in header)
// this adapts the particle type if it's an anti-particle
string particle::get_name() const
{
  if(charge < 0) return "anti"+particle_type;
  else return particle_type;
}

// Setter function for velocity (rest done in header)
void particle::set_velocity(const double& particle_velocity) {
  velocity = particle_velocity;
  validate_velocity();
  beta = velocity / speed_of_light;
}

// Function to print info about a particle
void particle::print_data() const {
  std::cout
  << " -- Type: " << particle_type << std::endl
  << " -- Rest Mass: " << rest_mass << " MeV" << std::endl
  << " -- Charge: " << -charge << " e" << std::endl
  << " -- Velocity: " << velocity << " m/s" << std::endl
  << " -- Beta: " << beta << std::endl;
}
