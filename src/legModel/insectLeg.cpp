#include "../include/legModel/insectLeg.h"
#include "../include/Kinematic/kinematicLie.h"
#include <iostream>

using namespace controller;

/// A single instance of insect leg
InsectLeg::Ptr insectLeg;
KinematicLie::Ptr kinematicLie;

InsectLeg::InsectLeg(void) : Leg("Insect Leg", TYPE_INSECT) 
{

}

InsectLeg::~InsectLeg(void) 
{
	
}

///Compute torque in each joint for given the force applied in the foot
std::vector<float_type> InsectLeg::computLoad(Vec3& force)
{
	std::vector<float_type> result;

	return result;
}

/// Compute forward kinematic, default (-1) -- the last joint
Mat34 InsectLeg::forwardKinematic(std::vector<float_type> configuration, unsigned int linkNo)
{
	return kinematicLie->forwardKinematic(configuration, linkNo);
}

/// Compute inverse kinematic, default (-1) -- the last joint
std::vector<float_type> InsectLeg::inverseKinematic(Mat34 linkPose, unsigned int linkNo)
{
	return kinematicLie->inverseKinematic(linkPose, linkNo);
}

controller::Leg* controller::createInsectLeg(void) 
{
	insectLeg.reset(new InsectLeg());
	return insectLeg.get();
}

controller::Leg* controller::createInsectLeg(std::string filename) 
{
	insectLeg.reset(new InsectLeg(filename));
	return insectLeg.get();
}