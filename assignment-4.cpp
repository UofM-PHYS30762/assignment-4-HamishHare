// PHYS 30762 Programming in C++
// Assignment 4
// Practice special functions and operators in C++ classes
// Hamish Hare

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "particle.h"

using std::string;

// Function to print out all the particle information
void print_all_particle_info(std::vector<particle>& particles)
{
  std::cout<<"============================="<<std::endl
           <<"          PARTICLES"<<std::endl
           <<"============================="<<std::endl;
  int i{1};
  for(auto particle{particles.begin()}; particle<particles.end(); ++particle)
  {
    std::cout<<"Particle "<<i<<" ("<<particle->get_name()<<"):"<<std::endl
             <<"-----------------------------"<<std::endl;
    particle->print_data();
    std::cout<<"-----------------------------"<<std::endl;
    i++;
  }
}

// Main program
int main()
{
  // Constants
  const double electron_rest_mass{0.51099895}; // MeV
  const double muon_rest_mass{105.6583755}; // MeV

  // Create a vector of particles:
  // two electrons, four muons, one antielectron, one antimuon
  std::vector<particle> particles;

  particles.emplace_back("electron", electron_rest_mass, 1, 613.1, 1.34, 0, 0);
  particles.emplace_back("electron", electron_rest_mass, 1, 34.1, 0, 4.56, 0);
  particles.emplace_back("muon", muon_rest_mass, 1, 81.6, 0, 0, 5.63);
  particles.emplace_back("muon", muon_rest_mass, 1, 984.2, 234.1, 0, 0);
  particles.emplace_back("muon", muon_rest_mass, 1, 489.21, 0, 23.4, 0);
  particles.emplace_back("muon", muon_rest_mass, 1, 92.7, 0, 0, 451.2);
  particles.emplace_back("electron", electron_rest_mass, -1, 712.1, 827.3, 0, 0);
  particles.emplace_back("muon", muon_rest_mass, -1, 121.1, 0, 9.120, 0);

  // Print out the data from all the particles
  print_all_particle_info(particles);

  // Sum the four-momenta of the two electrons
  // .. intro
  std::cout<<"========================"<<std::endl
           <<"Overloading 'operator+':"<<std::endl
           <<"========================"<<std::endl;
  std::cout<<"Electon 1 momentum: ";
  particles[0].print_four_momentum();
  std::cout<<"Electon 2 momentum: ";
  particles[1].print_four_momentum();
  // .. result
  particle summed_particle{particles[0]+particles[1]};
  std::cout<<"Sum of momenta for first two electrons: ";
  summed_particle.print_four_momentum();
  std::cout<<"========================"<<std::endl;

  // Do the dot product of the first two four-muons
  // .. intro
  std::cout<<"========================"<<std::endl
           <<"Performing dot product:"<<std::endl
           <<"========================"<<std::endl;
  std::cout<<"Muon 1 momentum: ";
  particles[2].print_four_momentum();
  std::cout<<"Muon 2 momentum: ";
  particles[3].print_four_momentum();
  // .. result
  std::cout<<"Dot product of first two muons: "
           <<particles[2].dot_product(particles[3])
           <<" (Mev/c)^2"<<std::endl;
  std::cout<<"========================"<<std::endl;

  // Assignment operator of an electron to a new electron
  // .. intro
  std::cout<<"========================"<<std::endl
           <<"Copy assignment (=):"<<std::endl
           <<"========================"<<std::endl;
  std::cout<<"Electron to be copied:"<<std::endl;
  particles[1].print_data();
  // .. result
  particle assigned_electron;
  assigned_electron = particles[1];
  std::cout<<"Assigned electron info:"<<std::endl;
  assigned_electron.print_data();
  std::cout<<"========================"<<std::endl;

  // Copy constructor of the first muon to a new muon
  // .. intro
  std::cout<<"========================"<<std::endl
           <<"Using copy constructor:"<<std::endl
           <<"========================"<<std::endl;
  std::cout<<"Muon to be copied:"<<std::endl;
  particles[2].print_data();
  // .. result
  particle copy_constructed_muon{particles[2]};
  std::cout<<"Constructed muon info:"<<std::endl;
  copy_constructed_muon.print_data();
  std::cout<<"========================"<<std::endl;

  // Move the antielectron into another antielectron using the move constructor
  // .. intro
  std::cout<<"========================"<<std::endl
           <<"Using move constructor:"<<std::endl
           <<"========================"<<std::endl;
  std::cout<<"Antielectron to be moved:"<<std::endl;
  particles[6].print_data();
  // .. result
  particle move_constucted_antielectron{std::move(particles[6])};
  std::cout<<"New antielectron info:"<<std::endl;
  move_constucted_antielectron.print_data();
  std::cout<<"========================"<<std::endl;

  // Assign the antimuon to another antimuon using the move assignment
  // .. intro
  std::cout<<"========================"<<std::endl
           <<"Move assignment (=):"<<std::endl
           <<"========================"<<std::endl;
  std::cout<<"Antimuon to be moved:"<<std::endl;
  particles[7].print_data();
  // .. result
  particle assigned_antimuon;
  assigned_antimuon = std::move(particles[7]);
  std::cout<<"Assigned antimuon info:"<<std::endl;
  assigned_antimuon.print_data();
  std::cout<<"========================"<<std::endl;

  return 0;
}