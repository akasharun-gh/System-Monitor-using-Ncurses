#include "processor.h"
#include "linux_parser.h"

// Returns the aggregate CPU utilization
using namespace LinuxParser;

float Processor::Utilization() {
    std::vector<float> const &cpu_util = CpuUtilization();

    float Idle = cpu_util[kIdle_] + cpu_util[kIOwait_];
    float NonIdle = cpu_util[kUser_] + cpu_util[kNice_] + cpu_util[kSystem_] +
                    cpu_util[kIRQ_] + cpu_util[kSoftIRQ_] + cpu_util[kSteal_];

    float Total = Idle + NonIdle;

    float totald = Total - PrevTotal;
    float idled = Idle - PrevIdle;

    PrevIdle = Idle;
    PrevNonIdle = NonIdle;
    PrevTotal = Total; 

    return (totald- idled)/totald;
 }