// PHYS 30762 Programming in C++
// Implementing the header file for the 'detector' class
// Hamish Hare

#ifndef DETECTOR_H
#define DETECTOR_H

#include <string>
#include "particle.h"
using std::string;

class detector {
private:
  string detector_type{"tracker"};
  bool status{false}; // true <--> on, false <--> off
  size_t detection_count{0};
  size_t electron_detection_count{0};
  size_t muon_detection_count{0};
  size_t total_particle_count{0};

  // Function to get on/off message depending on status
  string status_message() const;

  // Function to check if the given particle can be detected
  // by this detector
  bool can_detect(const particle& particle) const;

  // Validation functions
  void validate_type(); // .. detector type
  void validate_count(const size_t& count); // .. counts

public:
  // Constructors
  // .. Default constructor
  detector() = default;
  // .. Parameterised constructor
  detector(string type, bool initial_status);
  // Destructor
  ~detector(){}

  // Getter functions
  string get_detector_type() const {return detector_type;}
  bool get_status() const {return status;}
  size_t get_detection_count() const {return detection_count;}
  size_t get_electron_detection_count() const {return electron_detection_count;}
  size_t get_muon_detection_count() const {return muon_detection_count;}
  size_t get_total_particle_count() const {return total_particle_count;}

  // Setter functions
  void set_detector_type(const string& type){detector_type = type; validate_type();}
  void turn_on(){status=true;}
  void turn_off(){status=false;}
  void set_detection_count(const size_t& new_count);
  void set_electron_detection_count(const size_t& new_count);
  void set_muon_detection_count(const size_t& new_count);
  void set_total_particle_count(const size_t& new_count);

  // Function to attempt to detect a particle
  bool detect_particle(const particle& particle);

  // Print the detector information
  void print_data() const;
};

#endif // DETECTOR_H
