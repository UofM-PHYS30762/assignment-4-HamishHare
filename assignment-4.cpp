// PHYS 30762 Programming in C++
// Assignment 4
// Practice special functions and operators in C++ classes
// Hamish Hare

#include <iostream>
#include <vector>
#include "particle.h"
#include "detector.h"

// Function to run a vector of particles through a detector
void pass_particles_through_detector(detector& current_detector,
                                     std::vector<particle>& particles)
{
  // .. turn detector on
  current_detector.turn_on();
  // .. pass particles through it
  for(auto particle{particles.begin()}; particle<particles.end(); ++particle)
  {
    current_detector.detect_particle(*particle);
  }
  // .. turn detector off
  current_detector.turn_off();
}

// Function to print out all the particle information
void print_all_particle_info(std::vector<particle>& particles)
{
  std::cout<<"============================="<<std::endl
           <<"          PARTICLES"<<std::endl
           <<"============================="<<std::endl;
  int i{1};
  for(auto particle{particles.begin()}; particle<particles.end(); ++particle)
  {
    std::cout<<"Particle "<<i<<" ("<<(*particle).get_name()<<"):"<<std::endl
             <<"-----------------------------"<<std::endl;
    (*particle).print_data();
    std::cout<<"-----------------------------"<<std::endl;
    i++;
  }
}

// Function to run given particles through given detectors
void run_particles_through_detectors(std::vector<detector>& detectors,
                                     std::vector<particle>& particles)
{
  std::cout<<std::endl
           <<"============================="<<std::endl
           <<"          DETECTION"<<std::endl
           <<"============================="<<std::endl;
  for(auto detector{detectors.begin()}; detector<detectors.end(); ++detector)
  {
    // .. print which detector is currently in use
    std::cout<<"For the "<<(*detector).get_detector_type()<<":"<<std::endl;
    std::cout<<"-----------------------------"<<std::endl;
    // .. pass the particles through it
    pass_particles_through_detector((*detector), particles);
    std::cout<<"-----------------------------"<<std::endl;
  }
}

// Function to provide a summary of the detector results after
// particles have been run through them
void print_detector_results(std::vector<detector>& detectors)
{
  std::cout<<std::endl
           <<"============================="<<std::endl
           <<"           SUMMARY"<<std::endl
           <<"============================="<<std::endl;
  // .. loop over each detector
  for(auto detector{detectors.begin()}; detector<detectors.end(); ++detector)
  {
    std::cout<<"For the "<<(*detector).get_detector_type()<<":"<<std::endl
             <<"-----------------------------"<<std::endl;
    (*detector).print_data();
    std::cout<<"-----------------------------"<<std::endl;
  }
}

int main() {
  // Constants
  const double electron_rest_mass{0.51099895}; // MeV
  const double muon_rest_mass{105.6583755}; // MeV

  // Create a vector of particles:
  // two electrons, four muons, one antielectron, one antimuon
  std::vector<particle> particles;

  particles.emplace_back("electron", electron_rest_mass, 1, 41.21);
  particles.emplace_back("electron", electron_rest_mass, 1, -2.01e8);
  particles.emplace_back("muon", muon_rest_mass, 1, 34324.12);
  particles.emplace_back("muon", muon_rest_mass, 1, -612.5421);
  particles.emplace_back("muon", muon_rest_mass, 1, 9.6233e3);
  particles.emplace_back("muon", muon_rest_mass, 1, 0.56);
  particles.emplace_back("electron", electron_rest_mass, -1, 1.74e7);
  particles.emplace_back("muon", muon_rest_mass, -1, 0.0);
  
  // Print out the data from all the particles
  print_all_particle_info(particles);

  // Create a vector of detectors:
  // a tracker, a calorimeter, a muon chamber
  std::vector<detector> detectors;

  detectors.emplace_back("tracker", false);
  detectors.emplace_back("calorimeter", false);
  detectors.emplace_back("muon chamber", false);

  // Pass the list of particles into each detector
  run_particles_through_detectors(detectors, particles);

  // Print a summary of how many particles were detected
  print_detector_results(detectors);

  return 0;
}
