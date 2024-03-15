// PHYS 30762 Programming in C++
// Implementing the cpp file for the 'detector' class
// Hamish Hare

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "detector.h"
using std::string;

// Function to convert strings to lowercase
static void to_lowercase(string& input_string)
{
  std::transform(input_string.begin(), input_string.end(), input_string.begin(),
                 [](unsigned char c){return std::tolower(c);});
}
// Function to get on/off message depending on status
string detector::status_message() const
{
  if(status) return "on"; else return "off";
}

// Function to check if the given particle can be detected
// by this detector
bool detector::can_detect(const particle& particle) const
{
  string particle_type = particle.get_type();
  // .. tracker can detect both electrons and muons
  if(detector_type=="tracker" &&
    (particle_type=="electron" || particle_type=="muon")) return true;
  // .. calorimeter can detect electrons
  else if(detector_type=="calorimeter" && particle_type=="electron") return true;
  // .. muon chamber can detect muons
  else if(detector_type=="muon chamber" && particle_type=="muon") return true;
  // .. otherwise undetected
  return false;
}

// Validation functions
// .. detector type
void detector::validate_type()
{
  // make detector_type lowercase
  to_lowercase(detector_type);
  // ensure its an acceptable input
  if(!(detector_type=="tracker" || detector_type=="calorimeter"
       || detector_type=="muon chamber"))
  {
    std::cout<<"Provided type "<<detector_type<<" is not 'tracker',"
    "'calorimeter' or 'muon chamber'";
    throw std::invalid_argument("Invalid detector type.");
  }
}
// .. counts
void detector::validate_count(const size_t& count)
{
  if(count<0)
  {
    std::cout<<"Provided count "<<count<<" is less than zero";
    throw std::invalid_argument("Invalid count provided.");
  }
}

// Parameterised constructor
detector::detector(string type, bool initial_status) : detector_type{type},
                              status{initial_status}, detection_count{0}, 
                              electron_detection_count{0}, muon_detection_count{0},
                              total_particle_count{0}
{
  // Validation
  // .. check that the detector type is valid
  validate_type();
}

// Setters
void detector::set_detection_count(const size_t& new_count)
{
  validate_count(new_count);
  detection_count = new_count;
  if(detection_count>total_particle_count)
  {
    std::cout<<"WARNING: Detection count set to a value larger than"
    " the total count. The total count has been set to this value."
    <<std::endl;
    total_particle_count = new_count;
  }
}

void detector::set_electron_detection_count(const size_t& new_count)
{
  validate_count(new_count);
  electron_detection_count = new_count;
  detection_count = new_count + muon_detection_count;
  if(detection_count>total_particle_count)
  {
    std::cout<<"WARNING: Changing the electron detection count led to"
    " a combined detection count larger than the total count. The total"
    " count has been set to the new combined detection count"<<std::endl;
    total_particle_count = detection_count;
  }
}

void detector::set_muon_detection_count(const size_t& new_count)
{
  validate_count(new_count);
  muon_detection_count = new_count;
  detection_count = new_count + electron_detection_count;
  if(detection_count>total_particle_count)
  {
    std::cout<<"WARNING: Changing the muon detection count led to a"
    " combined detection count larger than the total count. The total"
    " count has been set to the new combined detection count"<<std::endl;
    total_particle_count = detection_count;
  }
}

void detector::set_total_particle_count(const size_t& new_count)
{
  validate_count(new_count);
  total_particle_count = new_count;
}

bool detector::detect_particle(const particle& particle)
{
  // Increase total particle count
  total_particle_count++;
  // Check if the detector is on and is able to detect the particle
  if(status && can_detect(particle))
  {
    // .. announce the detected particle
    std::cout<<particle.get_name()<<" was detected"<<std::endl;
    // .. update counts
    detection_count++;
    if(particle.get_type()=="electron") electron_detection_count++;
    else if (particle.get_type()=="muon") muon_detection_count++;
    return true; // detected
  }
  return false; // undetected
}

void detector::print_data() const
{
  std::cout
  <<" -- Status: "<<status_message()<<std::endl
  <<" -- Detected particles: "<<detection_count<<std::endl
  <<"   (Electrons: "<<electron_detection_count
  <<", Muons: "<<muon_detection_count<<")"<<std::endl
  <<" -- Total particle count: "<<total_particle_count<<std::endl;
}
