#include "process.h"
#include "linux_parser.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;


Process::Process(int pid) : pid_(pid) {}

//  Returns this process's ID
int Process::Pid() { return pid_; }

//  Returns this process's CPU utilization
float Process::CpuUtilization() const {
  string key, value, line;
  float utime = 0.0;
  float stime = 0.0;
  float cutime = 0.0;
  float cstime = 0.0;
  float strtTime = 0.0;
  float sysUptime = (float)LinuxParser::UpTime();
  std::ifstream stream(LinuxParser::kProcDirectory + to_string(pid_) + LinuxParser::kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      std::replace(line.begin(), line.end(), '(', '_');
      std::replace(line.begin(), line.end(), ')', '_');
      std::replace(line.begin(), line.end(), '-', '_');
      std::istringstream linestream(line);
      std::istream_iterator<std::string> beg(linestream), end;
      std::vector<std::string> vec(beg, end);
      utime = std::stof(vec[13]);
      stime = std::stof(vec[14]);
      cutime = std::stof(vec[15]);
      cstime = std::stof(vec[16]);
      strtTime = std::stof(vec[21]);
    }
  }
  float total_time = utime + stime + cutime + cstime;
  float seconds = sysUptime - (strtTime / sysconf(_SC_CLK_TCK));
  float util = (total_time/sysconf(_SC_CLK_TCK))/seconds;
  return util;
}

//  Returns the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// Returns this process's memory utilization
// Note: Returned RAM value is in kB, so converting to MB as mentioned in the display
string Process::Ram() { 
  long ram_kb = std::stol(LinuxParser::Ram(pid_));
  long ram_mb = ram_kb/1024;
  return to_string(ram_mb); }

//  Returns the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

//  Returns the age of this process (in seconds)
long int Process::UpTime() const { return LinuxParser::UpTime(pid_); }

// Overloading the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const {
  // using '>' to sort in descending order
  return (this->CpuUtilization() > a.CpuUtilization());
  //return (this->UpTime() > a.UpTime()); -> sorting based on uptime
}