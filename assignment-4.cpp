// PHYS 30762 Programming in C++
// Assignment 4
// Practice special functions and operators in C++ classes
// Note that the hints in the skeleton are given to help you
// in case of doubt, the official guidance/marking scheme is on the slides on BB 

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

// // Beginning of particle class
// class particle
// {
// private:
//   string particle_name;
//   //...other data members (see slides on BB)
//   // We need the four-vector, you can leave the particle mass (or remove it, we don't mark it)


// public:
//   // Constructors
//   // Here you need a default constructor, a parameterised constructor and a copy constructor
//   // The parameterised constructor needs to dynamically allocate the std::vector containing the four-vector elements
//   // The parameterised constructor also needs to check the validity of the energy component
//   // The copy constructor needs to make a deep copy of the std::vector holding the 4-momentum

//   // Destructor
//   // The destructor needs to free the memory allocated by the constructor

//   // Assignment operator
//   // The assignment operator needs to avoid self-assignment using the *this pointer

//   // Move constructor
//   // The move constructor needs to correctly steal the memory from the object you're calling it on
  
//   // Move assignment operator
//   // The move assignment operator needs to correctly reassign the memory from the original object
  
//   // Getter functions (accessors) to individual elements of 4-momentum
//   // This should include function returning beta value 

//   // Setter functions, to change values of 4-momentum 
//   // Make sure you check input validity for the energy in the 4-momentum 

//   // Function to print info about a particle 
//   // (not necessary or marked, but nice as you can extend the one you already have from Assignment 3)
//   void print_data();

// };

// Implementation of functions goes here

// End of particle class and associated member functions

// Main program
int main()
{
  // Constants
  const double electron_rest_mass{0.51099895}; // MeV
  const double muon_rest_mass{105.6583755}; // MeV

  // Create a vector of particles:
  // two electrons, four muons, one antielectron, one antimuon
  // std::vector<particle> particles;

  // particles.emplace_back("electron", electron_rest_mass, 1, 613.1, 1.34, 0, 0);
  // particles.emplace_back("electron", electron_rest_mass, 1, 34.1, 0, 4.56, 0);
  // particles.emplace_back("muon", muon_rest_mass, 1, 81.6, 0, 0, 5.63);
  // particles.emplace_back("muon", muon_rest_mass, 1, 984.2, 234.1, 0, 0);
  // particles.emplace_back("muon", muon_rest_mass, 1, 489.21, 0, 23.4, 0);
  // particles.emplace_back("muon", muon_rest_mass, 1, 92.7, 0, 0, 451.2);
  // particles.emplace_back("electron", electron_rest_mass, -1, 712.1, 827.3, 0, 0);
  // particles.emplace_back("muon", muon_rest_mass, -1, 121.1, 0, 9.120, 0);

  // Print out the data from all the particles
  // print_all_particle_info(particles);

  // Sum the four-momenta of the two electrons
  particle e1{"electron", electron_rest_mass, 1, 613.1, 1.34, 0, 6.1};
  particle e2{"electron", electron_rest_mass, 1, 34.1, 0, 4.56, 0};
  // particle summed_particle{e1+e2};
  // std::cout<<"Sum of momenta for first two electrons: ";
  // summed_particle.print_four_momentum();
  // Do the dot product of the first two four-muons
  // particle m1{"muon", muon_rest_mass, 1, 1, 2, 3, 4};
  // particle m2{"muon", muon_rest_mass, 1, 2000, 200, 20, 2};
  // std::cout<<"Dot product of first two muons: "
  //          <<m1.dot_product(m2)<<" (Mev/c)^2"<<std::endl;
  // Assignment operator of an electron to a new electron
  std::cout<<std::endl<<"e3:"<<std::endl;
  particle e3 = e1;
  e3.print_data();
  e1.set_type("muon");
  e3.print_data();

  std::cout<<std::endl<<"e4:"<<std::endl;
  particle e4;
  e4 = e2;
  e4.print_data();
  e2.set_charge(-1);
  e4.print_data();
  // Copy constructor of the first muon to a new muon
  // Move the antielectron into another antielectron using the move constructor 
  // Assign the antimuon to another antimuon using the move assignment

  // (optional but nice) Here or at the end of each step, print the new particle info
  // to convince yourself that you have used all special functions and operations correctly

  return 0;
}